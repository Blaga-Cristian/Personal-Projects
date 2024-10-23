#include <fstream>

using namespace std;
ifstream cin("crescator.in");
ofstream cout("crescator.out");
const int Nmax = 1000,Smax = 10000,mod = 700001;
int n,s;
int dp[Nmax][Smax];///dp[i][j] = nr de mod de a obt suma j folosind primele i valori
int main()
{
    cin>>s;

    for(int i = 1; i <= s; ++i)
        dp[i][0] = 1;

    for(int i = 1; i <= s; ++i)
        for(int sum = i; sum <= s; ++sum)
            dp[i][sum] = dp[i][sum-i] + dp[i-1][sum],
            dp[i][sum] %= mod;

    int ans = 0;
    for(int i = 1; i <= s;++i)
        ans += dp[i][s],
        ans %= mod;
    cout<<ans;
    return 0;
}
