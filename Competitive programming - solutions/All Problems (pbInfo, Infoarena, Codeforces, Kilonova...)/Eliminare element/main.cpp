#include <iostream>

using namespace std;
const int N = 2 * 1e5 + 9;

int n, poz, v[N], tree[4 * N];

void Build(int nod, int st, int dr)
{
    tree[nod] = dr - st + 1;
    if(st == dr)return;
    int mij = (st + dr) >> 1;
    Build(nod << 1, st, mij);
    Build(nod << 1 | 1, mij + 1, dr);
}
void Update(int nod, int st, int dr, int poz)
{
    --tree[nod];
    if(st == dr)return;
    int mij = (st + dr) >> 1;
    if(tree[nod << 1] >= poz)Update(nod << 1, st, mij, poz);
    else Update(nod << 1 | 1, mij + 1, dr, poz - tree[nod << 1]);
}
int Query(int nod, int st, int dr, int poz)
{
    if(st == dr)
        return v[st];
    int mij = (st + dr) >> 1;
    if(tree[nod << 1] >= poz)return Query(nod << 1, st, mij, poz);
    return Query(nod << 1 | 1, mij + 1, dr, poz - tree[nod << 1]);
}

int main()
{
    cin >> n;
    Build(1, 1, n);
    for(int i = 1; i <= n; ++i)cin >> v[i];

    for(int i = 1; i <= n; ++i)
    {
        cin >> poz;
        cout << Query(1, 1, n, poz) << ' ';
        Update(1, 1, n, poz);
    }
    return 0;
}
