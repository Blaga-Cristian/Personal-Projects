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
ifstream fin("divquery.in");
ofstream fout("divquery.out");

const int N = 1e5 + 9, LG = 19;

int n, q, v[N], ST[N][LG];

int gcd(int a, int b)
{
    while(b)
    {
        int aux = a % b;
        a = b;
        b = aux;
    }
    return a;
}

void precalc()
{
    FOR(i, 1, n)
        ST[i][0] = v[i];

    for(int k = 1; (1 << k) <= n; ++k)
        for(int i = 1; i + (1 << k) - 1 <= n; ++i)
            ST[i][k] = gcd(ST[i][k - 1], ST[i + (1 << (k - 1))][k - 1]);
}
int query(int st, int dr)
{
    int k = log2(dr - st + 1);
    return gcd(ST[st][k], ST[dr - (1 << k) + 1][k]);
}

int main()
{

    fin >> n >> q;

    FOR(i, 1, n)
        fin >> v[i];

    precalc();

    int a, b;
    while(q --)
    {
        fin >> a >> b;
        fout << query(a, b) << '\n';
    }

    return 0;
}
