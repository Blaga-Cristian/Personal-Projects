#include <iostream>

using namespace std;
const int N = 250;
int pol[N];
long long dp[N][N]; /// dp[i][j] = modul de alegere a triunghiurilor astfel incat valoarea lui este maxima
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>pol[i];
    for(int m=1;m<=n;++m)
    {
        for(int i=1,j=m;j<=n;++i,++j)
        {
            if(j<i+2)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 0;
                for(int k=i+1;k<j;++k)
                {
                    long long val = dp[i][k] + dp[k][j] + 1LL*pol[i]*pol[k]*pol[j];
                    if(val>dp[i][j])
                        dp[i][j] = val;
                }
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
