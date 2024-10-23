#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define int long long
using namespace std;
const string TASK("keidei");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
const int N = 10009, Al = 30, Inf = 0x3f3f3f3f;
const bool test_cases = false;

int c, n, k, w[N], dp[N], dep[N];
vi ans;
vvi G(N);

void add(int* kp, int val)
{
    for(int i = n - val; i >= 0; --i)
        if(kp[i])
            kp[i + val] += kp[i];
}
void rem(int* kp, int val)
{
    for(int i = 0; i <= n - val; ++i)
        if(kp[i])
            kp[i + val] -= kp[i];
}

void Precalc(int x = 1, int p = 0)
{
    w[x] = 1;

    for(auto y : G[x])
        if(y != p)
        {
            Precalc(y, x);
            w[x] += w[y];
        }
}

void _Dfs(int x = 1, int p = 0)
{
    if(dp[k])ans.pb(x);

    for(auto y : G[x])
        if(y != p)
            add(dp, w[y]);

    for(auto y : G[x])
    {
        if(y == p)continue;

        rem(dp, w[y]);

        FORR(i, n, 0)dp[i] = dp[i - 1];
        _Dfs(y, x);
        FOR(i, 0, n)dp[i] = dp[i + 1];

        add(dp, w[y]);
    }

    for(auto y : G[x])
        if(y != p)
            rem(dp, w[y]);
}

void Solve_Dfs()
{
    Precalc();
    dp[1] = 1;
    _Dfs();
}

void _Precalc(int x = 1, int y = 0)
{
    if()
}

void Solve_Bfs()
{
    _Precalc();
}

void solve()
{
    cin >> c >> n >> k;

    int x, y;
    FOR(i, 2, n)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    if(c == 1)Solve_Dfs();
    else Solve_Bfs();

    sort(ans.begin(), ans.end());
    for(auto i : ans)cout << i << ' ';
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
