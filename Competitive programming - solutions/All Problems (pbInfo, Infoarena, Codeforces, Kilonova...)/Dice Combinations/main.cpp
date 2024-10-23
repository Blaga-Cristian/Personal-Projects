#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 9;
const int Mod = 1e9 + 7;
int dp[N];
int n;
ll s;

int main()
{
    dp[0] = 1;
    cin >> n;

    s = dp[0];
    for(int i = 1; i <= 6; ++i)
        dp[i] = s, s += dp[i];

    for(int i = 7; i <= n; ++i)
    {
        s = (s - dp[i-7] + Mod) % Mod;
        dp[i] = s;
        s += dp[i];
    }

    cout << dp[n];
    return 0;
}
