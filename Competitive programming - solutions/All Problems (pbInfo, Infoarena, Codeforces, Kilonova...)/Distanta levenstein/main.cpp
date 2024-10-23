#include <iostream>
#include <cstring>
using namespace std;
char s[150],t[150];
int dp[101][101];
int main()
{
    cin>>s>>t;
    for(int i=1;i<=strlen(t);++i)
        dp[0][i] = i;
    for(int j=1;j<=strlen(s);++j)
        dp[j][0] = j;
    for(int i=1;i<=strlen(s);++i)
        for(int j=1;j<=strlen(t);++j)
            dp[i][j] = min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1] + (t[j-1]!=s[i-1])));
    cout<<dp[strlen(s)][strlen(t)];
    return 0;
}
