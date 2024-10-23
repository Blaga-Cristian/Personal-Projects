#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

using namespace std;
const string TASK("warb");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const ll Inf = 0x3f3f3f3f;
const int N = 1e5 + 9, M = 109;
const bool test_cases = false;

ll n, m, w[N], req[N], dp[N][M][2];
vvi G(N);

ll best[N], ind1[N], sbest[N], ind2[N], tbest[N];
///dp[x][y][tip] = suma maxima pentru care nodul x are culoarea y,
///daca tip == 0, radacina e diferita de y - 1;
///date tip == 1, radacina e egala cu y - 1;

vi vec;

int get_best(int x, int col)
{
    ll ret = -Inf;
    if(ind1[x] == col - 1)
    {
        if(ind2[x] == col + 1)ret = tbest[x];
        else ret = sbest[x];
    }
    else if(ind1[x] == col + 1)
    {
        if(ind2[x] == col - 1)ret = tbest[x];
        else ret = sbest[x];
    }
    else ret = best[x];

    if(col < m)ret = max(ret, dp[x][col + 1][1]);
    return ret;
}

void Dfs(int x, int p)
{
    if(G[x].size() == 1 && x != 1)
    {
        dp[x][1][0] = w[1];

        if(req[x] == 0)for(int i = 2; i <= m; ++i)dp[x][i][0] = w[i];
        else for(int i = 2; i <= m; ++i)dp[x][i][1] = w[i];


        best[x] = -Inf, ind1[x] = -1;
        for(int i = 1; i <= m; ++i)
            if(ind1[x] == -1 || best[x] < dp[x][i][0])
            {
                ind1[x] = i;
                best[x] = dp[x][i][0];
            }

        sbest[x] = -Inf, ind2[x] = -1;
        for(int i = 1; i <= m; ++i)
            if(i != ind1[x] && (ind2[x] == -1 || sbest[x] < dp[x][i][0]))
            {
                ind2[x] = i;
                sbest[x] = dp[x][i][0];
            }

        tbest[x] = -Inf;
        for(int i = 1; i <= m; ++i)
            if(i != ind1[x] && i != ind2[x] && tbest[x] < dp[x][i][0])
                tbest[x] = dp[x][i][0];

        return;
    }


    for(auto y : G[x])
        if(y != p)
            Dfs(y, x);

    vec.clear();
    for(auto y : G[x])
        if(y != p)
            vec.pb(y);

    dp[x][1][0] = w[1];
    for(auto i : vec)dp[x][1][0] += get_best(i, 1);

    for(int col = 2; col <= m; ++col)
    {
        sort(vec.begin(), vec.end(), [&](int a, int b){return get_best(a, col) - dp[a][col - 1][0] <
                                                            get_best(b, col) - dp[b][col - 1][0];});

        ll sum = 0;
        for(auto i : vec)sum += get_best(i, col);

        if(req[x] < G[x].size() || x == 1)
        {
//            if(x == 1)cout << sum << '\n';
            dp[x][col][0] = sum + w[col];
            for(int i = 0; i < req[x]; ++i)dp[x][col][0] -= get_best(vec[i], col) - dp[vec[i]][col - 1][0];
        }

        if(req[x] != 0)
        {
            dp[x][col][1] = sum + w[col];
            for(int i = 0; i < req[x] - 1; ++i)dp[x][col][1] -= get_best(vec[i], col) - dp[vec[i]][col - 1][0];
        }
    }

    best[x] = -Inf, ind1[x] = -1;
    for(int i = 1; i <= m; ++i)
        if(ind1[x] == -1 || best[x] < dp[x][i][0])
        {
            ind1[x] = i;
            best[x] = dp[x][i][0];
        }

    sbest[x] = -Inf, ind2[x] = -1;
    for(int i = 1; i <= m; ++i)
        if(i != ind1[x] && (ind2[x] == -1 || sbest[x] < dp[x][i][0]))
        {
            ind2[x] = i;
            sbest[x] = dp[x][i][0];
        }

    tbest[x] = -Inf;
    for(int i = 1; i <= m; ++i)
        if(i != ind1[x] && i != ind2[x] && tbest[x] < dp[x][i][0])
            tbest[x] = dp[x][i][0];
}

void solve()
{
    cin >> n >> m;
    FOR(i, 1, m)cin >> w[i];
    FOR(i, 1, n)cin >> req[i];

    for(int i = 0; i <= n + 1; ++i)
        for(int j = 0; j <= m + 1; ++j)
            dp[i][j][0] = dp[i][j][1] = -Inf;

    int u, v;
    FOR(i, 2, n)
    {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    Dfs(1, 0);

    ll ans = -Inf;
    FOR(i, 1, m)ans = max(ans, dp[1][i][0]);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
