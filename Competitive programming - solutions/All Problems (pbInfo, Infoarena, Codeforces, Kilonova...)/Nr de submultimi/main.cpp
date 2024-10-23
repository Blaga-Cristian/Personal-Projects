#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9, MOD = 777013;

int n, dp[N];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + 1) % MOD;
        if(i > 2)dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }

    cout << dp[n];
    return 0;
}
