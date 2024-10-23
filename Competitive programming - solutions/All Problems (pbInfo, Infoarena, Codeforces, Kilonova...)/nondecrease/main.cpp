#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("nondecreasing.in");
ofstream cout("nondecreasing.out");
const int N = 50009,Inf = 0x3f3f3f3f;
char s[N];
int n,dp[N][27],mn;
int main()
{
    cin.get(s+1,N);
    n = strlen(s+1);


    for(int i = 1; i <= n; ++i)
    {
        mn = Inf;
        for(int j = 1; j <= 26; ++j)
        {
            mn = min(mn,dp[i-1][j]);
            dp[i][j] = mn;
            if(s[i] - 'a' + 1 != j)
                dp[i][j] += j + (s[i] - 'a' + 1);
        }
    }

    int ans = Inf;
    for(int i = 1; i <= 26; ++i)
        ans = min(ans,dp[n][i]);
    cout<<ans;
    return 0;
}
