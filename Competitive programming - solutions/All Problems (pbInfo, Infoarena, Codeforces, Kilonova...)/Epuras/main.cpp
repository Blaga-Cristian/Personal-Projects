#include <fstream>

using namespace std;
ifstream cin("epuras.in");
ofstream cout("epuras.out");
const int N = 1009,Inf = 0x3f3f3f3f;
int n,v[N][N],dp[N][N],Max[N][N];
int main()
{
    cin>>n;

    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            dp[i][j] = Max[i][j] = -Inf;

    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>v[i][j];

    dp[1][1] = v[1][1];
    Max[1][1] = dp[1][1];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(!(i==1&&j==1))
                {
                    dp[i][j] = max(Max[i-1][j],Max[i][j-1]) + v[i][j];
                    Max[i][j] = max(dp[i][j],max(Max[i-1][j],Max[i][j-1]));
                }
    cout<<dp[n][n];
    return 0;
}
