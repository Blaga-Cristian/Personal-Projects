#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("cuvant2.in");
ofstream cout("cuvant2.out");

char cuv[270];
int dp[270][270],ans,cnt,nrpal;
int sum;
int main()
{
    cin>>cuv;
    for(int i=1;i<=strlen(cuv);++i)
        for(int j=1;j<=strlen(cuv);++j)
            {
                if(cuv[i-1]==cuv[strlen(cuv) - j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans,dp[i][j]);
            }
            if(dp[i][j]==0&&dp[i-1][j-1]>1)sum+=dp[i-1][j-1],cnt++;
            }
    for(int i=1;i<=strlen(cuv);++i)
    {
        if(dp[strlen(cuv)][i] > 1)
        {
            cnt++;
            sum+=dp[strlen(cuv)][i];
        }
        if(dp[i][strlen(cuv)] > 1)
        {
            cnt++;
            sum+=dp[i][strlen(cuv)];
        }
    }
    for(int i=1;i<=strlen(cuv);++i,cout<<endl)
        for(int j=1;j<=strlen(cuv);++j)
            cout<<dp[i][j]<< ' ';
    cout<<cnt + (strlen(cuv) - sum)<<' '<<ans;
    return 0;
}
