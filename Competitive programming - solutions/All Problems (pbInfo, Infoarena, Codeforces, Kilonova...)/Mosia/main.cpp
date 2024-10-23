#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define double long double
using namespace std;
const string TASK("mosia");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
const int N = 1009;

int n;
double dp[N];
double dx, dy;

struct pct
{
    double x, y, t;
};
pct v[N];

double dot(pct a, pct b, pct c)///ab->, ac->
{
    return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}

double cross(pct a, pct b, pct c)///ab->, ac->
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

double aria(pct a, pct b, pct c)
{
    return abs(cross(a, b, c));
}

double dist(pct a, pct b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int next(int i)
{
    if(i < n)return i + 1;
    return 1;
}
int prev(int i)
{
    if(i > 1)return i - 1;
    return n;
}

double get_cst(int i)
{
    int prv = prev(i), nxt = next(i);
    return v[i].t * dist(v[prv], v[nxt]) / 2.0;
}

int cadran(pct a)
{
    if(a.x >= 0 && a.y >= 0)
        return 1;
    if(a.x < 0 && a.y >= 0)
        return 2;
    if(a.x < 0 && a.y < 0)
        return 3;
    return 4;
}

bool cmp(pct a, pct b)///sortare radiala, in sens trig
{
    int ca = cadran(a), cb = cadran(b);
    if(ca != cb)return ca < cb;
    else if(cross({0, 0, 0}, a, b) != 0)
        return cross({0, 0, 0}, a, b) > 0;
    return dist({0, 0, 0}, a) < dist({0, 0, 0}, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    FOR(i, 1, n)cin >> v[i].x >> v[i].y >> v[i].t;

    FOR(i, 1, n)dx += v[i].x, dy += v[i].y;
    dx /= n, dy /= n;
    FOR(i, 1, n)v[i].x -= dx, v[i].y -= dy;

    sort(v + 1, v + n + 1, cmp);
    ///sorteaza pana cand cmp este valabil peste tot


    double ans = 0;

    ///nu am mutat parul 1
    dp[1] = dp[2] = 0;
    FOR(i, 3, n)
        dp[i] = max(dp[i - 1], dp[i - 2] + get_cst(i - 1));
    ans = max(ans, max(dp[n], dp[n - 1] + get_cst(n)));

    ///am mutat parul 1
    FOR(i, 1, n)dp[i] = 0;
    dp[2] = dp[3] = get_cst(1);
    FOR(i, 4, n)
        dp[i] = max(dp[i - 1], dp[i - 2] + get_cst(i - 1));
    ans = max(ans, dp[n]);

    cout << fixed << setprecision(4);
    cout << ans << '\n';
    return 0;
}
