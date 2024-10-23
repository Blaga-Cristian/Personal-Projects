#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define VPI vector<PI>
#define VVPI vector<VPI>
#define REP(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;
const int N = 300009;

int n, m, a, b, comp[N], cnt;
PI muchii[N];
VVPI G;
VVI GF;
bitset<N> crit, viz;

int lvl[N], low[N], idx;
void FindCrit(int x, int p = 0)
{
    lvl[x] = low[x] = ++idx;

    for(auto aux : G[x]){
        int y = aux.F, i = aux.S;

        if(y == p)continue;

        if(!lvl[y]){
            FindCrit(y, x);

            low[x] = min(low[x], low[y]);
            if(low[y] > lvl[x])
                crit[i] = true;
        }
        else low[x] = min(low[x], lvl[y]);
    }
}
void Dfs(int x, int nr_comp)
{
    comp[x] = nr_comp;

    for(auto aux : G[x])
    {
        int y = aux.F, i = aux.S;

        if(crit[i] || comp[y] != 0)continue;

        Dfs(y, nr_comp);
    }
}

int path[N], spath[N];
void DPDfs(int x)
{
    viz[x] = true;

    for(auto y : GF[x])
        if(!viz[y]){
            DPDfs(y);

            if(path[x] < path[y] + 1)
            {
                spath[x] = path[x];
                path[x] = path[y] + 1;
            }
            else if(spath[x] < path[y] + 1)
                spath[x] = path[y] + 1;
        }
}

int main()
{
    cin >> n >> m;
    G = VVPI(n + 1);

    for(int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        muchii[i] = {a, b};
    }

    FindCrit(1);

    for(int i = 1; i <= m; ++i)
        if(crit[i]){
            if(!comp[muchii[i].F])Dfs(muchii[i].F, ++cnt);
            if(!comp[muchii[i].S])Dfs(muchii[i].S, ++cnt);
        }

    GF = VVI(cnt + 1);
    for(int i = 1; i <= m; ++i)
        if(comp[muchii[i].F] != comp[muchii[i].S])
        {
            GF[comp[muchii[i].F]].push_back(comp[muchii[i].S]);
            GF[comp[muchii[i].S]].push_back(comp[muchii[i].F]);
        }


    DPDfs(1);
    int ans = 0;
    for(int i = 1; i <= cnt; ++i)
        ans = max(ans, path[i] + spath[i]);

    cout << ans;
    return 0;
}
