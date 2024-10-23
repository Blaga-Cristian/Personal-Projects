#include <iostream>

using namespace std;
int n;
int dp[1000][1000];
int main()
{
    cin>>n;
    dp[1][1] = 1;
    for(int i =1 ;i <= n; ++i)
        for(int j =1 ; j<=i; ++j)
            dp[i][j] = max(dp[i][j],dp[i-1][j] + dp[i][j-1]);

    for(int i =1 ;i <= n; ++i,cout<<'\n')
        for(int j =1 ; j<=i; ++j)
            cout<<dp[i][j]<<' ';
    return 0;
}
