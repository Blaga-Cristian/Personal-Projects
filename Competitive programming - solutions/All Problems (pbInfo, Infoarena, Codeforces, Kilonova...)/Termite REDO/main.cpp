#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
//#define int long long
#define ll long long

using namespace std;
const string TASK("termite");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 3e5 + 9, Inf = 0x3f3f3f3f;

int n, m, k, q, in[N], d[N];
vvpi G(N), T(N);

struct edge
{
    int x, y, c;
};
vector<edge> edges;

int dsu[N], sz[N];
int find(int x){return (dsu[x] == 0) ? x : dsu[x] = find(dsu[x]);}
void unite(int x, int y, int c)
{
    x = find(x), y = find(y);

    if(x == y)return;
    if(sz[x] > sz[y])swap(x, y);

    dsu[x] = y;
    sz[y] += sz[x] + 1;

    cout << x << ' ' << y << ' ' << c << '\n';

    T[x].pb({y, c}), T[y].pb({x, c});
}

int dep[N], t[N], ct[N], j[N], cj[N];
void Dfs(int x = 1, int p = 0, int v = Inf)
{
    if(x != 1)
    {
        ct[x] = v;
        t[x] = p;
        dep[x] = dep[p] + 1;

        if(dep[t[x]] - dep[j[t[x]]] == dep[j[t[x]]] - dep[j[j[t[x]]]])
        {
            j[x] = j[j[t[x]]];
            cj[x] = min({ct[x], cj[t[x]], cj[j[t[x]]]});
        }
        else
        {
            j[x] = t[x];
            cj[x] = ct[x];
        }
    }

    for(auto [y, c] : T[x])
        if(y != p)
            Dfs(y, x, c);
}

void Dijkstra()
{
    FOR(i, 1, n)d[i] = Inf;
    priority_queue<pii, vector<pii>, greater<>> q;
    FOR(i, 1, k)
    {
        q.push({0, in[i]});
        d[in[i]] = 0;
    }

    while(!q.empty())
    {
        int dx = q.top().ff, x = q.top().ss;
        q.pop();

        if(dx > d[x])continue;

        for(auto [y, c] : G[x])
            if(d[y] > d[x] + c)
                q.push({d[y] = d[x] + c, y});
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k >> q;

    FOR(i, 1, k)cin >> in[i];

    int x, y, l;
    FOR(i, 1, m)
    {
        cin >> x >> y >> l;
        G[x].pb({y, l});
        G[y].pb({x, l});
        edges.pb({x, y, l});
    }

    Dijkstra();

    for(auto& e : edges)e.c = max(d[e.x], d[e.y]);

    sort(edges.begin(), edges.end(), [](edge a, edge b){return a.c > b.c;});

    for(auto e : edges)
        unite(e.x, e.y, e.c);

    t[1] = 1, ct[1] = Inf, j[1] = 1, cj[1] = Inf;
    Dfs();

//    FOR(i, 1, n)cout << d[i] << ' ';

    int a, b, tm;
    FOR(i, 1, q)
    {
        cin >> a >> b >> tm;

        int mn = min(d[a], d[b]);

        if(dep[a] > dep[b])swap(a, b);

        while(dep[a] > dep[b])
            if(dep[j[a]] >= dep[b])
            {
                mn = min(mn, cj[a]);
                a = j[a];
            }
            else
            {
                mn = min(mn, ct[a]);
                a = t[a];
            }

        while(a != b)
            if(j[a] != j[b])
            {
                mn = min({mn, cj[a], cj[b]});
                a = j[a];
                b = j[b];
            }
            else
            {
                mn = min({mn, ct[a], ct[b]});
                a = t[a];
                b = t[b];
            }

        cout << max(0, mn - tm) << '\n';
    }
    return 0;
}
