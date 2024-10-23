#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
int n,x;
int c[109];

int dp[(int)1e6 + 9];

int main()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    cin >> n >> x;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];

    for(int i = 1; i <= n; ++i)
        for(int s = 0; s + c[i] <= x; ++s)
            if(dp[s] != 0)
                {
                    dp[s + c[i]] += dp[s];
                    if(dp[s + c[i]] >= Mod)dp[s + c[i]] -= Mod;
                }

    cout << dp[x];
    return 0;
}
