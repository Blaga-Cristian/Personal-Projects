#include <bits/stdc++.h>

using namespace std;
const int N = 25, MOD = 1000000007;

int n, dp[2][1 << N], prv = 0, cur = 1;
bool mat[N][N];

int putere(int baza, int exp)
{
    int ret = 1;
    while(exp)
    {
        if(exp & 1)
            ret = (1LL * ret * baza) % MOD;

        baza = (1LL * baza * baza) % MOD;
        exp >>= 1;
    }
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> mat[i][j];

    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i, swap(prv, cur))
    {
        for(int s = 0; s < (1 << n); ++s)dp[cur][s] = 0;

        for(int s = 1; s < (1 << n); ++s)
            for(int j = 0; j < n; ++j)
                if(s & (1 << j))
                    dp[cur][s] = (dp[cur][s] + dp[prv][s - (1 << j)]) % MOD;
    }

    cout << (1LL * dp[prv][(1 << n) - 1] * putere(2, MOD - 2)) % MOD;
    return 0;
}
