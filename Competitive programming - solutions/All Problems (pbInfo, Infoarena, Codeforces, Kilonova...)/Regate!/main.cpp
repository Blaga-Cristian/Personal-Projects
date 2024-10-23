#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 2e5 + 9;

ll n, m, r[N], cc[N], ncc[N], counter, k, a, b, c, idx = 1;
vector<bool> muchii(N);
struct muchie
{
    ll y, c, i;
};
struct bridge
{
    ll x, y, c;
};
vector<bridge> bridges;
vector<vector<muchie>> G;
vector<bridge> aux;

ll low[N], lvl[N];
void Dfs(int x, int p)
{
    low[x] = lvl[x] = idx ++ ;

    for(auto& aux : G[x])
    {
        //int y = aux.y, c = aux.c, i = aux.i;

        if(aux.y == p)continue;

        if(lvl[aux.y])low[x] = min(low[x], low[aux.y]);
        else
        {
            Dfs(aux.y, x);
            low[x] = min(low[x], lvl[aux.y]);

            if(low[aux.y] > lvl[x])
            {
                muchii[aux.i] = true;
                bridges.push_back({x, aux.y, aux.c});
            }
        }
    }
}
void Dfs1(int x, int legatura, int comp)
{
    counter++;
    cc[x] = comp;
    aux.push_back({x + n, legatura, r[x]});

    for(auto& aux : G[x])
    {
        //int y = aux.y, i = aux.i;

        if(!muchii[aux.i] && !cc[aux.y])
            Dfs1(aux.y, legatura, comp);
    }
}

struct DSU
{
    ll t[2 * N], w[2 * N];
    ll marss[2 * N];

    void init()
    {
        for(int i = 1; i <= n; ++i)
            t[i] = w[i] = marss[i] = t[i + n] = w[i + n] = marss[i + n] = 0;
    }

    ll find(ll a)
    {
        while(t[a])a = t[a];
        return a;
    }

    void unionp(ll x, ll y, ll c)
    {
        if(w[x] > w[y])swap(x, y);

        marss[y] += 1LL * w[x] * c;
        marss[x] += 1LL * w[y] * c;
        marss[x] -= marss[y];

        t[x] = y;
        w[y] += w[x];
        w[x] = 0;
    }

    ll cost(ll x)
    {
        ll ret = 0;

        while(x)
        {
            ret += marss[x];
            x = t[x];
        }

        return ret;
    }

    void update(ll x, ll size)
    {
        w[x] = size;
    }
}dsu;

int main()
{
    cin >> n >> m;
    dsu.init();
    G = vector<vector<muchie>>(n + 1);
    for(int i = 1; i <= n; ++i)cin >> r[i];
    for(int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c, i});
        G[b].push_back({a, c, i});
    }

    Dfs(1, 0);

    for(auto b : bridges)
    {
        //int x = b.x, y = b.y, c = b.c;
        if(!cc[b.x])
        {
            counter = 0;
            ++k;
            Dfs1(b.x, b.x, k);

            ncc[k] = b.x;
            dsu.update(b.x, counter);
        }
        if(!cc[b.y])
        {
            counter = 0;
            ++k;
            Dfs1(b.y, b.y, k);

            ncc[k] = b.y;
            dsu.update(b.y, counter);
        }

        aux.push_back({ncc[cc[b.x]], ncc[cc[b.y]], b.c});
    }

    sort(aux.begin(), aux.end(), [](bridge const& a, bridge const& b){return a.c > b.c;});

    for(auto i : aux)
    {
        ll x = dsu.find(i.x);
        ll y = dsu.find(i.y);

        dsu.unionp(x, y, i.c);
    }


    for(int i = 1; i <= n; ++i)
        cout << dsu.cost(i + n) - r[i] << '\n';
    return 0;
}
