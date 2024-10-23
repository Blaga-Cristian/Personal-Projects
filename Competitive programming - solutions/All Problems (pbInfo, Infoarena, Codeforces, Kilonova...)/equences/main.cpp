#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 35;

int n, m, k;
ll dp[N][N][N];


int main()
{
    cin >> n >> m >> k;

    for(int i = 1; i <= m; ++i)
        dp[1][i][1] = 1;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            for(int i1 = 1; i1 < j; ++i1)
                for(int j1 = 1; j1 <= k; ++j1)
                    dp[i][j][1] += dp[i - 1][i1][j1];

            for(int p = 2; p <= m; ++p)
                dp[i][j][p] += dp[i - 1][j][p - 1];
        }

    ll ans = 0;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= k; ++j)
            ans += dp[n][i][j];
    cout << ans;
    return 0;
}
