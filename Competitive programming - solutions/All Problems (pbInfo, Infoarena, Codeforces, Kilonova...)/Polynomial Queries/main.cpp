#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2 * 1e5 + 9;

int n, q, op, a, b;

struct info
{
    ll sum, lazy;
    bool has_lazy;
};
info tree[4 * N];

void Build(int nod, int st, int dr)
{
    if(st == dr)
    {
        cin >> tree[nod].sum;
        return;
    }
    int mij = (st + dr) >> 1;
    Build(nod, st, mij);
    Build(nod, mij + 1, dr);

    tree[nod].sum = tree[nod << 1].sum + tree[nod << 1 | 1].sum;
}
void Push(int nod, int st, int dr)
{
    if(!tree[nod].has_lazy || st == dr)return;

    int mij = (st + dr) >> 1, val = tree[nod].lazy;
    tree[nod << 1].sum += val * (mij - st + 1) + (mij - st + 1) * (mij - st + 2) / 2;
    tree[nod << 1].has_lazy = true;

    tree[nod << 1 | 1].sum += (dr - mij) * (mij + 1 - st) + (dr - mij) * val + (dr - mij) * (dr - mij + 1) / 2;
    tree[nod << 1 | 1].has_lazy = true;
    tree[nod << 1 | 1].lazy += mij + 1 - st;

    tree[nod].has_lazy = false;
    tree[nod].lazy = 0;
}
void Update(int nod, int st, int dr, int a, int b)
{
    if(a <= st && dr <= b)
    {
        tree[nod].sum += (st - a) * (dr - st + 1) + (dr - st + 1) * (dr - st + 2) / 2;
        tree[nod].has_lazy = true;
        tree[nod].lazy += (st - a);
        return;
    }
    Push(nod, st, dr);

    int mij = (st + dr) >> 1;
    if(a <= mij)Update(nod << 1, st, mij, a, b);
    if(b > mij)Update(nod << 1 | 1, mij + 1, dr, a, b);

    tree[nod].sum = tree[nod << 1].sum + tree[nod << 1 | 1].sum;
}
ll Query(int nod, int st, int dr, int a, int b)
{
    if(a <= st && dr <= b)
        return tree[nod].sum;
    int mij = (st + dr) >> 1;
    if(b <= mij)return Query(nod << 1, st, mij, a, b);
    else if(a > mij)return Query(nod << 1 | 1, mij + 1, dr, a, b);
    return Query(nod << 1, st, mij, a, b) + Query(nod << 1 | 1, mij + 1, dr, a, b);
}
int main()
{
    cin >> n >> q;
    Build(1, 1, n);

    cout << tree[1].sum;
    while(q --)
    {
        cin >> op >> a >> b;
        if(op == 1)Update(1, 1, n, a, b);
        else cout << Query(1, 1, n, a, b) << '\n';
    }
    return 0;
}
