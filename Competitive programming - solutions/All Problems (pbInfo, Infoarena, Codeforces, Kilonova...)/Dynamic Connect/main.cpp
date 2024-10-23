#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
using namespace std;
const int N = 300009;

int n, k;
char op;
bool is_query[N];


class DSU
{
public:
    vector<int> t, w;
    vector<PI> events;
    int cc;

    DSU()
    {}

    DSU(int n) : t (vector<int>(n + 1)), w (vector<int>(n + 1, 1)), cc(n)
    {}

    inline int find(int x){return t[x] == 0 ? x : find(t[x]);}

    void unite(int a, int b)
    {
        int root_a = find(a), root_b = find(b);

        if(root_a == root_b)return;

        if(w[root_a] < w[root_b])swap(root_a, root_b);

        t[root_b] = root_a;
        w[root_a] += w[root_b];
        -- cc;
        events.push_back({root_b, root_a});
    }

    void rollback()
    {
        if(events.empty())return;

        int root_b = events.back().F, root_a = events.back().S;
        t[root_b] = 0;
        w[root_a] -= w[root_b];
        ++ cc;
        events.pop_back();
    }

    int get_state(){return events.size();}
    int get_cc(){return cc;}
};
DSU* dsu;

map<PI, int> edges;
vector<PI> tree[4 * N];

void Update(int nod, int st, int dr, int a, int b, PI edge)
{
    if(a <= st && dr <= b)
    {
        tree[nod].push_back(edge);
        return;
    }
    int mij = (st + dr) >> 1;
    if(a <= mij)Update(nod << 1, st, mij, a, b, edge);
    if(b > mij)Update(nod << 1 | 1, mij + 1, dr, a, b, edge);
}

void Push(int nod, int st, int dr)
{
    int sz = dsu->get_state();

    for(auto edge : tree[nod])dsu->unite(edge.F, edge.S);

    if(st == dr)
    {
        if(is_query[st])
            cout << dsu->get_cc() << '\n';
    }
    else
    {
        int mij = (st + dr) >> 1;
        Push(nod << 1, st, mij);
        Push(nod << 1 | 1, mij + 1, dr);
    }

    while(dsu->get_state() != sz)dsu->rollback();
}

int main()
{
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);

    cin >> n >> k;
    dsu = new DSU(n);

    int u, v;
    for(int i = 1; i <= k; ++i)
    {
        cin >> op;
        if(op == '?')
            is_query[i] = true;
        else if(op == '+')
        {
            cin >> u >> v;
            if(u > v)swap(u, v);
            edges[{u, v}] = i;
        }
        else if(op == '-')
        {
            cin >> u >> v;
            if(u > v)swap(u, v);
            Update(1, 1, k, edges[{u, v}], i, {u, v});
            edges.erase({u, v});
        }
    }
    for(auto it : edges)Update(1, 1, k, it.S, k, it.F);

    Push(1, 1, k);
    return 0;
}
