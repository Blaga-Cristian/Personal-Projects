#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define ll long long

using namespace std;
const int N = 1e5 + 9;

int n, q, a[N];

struct node
{
    int lazy, delta;

    node() : lazy(0), delta(0) {}
};
node tree[4 * N];

void Push(int nod, int st, int dr)
{
    if(st == dr || (tree[nod].lazy == 0 && tree[nod].delta == 0))return;

    int l = tree[nod].lazy, d = tree[nod].delta, m = (st + dr) >> 1;

    tree[nod << 1].lazy += l;
    tree[nod << 1].delta += d;
    tree[nod << 1 | 1].lazy += l + (m - st + 1) * d;
    tree[nod << 1 | 1].delta += d;

    tree[nod].lazy = tree[nod].delta = 0;
}

void Update(int l, int r, int val, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)
    {
        tree[nod].lazy += (st - l) * val;
        tree[nod].delta += val;
        return;
    }
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(l <= m)Update(l, r, val, nod << 1, st, m);
    if(r > m)Update(l, r, val, nod << 1 | 1, m + 1, dr);
}

int Query(int p, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)return tree[nod].lazy + tree[nod].delta;
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(p <= m)return Query(p, nod << 1, st, m);
    return Query(p, nod << 1 | 1, m + 1, dr);
}

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)cin >> a[i];

    int op, x, y, val;
    for(int i = 1; i <= q; ++i)
    {
        cin >> op;
        if(op == 1)///Update
        {
            cin >> x >> y >> val;
            Update(x, y, val);
        }
        else if(op == 2)
        {
            cin >> x;
            cout << a[x] + Query(x) << '\n';
        }
    }
    return 0;
}
