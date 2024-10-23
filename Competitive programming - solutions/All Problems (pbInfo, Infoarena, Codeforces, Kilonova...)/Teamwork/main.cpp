#include <fstream>

using namespace std;
ifstream cin("teamwork.in");
ofstream cout("teamwork.out");
const int N=18;
int n;
int dp[N][(1<<N)+2]; /// nivelul rezolvat si cu care copii a fost rezolvat
int ef[N][N];
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>ef[i][j];
    for(int i=0;i<n;++i)
        dp[0][1<<i] = ef[0][i];
    for(int i=0;i<n-1;++i)
        for(int k=1;k<(1<<n);++k)
            for(int j=0;j<n;++j)
                if(!(k&(1<<j)))
                    dp[i+1][k|(1<<j)] = max(dp[i+1][k|(1<<j)],dp[i][k] + ef[i+1][j]);
    cout<<dp[n-1][(1<<n)-1];
    return 0;
}
