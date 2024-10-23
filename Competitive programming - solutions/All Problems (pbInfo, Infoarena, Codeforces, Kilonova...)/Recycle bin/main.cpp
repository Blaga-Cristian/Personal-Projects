#include <fstream>
#define ll long long
using namespace std;
ifstream cin("recyclebin.in");
ofstream cout("recyclebin.out");
const int N = 1009,fmsk = 1023;
ll dp[fmsk+5][N],ans;
ll n,a,b,x,y,v[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];


    for(int s = 0;s <= fmsk; ++s)
        for(int i=1;i<=n;++i)
        {
            dp[s][i] = max(dp[s][i],dp[s][i-1] + v[i]);
            for(int k = 0; 1 << k <= i; ++k)
                if(s&(1<<k))
                    dp[s][i] = max(dp[s][i],dp[s^(1<<k)][i - (1<<k)]);
            ans = max(ans,dp[s][i]);
        }
    cout<<ans;
    return 0;
}
