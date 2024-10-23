#include <bits/stdc++.h>
#define pb push_back
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define ll long long
using namespace std;
ifstream fin("turcane.in");
ofstream fout("turcane.out");

const int N = 1009, Inf = 0x3f3f3f3f, Mod = 1e9 + 7;
int n, m, c, p, q, r;
int dp[N][N];


void solve1()
{
    dp[1][1] = 1;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
    {
        if(i == 1 && j == 1)continue;
        dp[i][j] = Inf;

        int k = r;
        dp[i][j] = min(dp[i][j], dp[max(1, i - q)][j] + 1);
        dp[i][j] = min(dp[i][j], dp[i][max(1, j - p)] + 1);
        if(i <= r || j <= r)
            k = min(i, j) - 1;
        dp[i][j] = min(dp[i][j], dp[i - k][j - k] + 1);
        if(i > 2 && j > 1)dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + 1);
        if(i > 1 && j > 2)dp[i][j] = min(dp[i][j], dp[i - 1][j - 2] + 1);
    }

    fout << dp[n][m] - 1;
}

int splin[N][N], spcol[N][N], spdiag[N][N];
ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod) x -= Mod;
    while(x < 0) x += Mod;
    return x;
}
void solve2()
{
    dp[1][1] = 1;
    splin[1][1] = spcol[1][1] = spdiag[1][1] = 1;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
    {
        if(i == 1 && j == 1)continue;
        dp[i][j] = add(add(splin[i][j - 1], - splin[i][max(0, j - p - 1)]),
                    add(add(spcol[i - 1][j], - spcol[max(0, i - q - 1)][j]),
                    add(spdiag[i - 1][j - 1], - spdiag[max(0, i - r - 1)][max(0, j - r - 1)])));

        if(i > 2 && j > 1)dp[i][j] = add(dp[i][j], dp[i - 2][j - 1]);
        if(i > 1 && j > 2)dp[i][j] = add(dp[i][j], dp[i - 1][j - 2]);

        splin[i][j] = add(splin[i][j - 1], dp[i][j]);
        spcol[i][j] = add(spcol[i - 1][j], dp[i][j]);
        spdiag[i][j] = add(spdiag[i - 1][j - 1], dp[i][j]);

    }

    fout << dp[n][m];
}

int main()
{
    fin >> c;
    fin >> n >> m;
    fin >> p >> q >> r;

    if(c == 1)solve1();
    else solve2();
    return 0;
}
