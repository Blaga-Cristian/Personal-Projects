#include <fstream>

using namespace std;
ifstream cin("rec.in");
ofstream cout("rec.out");
const int S = 405, N = 55, F = 405;
long long s,n,f,dp[N][S][S];///dp[i][s][c] = nr de moduri de ajunge la capitanul i care primeste c franci si unde se consuma s franci in total
///sa adaug sume partiale
int main()
{
    cin>>s>>n>>f;
    s -= n*(f-1);
    f = 1;
    for(int i=f;i<=s;++i)
        dp[1][i][i] = 1;
    for(int i=2;i<=n;++i)
    {
        for(int sum = i*f;sum<=s;++sum)
            for(int c= f;c<=sum - (i-1)*f;++c)
                for(int x = f; x<=c; ++x)
                    dp[i][sum][c] += dp[i-1][sum-c][x];
    }
    long long ans = 0;
    for(int i=f;i<=s - (n-1)*f;++i)
        ans += dp[n][s][i];
    cout<<ans;
    return 0;
}
