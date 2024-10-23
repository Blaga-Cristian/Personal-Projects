#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define vpi vector<pii>
#define vvpi vector<vpi>
#define ll long long

using namespace std;
const int N = 500009, V = 1e6 + 9;

int n, q;

struct info
{
    int l, r;

    info(int l = 0, int r = 0) : l(l), r(r) {}
};
info ops[V];

vi queries[V];

struct node
{
    int v, lazy, setv;
    node(int v = 0, int lazy = 0, int setv = -1) : v(v), lazy(lazy), setv(setv) {}
};
node tree[4 * V];

void Build(int nod = 1, int st = 1, int dr = V - 1)
{
    tree[nod].v = tree[nod].lazy = 0;
    tree[nod].setv = -1;
    if(st == dr)return;
    int m = (st + dr) >> 1;
    Build(nod << 1, st, m);
    Build(nod << 1 | 1, m + 1, dr);
}

void Push(int nod, int st, int dr)
{
    if(st == dr || (tree[nod].lazy == 0 && tree[nod].setv == -1))return;

    int av = tree[nod].lazy, sv = tree[nod].setv;
    tree[nod].lazy = 0, tree[nod].setv = -1;

    if(sv != -1)
    {
        tree[nod << 1].lazy = av;
        tree[nod << 1].setv = sv;
        tree[nod << 1 | 1].lazy = av;
        tree[nod << 1 | 1].setv = sv;
    }
    else
    {
        tree[nod << 1].lazy += av;
        tree[nod << 1 | 1].lazy += av;
    }
}

void Update(int l, int r, int val, bool tip = 0, int nod = 1, int st = 1, int dr = V - 1)
{
    if(l <= st && dr <= r)
    {
        if(tip == 0)tree[nod].lazy += val;
        else
        {
            tree[nod].lazy = 0;
            tree[nod].setv = val;
        }
        return;
    }
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(l <= m)Update(l, r, val, tip, nod << 1, st, m);
    if(r > m)Update(l, r, val, tip, nod << 1 | 1, m + 1, dr);
}

int Query(int p, int nod = 1, int st = 1, int dr = V - 1)
{
    if(st == dr)
    {
        if(tree[nod].setv == -1)return tree[nod].lazy;
        return tree[nod].setv + tree[nod].lazy;
    }
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(p <= m)return Query(p, nod << 1, st, m);
    return Query(p, nod << 1 | 1, m + 1, dr);
}

int main()
{
    cin >> n >> q;

    int l, r;
    for(int i = 1; i <= n; ++i)
    {
        cin >> l >> r;
        queries[r - 1].pb(l);
    }

    set<int> splits;
    int a, t;
    for(int i = 1; i <= q; ++i)
    {
        cin >> a >> t;

        if(a == 1)splits.insert(t);
        else if(ops[i].l == ops[i].r && ops[i].l == 0)///nu e nicio operatie
        {
            ops[t].l = 1, ops[t].r = V - 1;

            auto it = splits.lower_bound(t);
            if(it != splits.begin())ops[t].l = *(-- it);

            it = splits.upper_bound(t);
            if(it != splits.end())ops[t].r = *it - 1;
        }
    }


    Build();

    int ans = 0;
    priority_queue<pii> pq;
    for(int dr = 1; dr < V; ++dr)
    {
        if(ops[dr].l && ops[dr].r)///e o operatie
        {
            Update(ops[dr].l, ops[dr].r - 1, 0, true);///le setez la 0

            while(!pq.empty() && pq.top().ss < dr)pq.pop();

            if(!pq.empty())Update(pq.top().ff, ops[dr].l - 1, - (dr - ops[dr].l));
            else Update(1, ops[dr].l - 1, - (dr - ops[dr].l));

            pq.push({dr, ops[dr].r});
        }
        else
        {
            while(!pq.empty() && pq.top().ss < dr)pq.pop();

            if(!pq.empty())Update(pq.top().ff, dr, 1);
            else Update(1, dr, 1);
        }

        for(auto st : queries[dr])
            ans += Query(st);
    }

    cout << ans << '\n';
    return 0;
}
