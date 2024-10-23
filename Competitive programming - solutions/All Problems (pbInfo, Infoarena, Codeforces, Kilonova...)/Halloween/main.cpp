#include <iostream>

using namespace std;
const int Inf = 0x3f3f3f3f;
int dp[10009],g[1009];
int n,G;
int main()
{
    cin>>n>>G;
    for(int i=1;i<=n;++i)cin>>g[i];

    for(int i=1;i<=G;++i)dp[i]=Inf;
    dp[0] = 0;

    for(int i=1;i<=n;++i)
        for(int j = G - g[i]; j >= 0; --j)
            if(dp[j]!=Inf)dp[j+g[i]] = min(dp[j+g[i]],dp[j] + 1);

    dp[G] == Inf ? cout<<"NU" : cout<<dp[G];
    return 0;
}
