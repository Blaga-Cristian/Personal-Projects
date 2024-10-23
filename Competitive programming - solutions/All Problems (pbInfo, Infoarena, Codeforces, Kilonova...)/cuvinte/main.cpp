#include <fstream>

using namespace std;
ifstream cin("cuvinte8.in");
ofstream cout("cuvinte8.out");
const int Dim = 10001,Inf = 700;
int m,k,dp[2][Dim],len,n,curr=1,pre=0,pl;
char cuv[Dim],gresit[Dim];
int main()
{
    cin>>m>>k;
    cin>>len>>(cuv+1);
    while(m--)
    {
        cin>>n>>(gresit+1);
        for(int i=0;i<=k;++i)
            dp[pre][i] = i;
        dp[pre][k+1] = Inf;
        for(int i=1;i<=n;++i,swap(pre,curr))
        {
            pl = min(i+k+2,len+1);
            if(i-k-2 >= 0)
                dp[curr][i-k+1] = Inf;
            else
                dp[curr][0] = i;
            for(int j=max(1,i-k-2);j<=pl;++j)
                if(gresit[i] == cuv[j])
                    dp[curr][j] = dp[pre][j-1];
                else
                    dp[curr][j] = min(dp[pre][j],min(dp[curr][j-1],dp[pre][j-1])) + 1;
            dp[curr][pl] = Inf;
        }
        if(dp[pre][len]<=k)cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}
