#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,dp[1009][1009];
char s1[1009],s2[1009];
int main()
{
    cin>>n;
    cin>>s1+1;
    strcpy(s2+1,s1+1);
    reverse(s2+1,s2+n+1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    cout<<dp[n][n];
    return 0;
}
