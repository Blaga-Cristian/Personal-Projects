#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long

using namespace std;
const int N = 309;

struct point
{
    double x, y;

    point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct line
{
    double a, b, c;
};

void points_to_line(point a, point b, line& l)
{
    l.a = a.y - b.y;
    l.b = b.x - a.x;
    l.c = - l.a * a.x - l.b * a.y;
}

double cross(point a, point b)
{
    return a.x * b.y - b.x * a.y;
}

void intersect(line n, line m, point& res)
{

}

int main()
{
    point a(0, 2), b(2, 4);
    line l;
    points_to_line(a, b, l);
    cout << l.a << ' ' << l.b << ' ' << l.c;
    return 0;
}
