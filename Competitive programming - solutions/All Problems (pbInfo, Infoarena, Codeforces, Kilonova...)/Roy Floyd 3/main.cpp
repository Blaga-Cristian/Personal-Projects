#include <fstream>
#define val first
#define cnt second
using namespace std;
ifstream cin("rf.in");
ofstream cout("rf.out");
const int N = 260,Inf = 0x3f3f3f3f;
int n,v[N][N];
pair<int,int> dp[N][N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            {cin>>dp[i][j].val;
            if(dp[i][j].val!=0)dp[i][j].cnt = 1;}
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            if(i!=k)
                for(int j=1;j<=n;++j)
                    if(i!=j && j!=k)
                        if(dp[i][j].val > dp[i][k].val + dp[k][j].val)
                            dp[i][j].val = dp[i][k].val + dp[k][j].val,
                            dp[i][j].cnt = dp[i][k].cnt + dp[k][j].cnt;
                        else if(dp[i][j].val == dp[i][k].val + dp[k][j].val)
                            dp[i][j].cnt = max(dp[i][j].cnt,dp[i][k].cnt + dp[k][j].cnt);
    for(int i=1;i<=n;++i,cout<<'\n')
        for(int j=1;j<=n;++j)
            cout<<dp[i][j].val<<' ';
    for(int i=1;i<=n;++i,cout<<'\n')
        for(int j=1;j<=n;++j)
            cout<<dp[i][j].cnt<<' ';
    return 0;
}
