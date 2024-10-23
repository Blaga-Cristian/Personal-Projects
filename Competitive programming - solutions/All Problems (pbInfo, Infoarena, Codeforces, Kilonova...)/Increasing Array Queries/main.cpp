#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 9;

int n, q, a, b, x;

struct info
{
    int l, r, sz, c;

    info operator + (info const& a)
    {
        return {l, max(r, a.r), sz + a.sz, c + max(0, r - a.l) * a.sz};
    }
} tree[4 * N];

void Build(int nod, int st, int dr)
{
    if(st == dr)
    {
        cin >> x;
        tree[nod] = {x, x, 1, 0};
        return;
    }
    int mij = (st + dr) >> 1;
    Build(nod << 1, st ,mij);
    Build(nod << 1 | 1, mij + 1, dr);

    tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
}
info Query(int nod, int st, int dr, int a, int b)
{
    if(a <= st && dr <= b)
    {
        cout << st << ' ' << dr << '\n';
        return tree[nod];
    }

    int mij = (st + dr) >> 1;
    if(b <= mij)return Query(nod << 1, st, mij, a, b);
    else if(a > mij)return Query(nod << 1 | 1, mij + 1, dr, a, b);
    return Query(nod << 1, st, mij, a, b) + Query(nod << 1 | 1, mij + 1, dr, a, b);
}

int main()
{
    cin >> n >> q;
    Build(1, 1, n);

    while(q --)
    {
        cin >> a >> b;
        cout << Query(1, 1, n, a, b).c << '\n';
    }
    return 0;
}
