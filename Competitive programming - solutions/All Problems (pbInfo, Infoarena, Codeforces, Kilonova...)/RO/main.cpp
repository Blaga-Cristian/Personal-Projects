#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VB vector<bool>
#define VVP vector<VP>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll

using namespace std;
const int N = 2011, M = 10009, Inf = 0x3f3f3f3f;

int n, m, s[N], cntbc;

int dp[2][N]; ///dp[0][i] = costul minim ca subarborele sa respecte reguilile si i sa nu fie capiatala
              ///dp[1][i] = - / - i sa fie capitala

VVP G(N), GF(N);
VVI cbc(N);
int comp[N], poz[N];
struct muchie{int u, v;}muchii[M];
VB critical(M);

int low[N], lvl[N];
stack<PI> stk;
void Get_Crit(int x = 1, int p = 0, int idx = 1)
{
    lvl[x] = low[x] = idx;

    for(auto [y, i] : G[x])
    {
        if(y == p)continue;

        if(!lvl[y])
        {
            stk.push({x, y});

            Get_Crit(y, x, idx + 1);

            low[x] = min(low[x], low[y]);

            if(lvl[x] < low[y])
                critical[i] = true;

        }
        else low[x] = min(low[x], low[y]);
    }
}

void Mark_Comp(int x, int nr)
{
    comp[x] = nr;
    poz[x] = cbc[nr].size();
    cbc[nr].pb(x);

    for(auto [y, i] : G[x])
        if(!comp[y] && !critical[i])
            Mark_Comp(y, nr);
}
void Build_Tree()
{
    FOR(i, 1, m)
    {
        if(!critical[i])continue;

        if(!comp[muchii[i].u])
            Mark_Comp(muchii[i].u, ++cntbc);
        if(!comp[muchii[i].v])
            Mark_Comp(muchii[i].v, ++cntbc);

        GF[comp[muchii[i].u]].pb({comp[muchii[i].v], i});
        GF[comp[muchii[i].v]].pb({comp[muchii[i].u], i});
    }
}

void Solve_BCC(int component, int parent, int central_node)
{
    int sz = cbc[component].size();

    for(int k = 0; k < (1 << sz); ++k)
    {
        bool solvable = true;
        for(int i = 0; i < sz; ++ i)
            if(k & (1 << i) == 0)
            {
                int x = cbc[component][i];
                for(auto [y, aux] : G[x])
                    if(comp[x] == comp[y] && (k & (1 << poz[y])) == 0)
                        solvable = false;
            }
        if(!solvable)continue;

        for(int i = 0; i < sz; ++ i)
            if(k & (1 << i) == 1)
                cout << cbc[component][i] << ' ';
        cout << '\n';

        ///Calculeaza suma
        int sum = 0;
        for(int i = 0; i < sz; ++i)
        {
            int x = cbc[component][i];

            if((k & (1 << i)) == 0)
            {
                for(auto [y, aux] : G[x])
                    if(comp[y] != comp[x] && comp[y] != parent)
                        sum += dp[1][comp[y]];
            }
            else
            {
                sum += s[x];
                for(auto [y, aux] : G[x])
                    if(comp[y] != comp[x] && comp[y] != parent)
                        sum += min(dp[0][comp[y]], dp[1][comp[y]]);
            }
        }

        if(k & (1 << poz[central_node]) == 1)
            dp[1][component] = min(dp[1][component], sum);
        else
            dp[0][component] = min(dp[0][component], sum);
    }
}
void Do_Dp(int x = 1, int p = 0, int central_node = cbc[1][0])
{
    for(auto [y, i] : GF[x])
        if(y != p)
        {
            if(comp[muchii[i].u] == comp[x])
                Do_Dp(y, x, muchii[i].v);
            else
                Do_Dp(y, x, muchii[i].u);
        }

    Solve_BCC(x, p, central_node);
}

int main()
{
    cin >> n >> m;

    FOR(i, 1, n)cin >> s[i];

    int u, v;
    FOR(i, 1, m)
    {
        cin >> u >> v;
        G[u].pb({v, i});
        G[v].pb({u, i});
        muchii[i] = {u, v};
    }

    Get_Crit();
    Build_Tree();

    FOR(i, 1, n)dp[0][i] = dp[1][i] = Inf;
    Do_Dp();

    cout << dp[1][2];
    return 0;
}
