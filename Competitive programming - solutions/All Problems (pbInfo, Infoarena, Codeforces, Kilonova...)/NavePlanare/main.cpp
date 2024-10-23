#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream cin("naveplanare.in");
ofstream cout("naveplanare.out");
const int N = 209, V = 2009, M = 1000,Inf = 0x3f3f3f3f;
int n,k,x[N],y[N];
int dp[2][N][V],prv = 0,cur = 1;
int ans;

int main()
{
    cin>>n>>k;
    for(int i = 1; i <= n; ++i)
        cin>>x[i]>>y[i],x[i] += M,y[i] += M;

    sort(x+1,x+n+1);
    sort(y+1,y+n+1);


    prv = 0, cur = 1;
    memset(dp,Inf,sizeof(dp));
    for(int i = 0;i <= 1; ++i)
        for(int k = 0; k <= 2000; ++k)
            dp[i][0][k] = 0;
    for(int i = 1; i <= n; ++i,swap(prv,cur))
        for(int j = 1; j <= k; ++j)
            for(int k = 0; k <= 2000; ++k)
                dp[cur][j][k] = min(dp[prv][j-1][k-1] + abs(x[i] - k),
                                min(dp[prv][j][k],dp[cur][j][k-1]));

    ans += dp[prv][k][2000];

    prv = 0, cur = 1;
    memset(dp,Inf,sizeof(dp));
    for(int i = 0;i <= 1; ++i)
        for(int k = 0; k <= 2000; ++k)
            dp[i][0][k] = 0;
    for(int i = 1; i <= n; ++i,swap(prv,cur))
        for(int j = 1; j <= k; ++j)
            for(int k = 0; k <= 2000; ++k)
                dp[cur][j][k] = min(dp[prv][j-1][k-1] + abs(y[i] - k),
                                min(dp[prv][j][k],dp[cur][j][k-1]));

    ans += dp[prv][k][2000];

    cout<<ans;
    return 0;
}
