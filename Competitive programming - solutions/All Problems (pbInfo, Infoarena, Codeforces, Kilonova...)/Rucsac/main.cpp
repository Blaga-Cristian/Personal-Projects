#include <iostream>

using namespace std;
int dp[1009][10009],g[1009],v[1009];
const int Inf  = 1;
int n,G;
int main()
{
    int ans = -Inf;
    cin>>n>>G;
    for(int i=1;i<=n;++i)
        cin>>g[i]>>v[i];


    for(int i=0;i<=n;++i)
        dp[i][0] = 0;
    for(int j=0;j<=G;++j)
        dp[0][j] = 0;


    for(int i=1;i<=n;++i)
        for(int j = 0; j <= G; ++j)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=g[i] && dp[i][j] < dp[i-1][j-g[i]] + v[i])
                dp[i][j] = dp[i-1][j-g[i]] + v[i];
            ans = max(ans,dp[i][j]);
        }
    cout<<ans;
    return 0;
}
