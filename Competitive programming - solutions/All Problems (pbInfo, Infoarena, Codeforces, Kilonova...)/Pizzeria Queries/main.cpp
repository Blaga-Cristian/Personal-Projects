#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 9;

int n, q, op, k, x;
int v[N];

struct node
{
    int lmn, rmn;

    node operator + (node a)
    {
        return {min(lmn, a.lmn), min(rmn, a.rmn)};
    }
};
node tree[4 * N];

void Build(int nod, int st, int dr)
{
    if(st == dr)
    {
        tree[nod] = {v[st] + n - st + 1, v[st] + st};
        return;
    }
    int mij = (st + dr) >> 1;
    Build(nod << 1, st, mij);
    Build(nod << 1 | 1, mij + 1, dr);

    tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
}
void Update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        tree[nod] = {v[st] + n - st + 1, v[st] + st};
        return;
    }
    int mij = (st + dr) >> 1;
    if(poz <= mij)Update(nod << 1, st, mij, poz, val);
    else Update(nod << 1 | 1, mij + 1, dr, poz, val);

    tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
}
int QueryL(int nod, int st, int dr, int poz)
{
    if(dr <= poz)
        return tree[nod].lmn - (n - poz + 1);

    int mij = (st + dr) >> 1;
    int ret = QueryL(nod << 1, st , mij, poz);
    if(mij + 1 <= poz)ret = min(ret, QueryL(nod << 1 | 1, mij + 1, dr, poz));
    return ret;
}
int QueryR(int nod, int st, int dr, int poz)
{
    if(st >= poz)
        return tree[nod].rmn - poz;
    int mij = (st + dr) >> 1;
    int ret = QueryR(nod << 1 | 1, mij + 1, dr, poz);
    if(mij >= poz)ret = min(ret, QueryR(nod << 1, st, mij, poz));
    return ret;
}

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)cin >> v[i];

    Build(1, 1, n);

    while(q --)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> k >> x;
            v[k] = x;
            Update(1, 1, n, k, x);
        }
        else
        {
            cin >> k;
            cout << min(QueryL(1, 1, n, k), QueryR(1, 1, n, k)) << '\n';
        }
    }
    return 0;
}
