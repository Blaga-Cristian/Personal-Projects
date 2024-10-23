#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("cod2.in");
ofstream cout("cod2.out");
const int N = 259;
int k,m,n;
int v[N],s1[N],s2[N];
int dp[2][N][N],pre = 0, cur = 1;

int main()
{
    cin>>k>>n>>m;
    for(int i = 1; i <= k; ++i)
        cin>>v[i];
    for(int i = 1; i <= n; ++i)
        cin>>s1[i];
    for(int i = 1; i <= m; ++i)
        cin>>s2[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            dp[pre][i][j] = max(dp[pre][i-1][j],dp[pre][i][j-1]);
            if(s1[i] == s2[j])
                dp[pre][i][j] = max(dp[pre][i][j],dp[pre][i-1][j-1] + 1);
        }


    for(int l = 1; l <= k; ++l,swap(pre,cur))
    {
        memset(dp[cur],0,sizeof(dp[cur]));
        int lin = 0,col = 0;
        for(;s1[lin] != v[l]; ++ lin);
        for(;s2[col] != v[l]; ++ col);

        for(int i = 1; i < lin; ++i)
            for(int j = 1; j <= m; ++j)
                dp[cur][i][j] = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j < col; ++j)
                dp[cur][i][j] = 0;

        for(int i = lin; i <= n; ++i)
            for(int j = col; j <= m; ++j)
        {
            if(s1[i] == s2[j] && s1[i] == v[l])dp[cur][i][j] = dp[pre][i-1][j-1] + 1;
            else if(s1[i] == s2[j] && s1[i] != v[l])dp[cur][i][j] = dp[cur][i-1][j-1] + 1;
            else dp[cur][i][j] = max(dp[cur][i-1][j],dp[cur][i][j-1]);
        }


    }

    cout<<dp[pre][n][m];
    return 0;
}
