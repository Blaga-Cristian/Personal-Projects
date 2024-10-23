#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define pb push_back
#define VL vector<ll>
#define VI vector<int>
#define VVI vector<VI>

using namespace std;
const bool testcase = true;
const int N = 2e5 + 9;

ll n, m, h[N], a[N], t[N];
ll v[N], b[N];

bool ok(int x)
{
    FOR(i, 1, n)b[i] = a[v[i]] * x + h[v[i]];

    FOR(i, 1, n - 1)
        if(b[i] >= b[i + 1] && h[v[i]] >= h[v[i + 1]])
            return false;

    return true;
}

void solve()
{
    cin >> n;

    FOR(i, 1, n)cin >> h[i];
    FOR(i, 1, n)cin >> a[i];
    FOR(i, 1, n)cin >> t[i];

    FOR(i, 1, n)v[i] = i;
    sort(v + 1, v + n + 1, [](int a, int b){return t[a] > t[b];});

    ll st = 0, dr = 1e9 + 7, m, poz;
    while(st <= dr)
    {
        m = (st + dr) >> 1;
        if(ok(m))
        {
            poz = m;
            dr = m - 1;
        }
        else st = m + 1;
    }

    FOR(i, 1, n)b[i] = a[v[i]] * poz + h[v[i]];
    bool solvable = true;
    FOR(i, 1, n - 1)
        if(b[i] >= b[i + 1])
            solvable = false;

    if(solvable)cout << poz << '\n';
    else cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t = 1;
    if(testcase)cin >> t;
    while(t --)
        solve();
    return 0;
}
