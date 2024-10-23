#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long

using namespace std;
const int N = 250009;

ll n, b, p, v[N], m, a, x, y, pt[N];

ll tree[4 * N];

void precalc()
{
    pt[0] = 1;
    FOR(i, 1, n)
        pt[i] = (pt[i - 1] * b) % p;
}

void Build(int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        tree[nod] = v[st];
        return;
    }
    int mij = (st + dr) >> 1;
    Build(nod << 1, st, mij);
    Build(nod << 1 | 1, mij + 1, dr);

    tree[nod] = ((tree[nod << 1] * pt[dr - mij]) % p + tree[nod << 1 | 1]) % p;
}
void Update(int poz, ll val, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        tree[nod] = val;
        return;
    }
    int mij = (st + dr) >> 1;
    if(poz <= mij)Update(poz, val, nod << 1, st, mij);
    else Update(poz, val, nod << 1 | 1, mij + 1, dr);

    tree[nod] = ((tree[nod << 1] * pt[dr - mij]) % p + tree[nod << 1 | 1]) % p;
}
ll Query(int l, int r, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)
        return (tree[nod] * pt[r - dr]) % p;

    int mij = (st + dr) >> 1;
    if(r <= mij)return Query(l, r, nod << 1, st, mij);
    else if(l > mij)return Query(l, r, nod << 1 | 1, mij + 1, dr);
    return (Query(l, r, nod << 1, st, mij) + Query(l, r, nod << 1 | 1, mij + 1, dr)) % p;
}

int main()
{
    freopen("rest.in" , "r", stdin);
    freopen("rest.out", "w", stdout);

    cin >> n >> b >> p;
    precalc();

    FOR(i, 1, n)cin >> v[i];
    Build();

    cin >> m;
    while(m --)
    {
        cin >> a >> x >> y;
        if(a == 1)Update(x, y);
        else cout << Query(x, y) << '\n';
    }
    return 0;
}
