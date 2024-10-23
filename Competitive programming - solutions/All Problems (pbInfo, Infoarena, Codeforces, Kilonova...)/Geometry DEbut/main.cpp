#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VVP vector<VP>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORI(i, a, b) for(int i = a; i >= b; --i)
#define ALL(v) v.begin(), v.end()
#define X first
#define Y second
using namespace std;
ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");
const int N = 120009;

typedef pair<double, double> Point;

int n;

Point stk[N];int head;

Point v[N];

double cross_product(Point const& A, Point const& B, Point const& C)
{
    return (B.X - A.X) * (C.Y - A.Y) - (B.Y - A.Y) * (C.X - A.X);
}

void sort_points()
{
    int idx = 1;

    for(int i = 2; i <= n; ++i)
        if(v[i] < v[idx])
            idx = i;

    swap(v[1], v[idx]);
    sort(v + 2, v + n + 1, [](Point const& a, Point const& b){return cross_product(v[1], a, b) < 0;});
}
void convex_hull()
{
    for(int i = 1; i <= n; ++i)
    {
        while(head >= 2 && cross_product(stk[head - 1], stk[head], v[i]) > 0)
            head--;
        stk[++head] = v[i];
    }
}

int main()
{
    fin >> n;
    FOR(i, 1, n)
        fin >> v[i].X >> v[i].Y;

    sort_points();
    convex_hull();

    fout << fixed;
    fout << head << '\n';
    FORI(i, head, 1)
        fout << setprecision(9) << stk[i].X << ' ' << stk[i].Y << '\n';
    return 0;
}
