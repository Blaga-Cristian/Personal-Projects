#include <iostream>

using namespace std;
const int N = 209;
int n,dp[N][N];
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>dp[i][i];

    for(int len = 2; len <= n; ++len)
        for(int i = 1; i + len - 1 <= n; ++i)
        {
            int j = i + len - 1;
            for(int p = i; p < j; ++p)
                dp[i][j] = max(dp[i][j],(dp[i][p] + dp[p+1][j])>>1);
        }
    cout<<dp[1][n];
    return 0;
}
