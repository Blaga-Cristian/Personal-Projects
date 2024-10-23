#include <fstream>

using namespace std;
ifstream cin("palixor.in");
ofstream cout("palixor.out");
const int N = 50009,S = 1024;
const int mod = 1000000007;
int dp[N][S],n,v[N]; ///dp[i][j] = nr de stari care se afla in reprezentarea zecimala a lui j,  pana in punctul i
int main()
{
    long long x;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        while(x)
        {
            v[i] ^= (1<<(x%10));
            x = x/10;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j = 0; j < S; ++j)
            dp[i][j] = dp[i-1][j];
        for(int j = 0; j < S; ++j)
            dp[i][v[i]^j] = (dp[i][v[i]^j] + dp[i-1][j]) % mod;
        dp[i][v[i]] = (dp[i][v[i]] + 1)% mod;
    }
    long long sol = dp[n][0];
    int i=1;
    while(i<=512)
    {
        sol = (sol + dp[n][i]) % mod;
        i = i * 2;
    }
    cout<<sol;
    return 0;
}
