#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2 * 1e5 + 9;

struct info
{
    ll sum;
    info *l, *r;

    info() : sum(0), l(0), r(0)
    {}
    info(ll sum, info* l, info* r) : sum(sum), l(l), r(r)
    {}
};
vector<info*> roots;

int n, q, a, b, x, k, op;

info* Build(int st, int dr)
{
    info* nod = new info();
    if(st == dr)
    {
        cin >> (nod->sum);
        return nod;
    }
    int mij = (st + dr) >> 1;
    nod->l = Build(st, mij);
    nod->r = Build(mij + 1, dr);

    nod->sum = nod->l->sum + nod->r->sum;
    return nod;
}
info* Update(info* nod, int st, int dr, int poz, int val)
{
    info* nnod = new info();
    nnod->l = nod->l;
    nnod->r = nod->r;

    if(st == dr)
    {
        nnod->sum = val;
        return nnod;
    }
    int mij = (st + dr) >> 1;
    if(poz <= mij)nnod->l = Update(nnod->l, st, mij, poz, val);
    else nnod->r = Update(nnod->r, mij + 1, dr, poz, val);

    nnod->sum = nnod->l->sum + nnod->r->sum;
    return nnod;
}
ll Query(info* nod, int st, int dr, int a, int b)
{
    if(a <= st && dr <= b)
        return nod->sum;
    int mij = (st + dr) >> 1;
    if(b <= mij)return Query(nod->l, st, mij, a, b);
    else if(a > mij)return Query(nod->r, mij + 1, dr, a, b);
    return Query(nod->l, st, mij, a, b) + Query(nod->r, mij + 1, dr, a, b);
}

int main()
{
    cin >> n >> q;
    roots.push_back(Build(1, n));

    while(q --)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> k >> a >> x;

            roots[k - 1] = Update(roots[k - 1], 1, n, a, x);
        }
        else if(op == 2)
        {
            cin >> k >> a >> b;

            cout << Query(roots[k - 1], 1, n, a, b) << '\n';
        }
        else if(op == 3)
        {
            cin >> k;
            roots.push_back(new info(roots[k - 1]->sum, roots[k - 1]->l, roots[k - 1]->r));
        }
    }
    return 0;
}
