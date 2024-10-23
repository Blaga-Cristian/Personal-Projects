#include <iostream>
#include <iomanip>
using namespace std;
int n,a,b; /// dp[i][j] = pos de a obtine valoarea j din aruncarea a i zaruri
unsigned int dp[105][605];
int main()
{
    cin>>n>>a>>b;
    dp[0][0] = 1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=i*6;++j)
        {
            if(dp[i-1][j] != 0)
            {
                for(int k=1;k<=6;++k)
                    dp[i][j+k] += dp[i-1][j];
            }
        }
    }
    int sum=0,imp=0;
    for(int i=0;i<=6*n;++i)
    {
        sum += dp[n][i];
        if(i>=a&&i<=b)imp+=dp[n][i];
    }
    int ans = (((long double)(imp))/sum)*1000000;
    cout<<fixed<<setprecision(6)<<ans/1000000.0;
    return 0;
}
