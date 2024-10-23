#include <fstream>

using namespace std;
ifstream cin("zero1.in");
ofstream cout("zero1.out");
using pi = pair<int,int>;
const int N = 509,Inf = 0x3f3f3f3f;
int n,m;
int mat[N][N];
pi mnr[N][N];
pair<pi,pi> dp[N][N];


int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            cin>>mat[i][j];
            for(;mat[i][j] != 0 && mat[i][j] % 2 == 0; mnr[i][j].first ++,mat[i][j] = mat[i][j]/2);
            for(;mat[i][j] != 0 && mat[i][j] % 5 == 0; mnr[i][j].second++,mat[i][j] = mat[i][j]/5);
        }



    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            dp[i][j] = {{Inf,Inf},{Inf,Inf}};

    dp[1][1] = {{mnr[1][1].first,mnr[1][1].second},{mnr[1][1].first,mnr[1][1].second}};
    mat[1][1] = 0;


    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
    {
        if(mat[i][j] == 0)continue;

        pi minfi = min(dp[i][j-1].first,dp[i-1][j].first);
        pi minse;
        pi a = dp[i][j-1].second,b = dp[i-1][j].second;

        if(a.second < b.second || (a.second == b.second && a.first < b.first))
            minse = a;
        else
            minse = b;

        dp[i][j] = {{minfi.first + mnr[i][j].first, minfi.second + mnr[i][j].second},
                {minse.first + mnr[i][j].first,minse.second + mnr[i][j].second}};
    }

    cout<<min((min(dp[n][n].first.first,dp[n][n].first.second)),
    min(dp[n][n].second.first, dp[n][n].second.second));
    return 0;
}
