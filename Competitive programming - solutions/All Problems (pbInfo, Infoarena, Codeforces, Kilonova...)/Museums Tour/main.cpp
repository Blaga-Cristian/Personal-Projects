#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VVP vector<VP>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll

using namespace std;
const bool has_multiple_testcases = false;
const int N = 1e5 + 9, D = 51;

int n, m, d, w[N * D], dp[N * D], in[N * D];
bool viz[N * D];
VVI G;
VVI GF;
string s;
bool open[N][D];
unordered_set<int> st;
VI sir;


int lvl[N][D], low[N][D], idx, comp[N][D], cntctc;
bool instk[N][D];
stack<PI> stk;
VVP ctc;
VP c;
void Dfs(PI x)
{
    stk.push(x);
    instk[x.F][x.S] = true;
    lvl[x.F][x.S] = low[x.F][x.S] = ++idx;

    for(auto f : G[x.F])
    {
        int s = (x.S + 1) % d;
        if(lvl[f][s] == 0)
        {
            Dfs({f, s});
            low[x.F][x.S] = min(low[x.F][x.S], low[f][s]);
        }
        else if(instk[f][s])low[x.F][x.S] = min(low[x.F][x.S], lvl[f][s]);
    }

    if(lvl[x.F][x.S] == low[x.F][x.S])
    {
        c.clear();
        ++ cntctc;
        while(true)
        {
            PI a = stk.top();
            stk.pop();
            instk[a.F][a.S] = false;

            comp[a.F][a.S] = cntctc;
            c.pb({a.F, a.S});

            if(a == x)break;
        }
        ctc.pb(c);
    }
}
void TopologicalSort(int x)
{
    viz[x] = true;

    for(auto y : GF[x])
        if(!viz[y])
            TopologicalSort(y);

    sir.pb(x);
}
void Solve_Graph()
{
    FOR(i, 1, n)
        FOR(j, 0, d - 1)
            if(lvl[i][j] == 0)
                Dfs({i, j});

    FOR(i, 0, ctc.size() - 1)
    {
        st.clear();
        for(auto j : ctc[i])
            if(open[j.F][j.S])
                st.insert(j.F);
        w[i + 1] = st.size();
    }

    GF = VVI(cntctc + 1);
    FOR(i, 1, n)
        for(auto j : G[i])
            FOR(k, 0, d - 1)
            {
                int p = (k + 1) % d;
                if(comp[i][k] != comp[j][p])
                {
                    GF[comp[i][k]].pb(comp[j][p]);
                    in[comp[j][p]] ++;
                }
            }

    FOR(i, 1, cntctc)
        if(in[i] == 0)
            TopologicalSort(i);

    FORR(i, sir.size() - 1, 0)
    {
        int x = sir[i];
        dp[x] = w[x];
        for(auto y : GF[x])
            dp[x] = max(dp[x], w[x] + dp[y]);
    }
}

void solve_testcase()
{
    cin >> n >> m >> d;
    G = VVI(n + 1);

    int u, v;
    while(m --)
    {
        cin >> u >> v;
        G[u].pb(v);
    }

    FOR(i, 1, n)
    {
        cin >> s;
        FOR(j, 0, d - 1)
            open[i][j] = s[j] - '0';
    }

    Solve_Graph();

    cout << dp[comp[1][0]];
}

int main()
{
    FAST_IN_OUT
    int t = 1;
    if(has_multiple_testcases) cin >> t;
    while(t --)
        solve_testcase();
    return 0;
}
