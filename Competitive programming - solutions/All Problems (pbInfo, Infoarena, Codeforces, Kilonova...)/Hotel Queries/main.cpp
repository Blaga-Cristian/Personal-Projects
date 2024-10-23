#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 9, Inf = 1e9 + 9;

int n, m, x, tree[4 * N];

void Build()
{
    for(int i = 1; i <= n; ++i)cin >> tree[n - 1 + i];
    for(int i = n - 1; i; --i)tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
}
void Build(int nod, int st, int dr)
{
    if(st == dr)
    {
        cin >> tree[nod];
        return;
    }
    int mij = (st + dr) >> 1;
    Build(nod << 1, st, mij);
    Build(nod << 1 | 1, mij + 1, dr);

    tree[nod] = max(tree[nod << 1], tree[nod << 1 | 1]);
}

int Query(int nod, int st, int dr, int val)
{
    if(st == dr)
        return st;
    int mij = (st + dr) >> 1;
    if(tree[nod << 1] >= val)
        return Query(nod << 1, st, mij, val);
    return Query(nod << 1 | 1, mij + 1, dr, val);
}

void Update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        tree[nod] -= val;
        return;
    }

    int mij = (st + dr) >> 1;
    if(poz <= mij)
        Update(nod << 1, st, mij, poz, val);
    else
        Update(nod << 1 | 1, mij + 1, dr, poz, val);

    tree[nod] = max(tree[nod << 1], tree[nod << 1 | 1]);
}


int main()
{
    cin >> n >> m;
    Build();
    for(int i = 1; i <= m; ++i)
    {
        cin >> x;
        if(tree[1] < x)cout << "0 ";
        else
        {
            int poz = Query(1, 1, n, x);
            cout << poz << ' ';
            Update(1, 1, n, poz, x);
        }
    }
    return 0;
}
