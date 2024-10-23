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
/// This IS the dp solution

using namespace std;
//ifstream fin("drumuri.in");
//ofstream fout("drumuri.out");
const int N = 150009;

int n, m, in[N], out[N], sir[N], sz;
VVI G, GI, GF, GIF;

int low[N], lvl[N], comp[N], idx, cntctc;
bool instk[N];
stack<int> stk;
VVI ctc;
VI c;
void Dfs(int x)
{
    lvl[x] = low[x] = ++idx;
    stk.push(x);
    instk[x] = true;

    for(auto y : G[x])
        if(lvl[y] == 0)
        {
            Dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y])low[x] = min(low[x], low[y]);

    if(lvl[x] == low[x])
    {
        c.clear();
        cntctc ++;
        while(true)
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;

            comp[a] = cntctc;
            c.pb(a);
            if(a == x)break;
        }
        ctc.pb(c);
    }
}
void Tarjan()
{
    FOR(i, 1, n)
        if(lvl[i] == 0)
            Dfs(i);
}
void RebuildGraph()
{
    GF = VVI(cntctc + 1);
    FOR(i, 1, n)
        for(auto j : G[i])
            if(comp[i] != comp[j])
            {
                GF[comp[i]].pb(comp[j]);
                in[comp[j]] ++;
                out[comp[i]] ++;
            }

    GIF = VVI(cntctc + 1);
    FOR(i, 1, n)
        for(auto j : GI[i])
            if(comp[i] != comp[j])
                GIF[comp[i]].pb(comp[j]);
}

void SortTop(int x, VVI& graph, VB& viz)
{
    viz[x] = true;
    for(auto y : GF[x])
        if(!viz[y])
            SortTop(y, graph, viz);

    ++ sz;
    sir[cntctc - sz + 1] = x;
}
void Topological_sort(int* deg, VVI& graph)
{
    VB viz(cntctc + 1);
    FOR(i, 1, cntctc)
        if(deg[i] == 0)
            SortTop(i, graph, viz);
}

int main()
{
    cin >> n >> m;

    G = GI = VVI(n + 1);

    int a, b;
    FOR(i, 1, m)
    {
        cin >> a >> b;
        G[a].pb(b);
        GI[b].pb(a);
    }

    Tarjan();
    RebuildGraph();

    VI sum(cntctc + 1);

    Topological_sort(in, GF);
    FOR(i, 1, cntctc)
        sum[sir[i]] += i;
    Topological_sort(out, GIF);
    FORR(i, cntctc, 1)
        sum[sir[i]] += (cntctc - i + 1);


    VI ans;
    FOR(i, 1, cntctc)
        if(sum[i] == cntctc + 1)
            for(auto j : ctc[i - 1])
                ans.pb(j);
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(auto i : ans)cout << i << ' ';
    return 0;
}
