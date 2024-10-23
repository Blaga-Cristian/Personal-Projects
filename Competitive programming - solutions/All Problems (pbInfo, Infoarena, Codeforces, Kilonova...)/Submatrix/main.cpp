#include <fstream>

using namespace std;
ifstream cin("submatrix.in");
ofstream cout("submatrix.out");
const int N = 1009;
int dp[N][N],n,ans;
bool v[N][N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>v[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(v[i][j]==1)
            {
                dp[i][j] = 1;
                int mn = min(dp[i-1][j],dp[i][j-1]);
                if(v[i-mn][j-mn]==1)
                    dp[i][j] = max(dp[i][j],mn+1);
                else
                    dp[i][j] = max(dp[i][j],mn);
                ans = max(dp[i][j],ans);
            }
    cout<<ans;
    return 0;
}
