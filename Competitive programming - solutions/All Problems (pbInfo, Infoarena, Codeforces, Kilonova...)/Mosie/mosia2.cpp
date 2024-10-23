#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

ifstream fin("mosia.in");
ofstream fout("mosia.out");

struct Point
{
    double x, y, d;
};

const int NMAX = 1005;
int n;
double medX, medY;
double dp[2][NMAX];
Point p[NMAX];

// returneaza true daca unghiul pe care il face segemntul [media-x] cu Ox 
// e mai mic decat unghiul pe care il face segemntul [media-y] cu Ox 
bool Less(const Point &x, const Point &y)
{
    return atan2(x.y - medY, x.x - medX) < atan2(y.y - medY, y.x - medX);
}

double Dist(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    fin >> n;

    for (int i = 1; i <= n; ++i)
        fin >> p[i].x >> p[i].y >> p[i].d;

    for (int i = 1; i <= n; ++i)
    {
        medX += p[i].x;
        medY += p[i].y;
    }

    medX /= n;
    medY /= n;

    sort(p + 1, p + n + 1, Less);

    p[0] = p[n];
    p[n + 1] = p[1];

    for (int i = 1; i <= n; ++ i)
    {
        dp[0][i] = (Dist(p[i - 1], p[i + 1]) * p[i].d) / 2;
        dp[1][i] = (Dist(p[i - 1], p[i + 1]) * p[i].d) / 2;
    }

    dp[0][n] = dp[1][1] = 0;

    for (int i = 2; i <= n; ++ i)
    {
        dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + dp[0][i]);
        dp[1][i] = max(dp[1][i - 1], dp[1][i] + dp[1][i - 2]);
    }
    
    fout << fixed << setprecision(5) << max(dp[0][n], dp[1][n]);
}
