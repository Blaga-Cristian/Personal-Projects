#include <fstream>

using namespace std;
ifstream cin("palin.in");
ofstream cout("palin.out");
int n;
char s[4009];
int dp[4009][4009];
int main()
{
    cin>>n;
    cin>>(s+1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(s[i] == s[n-j+1])
                dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    cout<<n - dp[n][n];
    return 0;
}
