#include <bits/stdc++.h>
#include <bits/extc++.h>
#define ll long long
#define VI vector<int>
#define VVI vector<VI>
using namespace std;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> indexed_multiset;
const int N = 1e5 + 9;

int n, p[N], u, v, f[N], first[N], last[N], dep[N], poz[N], s, x, op, k, m, q, t[N], A;
ll S;
VVI G;
struct info
{
    ll sum, nod, max, nodymin, ymin, pmin, pmax, lazy;
};
info tree[8 * N];
int arr[4 * N], sz;
indexed_multiset sts[N];

void ETour(int x, int p)
{
    t[x] = p;
    arr[++sz] = x;
    first[x] = sz;
    dep[x] = dep[p] + 1;

    for(auto y : G[x])
    {
        if(y == p)continue;
        ETour(y, x);
    }

    arr[++sz] = x;
    last[x] = sz;
}

void Push(int nod, int st, int dr) /// Mut din nod in copii, si modific copiii
{
    if(tree[nod].lazy == 0 || st == dr)return;

    ll val = tree[nod].lazy, mij = (st + dr) >> 1, len;

    vector<info> v {tree[nod << 1], tree[nod << 1 | 1]};
    for(int i = 0; i < 2; ++i)
    {
        len = mij - st + 1;
        if(i == 1)len = dr - mij;
        v[i].sum = val * len;
        v[i].nod = v[i].ymin;
        v[i].max = val - v[i].ymin;
        ///v[i].nodymin = v[i].nodymin;
        ///v[i].ymin = v[i].ymin;
        v[i].pmin = val;
        v[i].pmax = val;
        v[i].lazy = val;
    }

    tree[nod << 1] = v[0];
    tree[nod << 1 | 1] = v[1];

    tree[nod].lazy = 0;
}

info Merge(info a, info b) /// OK!!
{
    info c = a;
    c.sum += b.sum;
    if(a.max < b.max || (a.max == b.max && a.nod > b.nod))
        c.nod = b.nod;
    c.max = max(a.max, b.max);
    if(a.ymin > b.ymin || (a.ymin == b.ymin && a.nodymin > b.nodymin))
        c.nodymin = b.nodymin;
    c.ymin = min(a.ymin, b.ymin);
    c.pmin = min(a.pmin, b.pmin);
    c.pmax = max(a.pmax, b.pmax);

    c.lazy = 0;

    return c;
}

void Build(int nod, int st, int dr) /// OK!!
{
    if(st == dr)
    {
        int x = arr[st];
        tree[nod].sum = p[x];
        tree[nod].nod = x;
        tree[nod].max = p[x] - dep[x];
        tree[nod].nodymin = x;
        tree[nod].ymin = dep[x];
        tree[nod].pmin = p[x];
        tree[nod].pmax = p[x];
        return;
    }
    int mij = (st + dr) >> 1;
    Build(nod << 1, st, mij);
    Build(nod << 1 | 1, mij + 1, dr);

    tree[nod] = Merge(tree[nod << 1], tree[nod << 1 | 1]);
}

info Query(int nod, int st, int dr, int a, int b) /// OK!!
{
    if(a <= st && dr <= b)
        return tree[nod];

    Push(nod, st, dr);
    int mij = (st + dr) >> 1;
    if(b <= mij)return Query(nod << 1, st, mij, a, b);
    else if(a > mij)return Query(nod << 1 | 1, mij + 1, dr, a, b);
    return Merge(Query(nod << 1, st, mij, a, b), Query(nod << 1 | 1, mij + 1, dr, a, b));
}
void Update(int nod, int st, int dr, int a, int b, int val) /// OK!!!
{
    if(dr < a || st > b || tree[nod].pmin >= val)return;

    if(a <= st && dr <= b && tree[nod].pmax <= val)
    {
        tree[nod].sum = (dr - st + 1) * val;
        tree[nod].nod = tree[nod].nodymin;
        tree[nod].max = val - tree[nod].ymin;
        ///tree[nod].nodymin = tree[nod].nodymin;
        ///tree[nod].ymin = tree[nod].ymin;
        tree[nod].pmin = val;
        tree[nod].pmax = val;
        tree[nod].lazy = val;
        return;
    }

    Push(nod, st, dr);
    int mij = (st + dr) >> 1;
    if(a <= mij)Update(nod << 1, st, mij, a, b, val);
    if(b > mij)Update(nod << 1 | 1, mij + 1, dr, a, b, val);

    tree[nod] = Merge(tree[nod << 1], tree[nod << 1 | 1]);
}

int main()
{
    cin >> n;
    G = VVI(n + 1);
    for(int i = 1; i <= n; ++i)cin >> p[i];
    for(int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ETour(1, 0);
    Build(1, 1, sz);

    cin >> m;
    for(int i = 1; i <= m; ++i)poz[i] = 1;
    for(int i = 1; i <= m; ++i)
    {
        cin >> f[i];
        sts[1].insert(f[i]);
    }


    cin >> q;
    while(q --)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> k;
            auto ans = Query(1, 1, sz, first[poz[k]], last[poz[k]]);

            for(int nod = ans.nod; nod != poz[k]; nod = t[nod])
                sts[nod].insert(f[k]);

            poz[k] = ans.nod;
        }
        else if(op == 2)
        {
            cin >> s >> S >> x;
            auto ans = Query(1, 1, sz, first[s], last[s]);
            if(ans.sum / 2 >= S)continue;

            Update(1, 1, sz, first[s], last[s], x);
        }
        else if(op == 3)
        {
            cin >> s >> A;

            if(A > sts[s].size())
            {
                cout << "-1\n";
                continue;
            }

            cout << *(sts[s].find_by_order(sts[s].size() - A)) << '\n';
        }
    }


    return 0;
}
