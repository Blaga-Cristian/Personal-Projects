#include <fstream>

using namespace std;
ifstream cin("suma5.in");
ofstream cout("suma5.out");
const int N = 58,di[] = {0,0,1,1},dj[]={0,1,1,0},Inf = 0x3f3f3f3f;
int n,s,k;
int pir[N][N][N];
int dp[N][N][N];
int start[N];
void afisare(int niv,int i,int j)
{
    if(niv==0 || i<1 || j<1 || i>niv || j>niv)return;
    int val = dp[niv][i][j] - pir[niv][i][j];
    if(dp[niv-1][i-1][j-1] == val)afisare(niv-1,i-1,j-1);
    if(dp[niv-1][i-1][j] == val)afisare(niv-1,i-1,j);
    if(dp[niv-1][i][j-1] == val)afisare(niv-1,i,j-1);
    if(dp[niv-1][i][j] == val)afisare(niv-1,i,j);
    cout<<start[niv] + (i-1)*niv + j-1<<' ';
}
int main()
{
    cin>>n;
    start[1] = 1;
    for(int i=2;i<=N;++i)
        start[i] = start[i-1] + (i-1)*(i-1);
    while(s<n)
    {
        ++k;
        for(int i=1;i<=k;++i)
            for(int j=1;j<=k;++j)
                cin>>pir[k][i][j];
        s+=k*k;
    }
    cout<<k<<' ';
    dp[1][1][1] = pir[1][1][1];
    for(int x = 2; x <= k; ++x)
        for(int i=1;i<=x;++i)
            for(int j=1;j<=x;++j)
            {
                dp[x][i][j] = Inf;
                if(dp[x-1][i-1][j-1]!=0)dp[x][i][j] = min(dp[x][i][j],dp[x-1][i-1][j-1] + pir[x][i][j]);
                if(dp[x-1][i][j-1]!=0)dp[x][i][j] = min(dp[x][i][j],dp[x-1][i][j-1] + pir[x][i][j]);
                if(dp[x-1][i-1][j]!=0)dp[x][i][j] = min(dp[x][i][j],dp[x-1][i-1][j] + pir[x][i][j]);
                if(dp[x-1][i][j]!=0)dp[x][i][j] = min(dp[x][i][j],dp[x-1][i][j] + pir[x][i][j]);
            }
    int ans = Inf,indi,indj;
    for(int i=1;i<=k;++i)
        for(int j=1;j<=k;++j)
        {
            if(dp[k][i][j] < ans)
            {
                ans = dp[k][i][j];
                indi = i;
                indj = j;
            }
        }
    cout<<ans<<'\n';
    afisare(k,indi,indj);
    return 0;
}
