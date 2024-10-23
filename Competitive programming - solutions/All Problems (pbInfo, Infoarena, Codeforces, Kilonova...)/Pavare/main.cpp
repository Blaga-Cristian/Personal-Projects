#include <bits/stdc++.h>

using namespace std;
const int N = 209;

int n, dp[N];

int main()
{
    cin >> n;
    n *= 2;
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        dp[i] *= 4;
        if(i >= 2)dp[i] -= dp[i - 2];
    }

    cout << dp[n];
    return 0;
}
