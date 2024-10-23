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
const bool has_multiple_testcases = false;
const int N = 5e4 + 9;

int n, m, q, sir[N], in[N], out[N], sz;
VVI G(N), GF(N), GIF(N);
VB viz(N);
bitset<N> bs[N];

int low[N], lvl[N], idx, comp[N], cnt;
VB instk(N);
stack<int> stk;
void Dfs(int x)
{
    lvl[x] = low[x] = ++idx;
    stk.push(x);
    instk[x] = true;

    for(auto y : G[x])
        if(!lvl[y])
        {
            Dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y])low[x] = min(low[x], lvl[y]);

    if(low[x] == lvl[x])
    {
        ++cnt;
        while(true)
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;

            comp[a] = cnt;

            if(a == x)break;
        }
    }
}
void Tarjan()
{
    FOR(i, 1, n)
        if(!lvl[i])
            Dfs(i);
}
void RebuildGraph()
{
    FOR(i, 1, n)
    {
        for(auto j : G[i])
            if(comp[i] != comp[j])
            {
                GF[comp[i]].pb(comp[j]);
                GIF[comp[j]].pb(comp[i]);
                in[comp[j]]++;
                out[comp[i]]++;
            }
    }
    FOR(i, 1, cnt)
        bs[i].set(i);
}
void ST(int x)
{
    viz[x] = true;
    for(auto y : GIF[x])
        if(!viz[y])
            ST(y);

    ++ sz;
    sir[cnt - sz + 1] = x;
}
void SortITop()
{
    FOR(i, 1, n)
        if(!out[i])
            ST(i);
}

void solve_testcase()
{
    cin >> n >> m >> q;

    int a, b;
    FOR(i, 1, m)
    {
        cin >> a >> b;
        G[a].pb(b);
    }

    Tarjan();
    RebuildGraph();
    SortITop();

    FOR(i, 1, n)
    {
        int x = sir[i];
        for(auto y : GIF[x])
            bs[y] |= bs[x];
    }

    FOR(i, 1, q)
    {
        cin >> a >> b;
        if(bs[comp[a]][comp[b]])cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_multiple_testcases)cin >> t;
    while(t --)
        solve_testcase();
    return 0;
}
