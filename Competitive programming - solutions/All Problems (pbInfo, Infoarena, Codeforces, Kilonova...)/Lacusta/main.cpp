#include <fstream>

using namespace std;
ifstream cin("lacusta.in");
ofstream cout("lacusta.out");
const int N = 105,INF = 0x3f3f3f3f;
int n,m,mat[N][N],dp[N][N],aux[N]; ///dp[i][j] = suma maxima pentru a ajunge pe pozitia i,j
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>mat[i][j];

    for(int j=1;j<=m;++j)
        dp[2][j] = mat[1][1] + mat[1][j] + mat[2][j];
    dp[2][1] = INF;

    for(int i=3;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            dp[i][j] = mat[i-1][j] + mat[i][j];
            int mini = INF;
            for(int k=1;k<=m;++k)
                if(k!=j)
                    mini = min(mini,dp[i-1][k]);
            dp[i][j] += mini;
        }
    }
    int mini = INF;
    for(int i=1;i<m;++i)
        mini = min(mini,dp[n][i]);
    cout<<mini + dp[n][m];
    return 0;
}
