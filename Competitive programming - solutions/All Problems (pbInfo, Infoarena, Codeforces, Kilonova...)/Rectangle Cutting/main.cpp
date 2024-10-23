#include <bits/stdc++.h>

using namespace std;
const int N = 509, Inf = 0x3f3f3f3f;

int dp[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            dp[i][j] = Inf;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            for(int k = 1; k <= min(i, j); ++k)
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i - k][k] + (k != j) + (k != i));
            for(int k = 1; k < i; ++k)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            for(int k = 1; k < j; ++k)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 2);
        }

    cout << dp[n][m];
    return 0;
}
