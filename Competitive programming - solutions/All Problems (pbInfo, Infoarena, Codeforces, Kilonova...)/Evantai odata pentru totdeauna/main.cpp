#include <fstream>

using namespace std;
ifstream cin("evantai.in");
ofstream cout("evantai.out");
const int N = 703, mod = 30103,Vmax = 2100;
int aib[N][Vmax],v[N],n,dp[N][N];
void update(int x,int y,int val)
{
    for(int i = x; i<=N;i+=i&-i)
        for(int j = y;j<=Vmax;j+=j&-j)
        {
            aib[i][j] += val;
            aib[i][j] = aib[i][j] %mod;
        }
}
int query(int x,int y)
{
    int rez = 0;
    for(int i = x; i>0 ;i-=i&-i)
        for(int j = y; j>0 ; j-=j&-j)
        {
            rez += aib[i][j];
            rez = rez % mod;
        }
    return rez%mod;
}
int main()
{
    int sol = 0;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    for(int i=n-1;i>=1;--i)
    {
        for(int j=i+1;j<=n;++j)
        {
            dp[i][j] = 1 + query(j-1,v[i] + v[j] - 1);
            sol += dp[i][j];
            sol = sol % mod;
        }
        for(int j=i+1;j<=n;++j)
            update(j,v[i]+v[j],dp[i][j]);
    }
    cout<<sol;
    return 0;
}
