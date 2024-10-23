#include <bits/stdc++.h>

using namespace std;
const int N = 10009, Mod = 10007;

int n, k, x;
int dp[N][N];
/// dp[i][j][k] = desc nr i in j numere cu cel mai mare mai mic sau egal cu k

int main()
{
    cin >> n >> k >> x;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dp[i][1] = 1;

    for(int j = 2; j <= n; ++j)
        for(int i = 1; i <= n; ++i)
        {
            dp[i][j] = dp[i - 1][j];
            if(i > x)dp[i][j] = (dp[i - 1][j] + dp[i - x][j - 1]) % Mod;
        }
    cout << dp[n][k] - dp[n - 1][k];
    return 0;
}
