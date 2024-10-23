#include <fstream>
#define st 0
#define dr 1
using namespace std;
ifstream cin("robot.in");
ofstream cout("robot.out");
const int N = 2800,mod = 64997;
int n,k,sol,pre=1,cur=0;
int dp[N][N];///dp[i][j] = nr de moduri pentru braul drept de a ajunge pe raftul i, aflandu-se pr raftur j;
int main()
{
    cin>>n>>k;
    for(int i=k;i<=n;++i)
        dp[pre][i] = 1;
    sol+=dp[1][n];
    sol%=mod;
    for(int i=2;i<=n;++i,swap(pre,cur))
    {
        for(int j=0;j<=n;++j)
            dp[cur][j] = 0;
        for(int j=i+1;j<=n;++j)
        {
            dp[cur][j] = dp[cur][j-1] + dp[pre][j];
            dp[i][j] %= mod;
        }
        sol+=dp[i][n];
        sol%=mod;
    }
    cout<<sol;
    return 0;
}
