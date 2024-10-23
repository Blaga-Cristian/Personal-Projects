#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back
#define ll long long
//#define int long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
using namespace std;
const string TASK("treegcd");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 109, M = 10009, Mod = 1e9 + 7;

int n, m, dp[N][M], mob[M], aux[M];
vvi G(N);

vvi p(M);
void Precalc()
{
    for(int i = 0; i < M; ++i)mob[i] = 1;

    for(int i = 2; i < M; ++i)
        if(!p[i].size())
            for(int j = i; j < M; j += i)
            {
                p[j].pb(i);
                mob[j] *= -1;
                if((j / i) % i == 0)mob[j] = 0;
            }
}

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * y) % Mod;
}

///MORBIUS
void Dfs(int x = 1, int parent = 0)
{
    for(auto y : G[x])
    {
        if(y == parent)continue;

        Dfs(y, x);

        for(int v = 1; v <= m; ++v)aux[v] = 0;
        for(int v = 1; v <= m; ++v)
        {
            for(int k = v; k <= m; k += v)
                aux[k] = add(aux[k], dp[y][v] * mob[v]);

            dp[x][v] = mul(dp[x][v], add(dp[y][1], - aux[v]));
        }
    }

    if(x == 1)return;

    for(int i = 1; i <= m; ++i)
        for(int j = 2 * i; j <= m; j += i)
            dp[x][i] = add(dp[x][i], dp[x][j]);
}

int main()
{
    Precalc();
    cin >> n >> m;

    int x, y;
    FOR(i, 2, n)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    FOR(i, 1, n)
        FOR(j, 1, m)
            dp[i][j] = 1;

    Dfs();

    int ans = 0;
    FOR(i, 2, m)ans = add(ans, dp[1][i]);
    cout << ans << '\n';
    return 0;
}
