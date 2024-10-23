#include <fstream>

using namespace std;
ifstream cin("smsm.in");
ofstream cout("smsm.out");
const int N = 504;
int d[] = {6, 2, 4, 8};
int t[] = {1, 3, 9, 7};
int D,T,P,Q;
long long ans;
long long A[N][N]; ///A[i][j] = asociatul lui 2^i*3^j
long long dp[N][N],E[N][N]; ///cea submultimea cu suma maxima care include dp[i][j](2^i*3^j)
int main()
{
    cin>>D>>T>>P>>Q;
    for (int i=0;i<=D;i++)
        for (int j=0;j<=T;j++)
            if (i == 0)
                A[i][j] = (t[j%4] * P) % Q;
            else
                A[i][j] = (d[i % 4] * t[j % 4]%10 * P) % Q;

    for(int i = D;i>=0;--i)
        for(int j=0;j<=T;++j)
    {
        if(i==N||j==0)
            dp[i][j] = A[i][j];
        else
            dp[i][j] = A[i][j] + E[i+1][j-1];
        long long e1,e2;
        if(j==0)
            e1 = 0;
        else
            e1 = E[i][j-1];
        if(i==D)
            e2 = 0;
        else
            e2 = E[i+1][j];
        E[i][j] = max(e1,max(e2,dp[i][j]));
        ans = max(ans,dp[i][j]);
    }
    cout<<ans;
    return 0;
}
