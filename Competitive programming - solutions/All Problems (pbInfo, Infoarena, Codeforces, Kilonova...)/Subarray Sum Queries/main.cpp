#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2 * 1e5 + 9;

int n, m, k, x;

struct info
{
    ll mx, pre, suf, sum;

    info operator + (info const& a)
    {
        return {max(mx, max(a.mx, suf + a.pre)),
                max(pre, sum + a.pre),
                max(a.suf, a.sum + suf),
                sum + a.sum};
    }
};
info tree[4 * N];

void Build(int nod, int st, int dr)
{
    if(st == dr)
    {
        cin >> x;
        tree[nod] = {max(x, 0), max(x, 0), max(x, 0), x};
        return;
    }
    int mij = (st + dr) >> 1;
    Build(nod << 1, st ,mij);
    Build(nod << 1 | 1, mij + 1, dr);

    tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
}
void Update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        tree[nod] = {max(val, 0), max(val, 0), max(val, 0), x};
        return;
    }
    int mij = (st + dr) >> 1;
    if(poz <= mij)Update(nod << 1, st, mij, poz, val);
    else Update(nod << 1 | 1, mij + 1, dr, poz, val);

    tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
}

int main()
{
    cin >> n >> m;
    Build(1, 1, n);
    while(m --)
    {
        cin >> k >> x;
        Update(1, 1, n, k, x);
        cout << tree[1].mx << '\n';
    }
    return 0;
}
