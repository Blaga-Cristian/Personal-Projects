#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define VP vector<PI>
#define VVP vector<VP>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, n) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long
#define ull unsigned ll
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
const int N = 3e5 + 9;

int n, m;
VVP G(N);

struct muchie
{
    int a, b, w;
};
muchie muchii[N];

int low[N], lvl[N];
bool critical[N];
void Get_Bridges(int x = 1, int p = 0, int idx = 1)
{
    low[x] = lvl[x] = idx;

    for(auto aux : G[x])
    {
        int y = aux.F, i = aux.S;

        if(y == p)continue;

        if(!lvl[y])
        {
            Get_Bridges(y, x, idx + 1);

            low[x] = min(low[x], low[y]);

            if(low[y] > lvl[x])
                critical[i] = true;
        }
        else low[x] = min(low[x], lvl[y]);
    }
}


VVP edges(N); ///edges[x][i].F = nod, edges[x][i].S = indicele muchiei
bool viz1[N], viz2[N], counted[N];///e pentru muchii
int dep[N], t[N], t_m[N]; ///t_m[x] = ce indice a avut muchia cu care am ajuns in x
VP res;///res.F = nr de muchii, res.S = nr de muchi cu val 1
void Get_Edges(int x, int p = 0)
{
    viz1[x] = true;

    dep[x] = dep[p] + 1;

    for(auto [y, i] : G[x])
    {
        if(critical[i] || y == p)continue;

        if(!viz1[y])
        {
            t[y] = x;
            t_m[y] = i;
            Get_Edges(y, x);
        }
        else if(dep[y] < dep[x])edges[y].pb({x, i});
    }

    sort(edges[x].begin(), edges[x].end(), [](PI a, PI b){return dep[a.F] < dep[b.F];});
}
void Get_Cycles(int x)
{
    viz2[x] = true;

    //cout << "In " << x << " I found: \n";
    for(auto [y, i] : edges[x])
    {
        PI a {1, muchii[i].w};

        //cout << "{" << muchii[i].a << ' ' << muchii[i].b << "} ";

        for(; !counted[y]; counted[y] = true, y = t[y])
        {
            a.F ++;
            a.S += muchii[t_m[y]].w;

            //cout << "{" << muchii[t_m[y]].a << ' ' << muchii[t_m[y]].b << "} ";
        }
        //cout << '\n';

        res.pb(a);
    }
    //cout << "\n\n";

    for(auto [y, i] : G[x])
        if(!viz2[y] && !critical[i])
            Get_Cycles(y);
}
void Cycle_Decomp()
{
    FOR(i, 1, n)
        if(!viz1[i])
        {
            Get_Edges(i);

            counted[i] = true;
            Get_Cycles(i);
        }
}

int main()
{
    cin >> n >> m;

    int a, b, w;
    FOR(i, 1, m)
    {
        cin >> a >> b >> w;
        muchii[i] = {a, b, w};
        G[a].pb({b, i});
        G[b].pb({a, i});
    }

    Get_Bridges();

    int cnt = 0;
    FOR(i, 1, m)
        if(critical[i])
            cnt += muchii[i].w;

    Cycle_Decomp();

    int cnt0or1 = 0;///care adauga oricare
    for(auto i : res)
        if(i.S == i.F && i.S % 2 == 0)cnt ++;
        else if(i.S != i.F && i.S > 0)cnt0or1 ++;

    if(cnt % 2 == 1 || (cnt % 2 == 0 && cnt0or1 > 0))cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
