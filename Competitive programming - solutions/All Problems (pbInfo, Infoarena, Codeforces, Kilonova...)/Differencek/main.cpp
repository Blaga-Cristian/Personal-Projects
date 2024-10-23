#include <iostream>

using namespace std;
const int mod = 1000000007;
int arr[1009],n,p,k;
int dp[2][109];/// dp[i][j] = sum(st,dr) nr de moduri de a ajunge la val j la pozitia i
int main()
{
    cin>>n>>p>>k;
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    int curr = 0,prev = 1;
    for(int i=1;i<=n;++i,swap(curr,prev))
    {
        for(int j=1;j<=p;++j)
            dp[curr][j] = 0;
        for(int j=1;j<=p;++j)
        {
            if(!arr[i] || arr[i] == j)
            {
                if(i==1)dp[0][j] = 1;
                else for(int l = max(0,j-k);l<=min(p,j+k);++l)
                {
                    dp[curr][j] += dp[prev][l];
                    if(dp[curr][j]>=mod) dp[curr][j]-=mod;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=p;++i)
    {
        ans += dp[prev][i];
        if(ans>=mod)ans-=mod;
    }
    cout<<ans;
    return 0;
}
