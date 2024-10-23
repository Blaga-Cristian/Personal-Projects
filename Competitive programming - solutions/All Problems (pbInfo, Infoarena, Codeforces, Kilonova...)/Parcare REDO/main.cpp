#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
using namespace std;
const string TASK("veri");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 5009;
const ll Mod = 1e9 + 7;
const ll Inf = (0x3f3f3f3f) >> 2;

int c, n, m, s, a, b;
bool viz[N];

int ds[N], ts[N];
int da[N], ta[N];
int db[N], tb[N];
int d[N], t[N];

vvi G(N), Gt(N);

void Bfs(int nod, vvi& gr, int* dist, int* par)
{
    FOR(i, 1, n)
    {
        dist[i] = Inf;
        par[i] = 0;
    }
    dist[nod] = 0;
    queue<int> q; q.push(nod);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto y : gr[x])
            if(dist[y] > dist[x] + 1)
        {
            dist[y] = dist[x] + 1;
            par[y] = x;
            q.push(y);
        }
    }
}


vi get_path(int y, int* t, bool inv = false)
{
    vi ret;
    for(int i = y; i != 0; i = t[i])
        ret.pb(i);

    if(!inv)reverse(ret.begin(), ret.end());

    return ret;
}

void af(vi v)
{
    cout << (int)v.size() - 1 << '\n';
    for(auto i : v)cout << i << ' ';
    cout << '\n';
}

int main()
{
    cin >> c;
    cin >> n >> m;
    cin >> s >> a >> b;

    int x, y;
    FOR(i, 1, m)
    {
        cin >> x >> y;
        G[x].pb(y);
        Gt[y].pb(x);
    }

    Bfs(s, G, ds, ts);
    Bfs(a, Gt, da, ta);
    Bfs(b, Gt, db, tb);

    int ans = Inf, nod1 = -1, nod2 = -1;

    queue<int> q;q.push(s);
    FOR(i, 1, n)viz[i] = false;
    viz[s] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        Bfs(x, G, d, t);

        for(auto y : Gt[x])
            if(ans > ds[x] + d[y] + 1 + max(da[x], db[x]))
            {
                ans = ds[x] + d[y] + 1 + max(da[x], db[x]);
                nod1 = x;
                nod2 = y;
            }

        for(auto y : G[x])
            if(!viz[y])
        {
            viz[y] = true;
            q.push(y);
        }
    }


    if(c == 1)cout << ans << '\n';
    else
    {
        vi res = get_path(nod1, ts);res.pop_back();
        Bfs(nod1, G, d, t);
        vi aux = get_path(nod2, t);
        res.insert(res.end(), aux.begin(), aux.end());
        res.pb(nod1);

        af(res);
        af(get_path(nod1, ta, true));
        af(get_path(nod1, tb, true));
    }
    return 0;
}
