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
/// This is not the dp solution

using namespace std;
ifstream fin("drumuri.in");
ofstream fout("drumuri.out");
const int N = 150009;

int n, m, in[N], out[N];
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


void Get_D(VVI& graph, VI& d, VB& viz, int x)
{
    viz[x] = true;
    for(auto y : graph[x])
    {
        if(!viz[y])Get_D(graph, d, viz, y);
        d[x] = max(d[x], 1 + d[y]);
    }
}
void Solve(int* deg, VVI& graph, bool* arr)///d is longest chain that starts from x
{
    priority_queue<PI> q;
    VB viz(cntctc + 1);
    VI d(cntctc + 1);
    FOR(i, 1, cntctc)
        if(deg[i] == 0)
        {
            Get_D(graph, d, viz, i);
            q.push({d[i], i});
        }

    while(!q.empty())
    {
        int dist = q.top().F, nod = q.top().S;

        if(q.size() == 1)arr[nod] = true;

        while(!q.empty() && q.top().F == dist)
        {
            int x = q.top().S;
            q.pop();

            for(auto y : graph[x])
            {
                deg[y] --;
                if(deg[y] == 0)
                    q.push({d[y], y});
            }
        }
    }
}

bool reachable[N]; /// true if can be reached by all nodes
bool canreach[N]; /// true if can reach all nodes


int main()
{
    fin >> n >> m;
    G = GI = VVI(n + 1);

    int a, b;
    FOR(i, 1, m)
    {
        fin >> a >> b;
        G[a].pb(b);
        GI[b].pb(a);
    }

    Tarjan(); /// Merge!

    RebuildGraph(); /// Merge!



    Solve(in, GF, reachable);
    Solve(out, GIF, canreach);

    VI ans;
    FOR(i, 1, cntctc)
        if(reachable[i] && canreach[i])
            for(auto y : ctc[i - 1])
                ans.pb(y);

    sort(ans.begin(), ans.end());
    fout << ans.size() << '\n';
    for(auto i : ans)fout << i << ' ';
    return 0;
}
