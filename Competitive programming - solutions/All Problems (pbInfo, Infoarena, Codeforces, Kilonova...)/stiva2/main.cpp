#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("stiva2.in");
ofstream cout("stiva2.out");
const int N = 505,inf  = 0x3f3f3f3f;
char s[N];
int n,dp[N][N]; /// dp[i][j] = nr minim de operatii de push necesare pentru a genera sirul s[i...j];

int main()
{
    cin>>s;
    n = strlen(s);
    for(int i=0;i<n;++i)
        dp[i][i] = 1;
    for(int d = 2;d<=n;++d)
        for(int i=0;i+d-1<n;++i)
    {
        int j = i+d-1;
        dp[i][j] = dp[i][j-1] + 1;
        for(int k=i;k<j;++k)
            if(s[k]==s[j])
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j-1]);
    }
    cout<<2*dp[0][n-1] + n;
    return 0;
}
