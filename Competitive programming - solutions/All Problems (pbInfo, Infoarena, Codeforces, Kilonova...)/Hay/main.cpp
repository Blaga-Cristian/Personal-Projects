#include <iostream>

using namespace std;
const int vmax = 60000,nmax = 101,Inf = 0x3f3f3f3f;
int dp[vmax];
int g[nmax],v[nmax];
int main()
{
    int n,h;
    cin>>n>>h;
    for(int i=1;i<=n;++i)
        cin>>g[i]>>v[i];

    for(int i=1;i<=vmax;++i)dp[i]=Inf;
    dp[0] = 0;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=h;++j)
            if(dp[j]!=-Inf)
                dp[j+g[i]] = min(dp[j+g[i]],dp[j]+v[i]);
    int ans = 2147483647;
    for(int i=h;i<=vmax;++i)
        if(dp[i]!=-Inf)ans = min(ans , dp[i]);
    cout<<ans;
    return 0;
}
