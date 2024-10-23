#include <fstream>
#define stanga 0
#define sus 1
#define dreapta 2
#define jos 3
#define ll long long
using namespace std;
ifstream cin("tmax.in");
ofstream cout("tmax.out");
const int N = 1009;
const long long inf = 1000000000000000000LL;
int v[N][N],n,m,cnt;
ll val,ans = -inf,dp[4][N][N];
/// dp[0][i][j] = suma maxima la stanga de pt de coord i,j
/// dp[1][i][j] = suma maxima la sus de pt de coord i,j
/// dp[2][i][j] = suma maxima la dreapta de pt de coord i,j
/// dp[3][i][j] = suma maxima la jos de pt de coord i,j
void Dynamic()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            dp[stanga][i][j] = max(1LL*v[i][j],dp[stanga][i][j-1] + v[i][j]);
        for(int j=m;j>0;--j)
            dp[dreapta][i][j] = max(1LL*v[i][j],dp[dreapta][i][j+1] + v[i][j]);
    }
    for(int j=1;j<=m;++j)
    {
        for(int i=1;i<=n;++i)
            dp[sus][i][j] = max(1LL*v[i][j],dp[sus][i-1][j] + v[i][j]);
        for(int i=n;i>0;--i)
            dp[jos][i][j] = max(1LL*v[i][j],dp[jos][i+1][j] + v[i][j]);
    }
}
void Check(ll x)
{
    if(x>ans)
    {
        ans = x;
        cnt = 1;
    }
    else if(x==ans)cnt++;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>v[i][j];
    Dynamic();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            ///In sus
            if(i>2&&j>1&&j<m)
            {
                val = v[i][j] + v[i-1][j] + dp[stanga][i][j-1] + dp[dreapta][i][j+1] + dp[sus][i-2][j];
                Check(val);
            }
            ///In jos
            if(i<n-1&&j>1&&j<m)
            {
                val = v[i][j] + v[i+1][j] + dp[stanga][i][j-1] + dp[dreapta][i][j+1] + dp[jos][i+2][j];
                Check(val);
            }
            ///La stanga
            if(j>2&&i>1&&i<n)
            {
                val = v[i][j] + v[i][j-1] + dp[sus][i-1][j] + dp[jos][i+1][j] + dp[stanga][i][j-2];
                Check(val);
            }
            ///La dreapta
            if(j<m-1&&i>1&&i<n)
            {
                val = v[i][j] + v[i][j+1] + dp[sus][i-1][j] + dp[jos][i+1][j] + dp[dreapta][i][j+2];
                Check(val);
            }
        }
    cout<<ans<<' '<<cnt;
    return 0;
}
