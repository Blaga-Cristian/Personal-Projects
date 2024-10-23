#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vpi vector<pii>
#define vvpi vector<vpi>

using namespace std;
const string TASK("termite");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 3e5 + 9, LG = 21, Inf = 0x3f3f3f3f;

int n, m, k, q;
vi src;

vvpi G(N);

struct muchie
{
    int x, y, c;

    bool operator < (muchie const& oth)
    {
        return c > oth.c;
    }
};
vector<muchie> muchii;


int d[N];
void Dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> q;

    FOR(i, 1, n)d[i] = Inf;
    FOR(i, 1, k)
    {
        d[src[i]] = 0;
        q.push({0, src[i]});
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


int dsu[N], sz[N], cst[N];
int find(int x){return dsu[x] == 0 ? x : find(dsu[x]);}
void unite(int x, int y, int c)
{
    x = find(x), y = find(y);
    if(x == y)return;
    if(sz[x] > sz[y])swap(x, y);
    cst[x] = c;
    dsu[x] = y;
    sz[y] += sz[x] + 1;
}

int main()
{
    cin >> n >> m >> k >> q;

    src.resize(k + 1);
    FOR(i, 1, k)cin >> src[i];

    int a, b, l;
    FOR(i, 1, m)
    {
        cin >> a >> b >> l;
        G[a].pb({b, l});
        G[b].pb({a, l});
        muchii.pb({a, b, -1});
    }

    Dijkstra();

    FOR(i, 0, m - 1)muchii[i].c = max(d[muchii[i].x], d[muchii[i].y]);
    sort(muchii.begin(), muchii.end());///ap maxim

    for(auto e : muchii)
    {
        int rx = find(e.x), ry = find(e.y);
        if(rx != ry)
        {
            unite(rx, ry, e.c);
        }
    }

    FOR(i, 1, q)
    {
        cin >> a >> b >> l;
        int ans = min(d[a], d[b]);

        int depa = 0, depb = 0, x = a, y = b;
        while(x)
        {
            x = dsu[x];
            depa ++;
        }
        while(y)
        {
            y = dsu[y];
            depb ++;
        }

        if(depa < depb)swap(a, b);

        while(depa > depb)
        {
            ans = min(ans, cst[a]);
            a = dsu[a];
        }

        while(a != b)
        {
            ans = min(ans, min(cst[a], cst[b]));
            a = dsu[a];
            b = dsu[b];
        }

        if(ans <= l)cout << "0\n";
        else cout << ans - l << '\n';
    }
    return 0;
}
