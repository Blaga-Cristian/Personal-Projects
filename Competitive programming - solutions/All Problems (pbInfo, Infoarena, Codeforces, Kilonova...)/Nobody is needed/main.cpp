#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define ll long long
//#define int long long
using namespace std;

const string TASK("heavypath");
//ifstream fin(TASK + ".in");
//ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout

const int N = 5e5 + 9;
const bool test_cases = false;

int n, m, q, t[N], dep[N], w[N], heavy_son[N], head[N], bot[N], pos[N], NEXT_INDEX, lo[N], hi[N];
ll need[N];
vvi G(N), sectors(N), tocheck(N);
struct info
{
    int f, x, d;
};
info qus[N];

struct node
{
    ll lazy, delta;
};
node tree[4 * N];
void Reset(int nod = 1, int st = 1, int dr = n)
{
    tree[nod].lazy = tree[nod].delta = 0;
    if(st == dr)return;
    int m = (st + dr) >> 1;
    Reset(nod << 1, st, m);
    Reset(nod << 1 | 1, m + 1, dr);
}

void Push(int nod, int st, int dr)
{
    if(st == dr || (tree[nod].lazy == 0 && tree[nod].delta == 0))return;

    ll v = tree[nod].lazy, d = tree[nod].delta;
    int m = (st + dr) >> 1;

    tree[nod << 1].lazy += v;
    tree[nod << 1].delta += d;
    tree[nod << 1 | 1].lazy += v + 1LL * (m - st + 1) * d;
    tree[nod << 1 | 1].delta += d;

    tree[nod].lazy = tree[nod].delta = 0;
}

void Update(int l, int r, int val, int delta, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)
    {
        tree[nod].lazy += 1LL * val + 1LL * (st - l) * delta;
        tree[nod].delta += delta;
        return;
    }
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(l <= m)Update(l, r, val, delta, nod << 1, st, m);
    if(r > m)Update(l, r, val, delta, nod << 1 | 1, m + 1, dr);
}

node Query(int p, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)return tree[nod];
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(p <= m)return Query(p, nod << 1, st, m);
    return Query(p, nod << 1 | 1, m + 1, dr);
}

void Dfs(int x = 1, int p = 1)
{
    dep[x] = dep[p] + 1;
    w[x] = 1;

    heavy_son[x] = -1;
    for(auto y : G[x])
    {
        Dfs(y, x);

        w[x] += w[y];
        if(heavy_son[x] == -1 || w[heavy_son[x]] < w[y])heavy_son[x] = y;
    }
}

void Build_Vec(int x = 1, int hd = 1)
{
    pos[x] = ++NEXT_INDEX;
    head[x] = hd;
    bot[hd] = x;

    if(heavy_son[x] != -1)Build_Vec(heavy_son[x], hd);

    for(auto y : G[x])
        if(y != heavy_son[x])
            Build_Vec(y, y);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 2; i <= n; ++i)
    {
        cin >> t[i];
        G[t[i]].pb(i);
    }

    int x;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x;
        sectors[x].pb(i);
    }

    for(int i = 1; i <= m; ++i)cin >> need[i];

    cin >> q;
    for(int i = 1; i <= q; ++i)cin >> qus[i].f >> qus[i].x >> qus[i].d;

    Dfs();
    Build_Vec();

    for(int i = 1; i <= m; ++i)
    {
        lo[i] = 1;
        hi[i] = q + 1;
    }


    ll sum;
    int init, id;
    node r;
    for(bool changed = true; changed;)
    {
        changed = false;

        Reset();
        for(int i = 1; i <= m; ++i)
            if(lo[i] != hi[i])
                tocheck[(lo[i] + hi[i]) >> 1].pb(i);

        for(int i = 1; i <= q; ++i)
        {
            Update(pos[qus[i].f], pos[bot[head[qus[i].f]]], qus[i].x, qus[i].d);

            while(tocheck[i].size())
            {
                changed = true;
                id = tocheck[i].back();
                tocheck[i].pop_back();

                sum = 0;
                for(auto x : sectors[id])
                {
                    init = x;
                    for(; x; x = t[head[x]])
                    {
                        r = Query(pos[x]);
                        sum += r.lazy;
                        sum += (dep[init] - dep[x]) * r.delta;
                    }

                    if(sum >= need[id])break;
                }

                if(sum >= need[id])hi[id] = i;
                else lo[id] = i + 1;
            }
        }
    }

    for(int i = 1; i <= m; ++i)
        if(lo[i] <= q)cout << lo[i] << '\n';
        else cout << "rekt\n";

    return 0;
}
