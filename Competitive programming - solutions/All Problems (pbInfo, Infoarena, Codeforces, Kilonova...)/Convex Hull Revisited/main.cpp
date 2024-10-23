#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
using namespace std;
const string TASK("infasuratoare");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 2e5 + 9;

int n;

struct point
{
    double x, y;

    bool operator < (point const& oth)
    {
        return y == oth.y ? x > oth.x : y < oth.y;
    }
};

point v[N], stk[N];
int sz;

double cross_product(point a, point b, point c)///crospriod(ab, ac)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main()
{
    cin >> n;
    FOR(i, 1, n)cin >> v[i].x >> v[i].y;

    int pos = 1;
    FOR(i, 2, n)
        if(v[i] < v[pos])
            pos = i;
    swap(v[1], v[pos]);

    sort(v + 2, v + n + 1, [](point a, point b){return cross_product(v[1], a, b) < 0;});

    stk[++sz] = v[1];
    FOR(i, 2, n)
    {
        while(sz > 1 && cross_product(stk[sz - 1], stk[sz], v[i]) > 0)-- sz;
        stk[++sz] = v[i];
    }

    cout << sz << '\n';
    cout << fixed << setprecision(6);
    FORR(i, sz, 1)cout << stk[i].x << ' ' << stk[i].y << '\n';
    return 0;
}
