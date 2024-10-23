#include <bits/stdc++.h>

using namespace std;
const int N = 4009, Mod = 998244353;

int n, k;
vector<vector<vector<int>>> dp;
vector<int> sp;

int main()
{
    cin >> n >> k;
    dp = vector<vector<vector<int>>>(n + 9, vector<vector<int>>(k + 9, vector<int>((n / k) + 9)));
    sp = vector<int>(k + 9);

    dp[0][0][0] = 1;

    for(int len = 1; len <= n; ++len)
        for(int c = 0; c <= (n / k); ++c)
    {
        for(int j = 1; j <= k; ++j)
            sp[j] = sp[j - 1] + dp[len - 1][j][c];

        for(int i = 0; i <= k; ++i)
        {
            if(i == 0)
            {
                if(c > 0)dp[len][i][c] = dp[len - 1][k - 1][c - 1];
            }
            else dp[len][i][c] = dp[len - 1][i - 1][c];

            dp[len][i][c] += sp[k] - sp[i];
        }
    }

    int ans = 0;
    for(int c = 1; c <= (n / k); ++c)
        for(int i = 0; i <= k; ++i)
            ans = (ans + (1LL * c * dp[n][i][c]) % Mod) % Mod;

    cout << ans;
    return 0;
}
