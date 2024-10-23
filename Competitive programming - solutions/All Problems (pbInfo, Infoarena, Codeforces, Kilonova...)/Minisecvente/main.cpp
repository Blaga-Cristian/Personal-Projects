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
ifstream fin("minisecvente.in");
ofstream fout("minisecvente.out");

const int N = 1e5 + 9;

int n, v[N], ST[N][20];

void Precalc()
{
    FOR(i, 1, n)
        ST[i][0] = v[i];

    for(int k = 1; (1 << k) <= n; ++k)
        for(int i = 1; i + (1 << k) - 1 <= n; ++i)
            ST[i][k] = min(ST[i][k - 1], ST[i + (1 << (k - 1))][k - 1]);
}
int query(int a, int b)
{
    int k = log2(b - a + 1);
    return min(ST[a][k], ST[b - (1 << k) + 1][k]);
}

int cb(int x)
{
    int st = 1, dr = x, poz = 0;
    while(st <= dr)
    {
        int mij = (st + dr) >> 1;
        if(x - mij + 1 > query(mij, x))
        {
            st = mij + 1;
            poz = mij;
        }
        else dr = mij - 1;
    }

    return poz;
}

int main()
{



    fin >> n;

    FOR(i, 1, n)fin >> v[i];
    Precalc();

    ll ans = 0;
    FOR(i, 1, n)
    {
        int poz = cb(i);
        ans += poz;
    }

    fout << ans;
    return 0;
}
