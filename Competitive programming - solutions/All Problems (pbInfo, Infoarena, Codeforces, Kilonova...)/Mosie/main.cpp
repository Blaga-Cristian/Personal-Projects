#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>>
using namespace std;

ifstream fin("MOSIA9.IN");
ofstream fout("mosia.out");

const int N = 500;
int n;
double ds[N];    // ds[i] - variatia suprafetei daca-l misc parul p[i] cu distanta p[i].d, perpendicular
double d[2][N];

struct Point {
    double x, y, d;
    bool operator < (Point const& p) const
    {
		return y < p.y || (y == p.y && x < p.x);
	}
};

Point p[N];
Point stk[N];

void ReadPoints();
double Dist(int, int);
void ConvexHull();
void Dynamic();

int main()
{
    ReadPoints();
    ConvexHull();    // pt det ordinii corecte de infasurare a nodurilor(imprejmuire a parilor)
    Dynamic();
    return 0;
}

void ReadPoints()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> p[i].x >> p[i].y >> p[i].d;

}

inline double CrossProduct(const Point& p1, const Point& p2, const Point& p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

void SortPoints()
{
    int pos = 1;
    for (int i = 2; i <= n; ++i)
        if (p[i] < p[pos])
            pos = i;
    swap(p[1], p[pos]);

    sort(p + 2, p + n + 1, [](const Point& p1, const Point& p2) {
		return CrossProduct(p[1], p1, p2) >  0;
	});
}

void ConvexHull()
{
    SortPoints();

    stk[1] = p[1];
    stk[2] = p[2];
    int top = 2;
    for (int i = 3; i <= n; ++i)
    {
        while (top >= 2 && CrossProduct(stk[top - 1], stk[top], p[i]) < 0)
            --top;
        stk[++top] = p[i];
    }
}

double Dist(int i, int j)
{
    return sqrt(double((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y)));
}

void Dynamic()
{

    p[0] = p[n];
    p[n + 1] = p[1];

	// variatia suprafetei daca-l misc parul p[i]
    for (int i = 1; i <= n; i++)
        ds[i] = (p[i].d  *  Dist(i - 1, i + 1)) / 2;

    d[0][1] = 0;                              // daca nu mutam primul par
    for (int i = 2; i <= n; i++)
    {
        if (d[0][i - 1] < d[0][i - 2] + ds[i])    // mutam parul i
            d[0][i] = d[0][i - 2] + ds[i];
        else                                  // nu mutam parul i
            d[0][i] = d[0][i - 1];
    }

    d[1][1] = ds[1];                          // mutam primul par
    for (int i = 2; i < n; i++)
    {
        if (d[1][i - 1] < d[1][i - 2] + ds[i])    //mutam parul i
            d[1][i] = d[1][i - 2] + ds[i];
        else                                //nu mutam parul i
            d[1][i] = d[1][i - 1];
    }

    d[1][n] = d[1][n - 1];                      //ultimul par nu mai poate fi mutat pentru ca l-am mutat pe primul


    if (d[1][n] >= d[0][n])
		fout << fixed << setprecision(4) << d[1][n];
    else
		fout << fixed << setprecision(4) << d[0][n];

}

