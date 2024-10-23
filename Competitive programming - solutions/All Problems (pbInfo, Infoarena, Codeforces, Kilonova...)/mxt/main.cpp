#include <iostream>

using namespace std;
int v[2009];
int dp[2009][2009],n; /// d[i][j] = csotul maxim de ajunge la secventa care incepe in i si se termina in j
int main()
{
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    dp[2][n] = v[1];
    dp[1][n-1] = v[n];
    for(int i=1;i<=n;++i)
        for(int j=n;j>=i;--j)
            dp[i][j] = max(dp[i-1][j] + (n-(j-i+1)) * v[i-1],dp[i][j+1] + (n-(j-i+1)) * v[j+1]);
    for(int i=1;i<=n;++i)
        ans = max(ans,dp[i][i] + n*v[i]);
    cout<<ans;
    return 0;
}
