#include <fstream>
#define N 1005
using namespace std;
ifstream cin("morcovi.in");
ofstream cout("morcovi.out");
int n,p,v[N],dp[1<<13][1+N],pas[14];
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>v[i];
    cin>>p;
    for(int i=0;i<p;++i)
        cin>>pas[i];
    for(int i=0;i<n;++i)
        dp[0][i] = v[i];
    for(int i=0;i<(1<<p);++i)
        for(int j=0;j<n;++j)
            for(int k=0;k<p;++k)
                if((i&(1<<k))==0)
                {
                    if(j+pas[k]<n)
                        dp[i|(1<<k)][j+pas[k]] = max(dp[i|(1<<k)][j+pas[k]],dp[i][j] + v[j+pas[k]]);
                    if(j-pas[k]>=0)
                        dp[i|(1<<k)][j-pas[k]] = max(dp[i|(1<<k)][j-pas[k]],dp[i][j] + v[j-pas[k]]);
                }
    int ans = 0;
    for(int i=0;i<n;++i)
        ans = max(ans,dp[(1<<p)-1][i]);
    cout<<ans;
    return 0;
}
