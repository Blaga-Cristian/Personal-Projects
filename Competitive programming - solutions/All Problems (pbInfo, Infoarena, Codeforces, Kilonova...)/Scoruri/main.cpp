#include <iostream>

using namespace std;
unsigned long long dp[10000][10000],n,m;
int main()
{
    cin>>n>>m;
    if(!n || !m)
    {
        cout<<1;
        return 0;
    }
    for(int i=1;i<=2001;++i)
        dp[i][0] = dp[0][i] =  1;

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]);
    cout<<dp[n][m];
    return 0;
}
