#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("nunta1.in");
ofstream cout("nunta1.out");
const int N = 53;
int n,x;
int dp[N][N];

void comp(int& ret,int a,int b)
{
    for(int i = 0; 1 << i <= a; ++i)
        for(int j = 0; 1 << j <= b; ++j)
            if((a & (1 << i)) && (b & (1<<j)))
               ret |= (1 << (int)(abs(i-j)));
}

int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin>>x;
        dp[i][i] = (1<<x);
    }

    for(int len = 2; len <= n; ++len)
        for(int i = 1; i + len - 1 <= n; ++i)
        {
            int j = i + len - 1;
            for(int k = i; k + 1 <= j; ++k)
                comp(dp[i][j],dp[i][k],dp[k+1][j]);
        }

    cout<<__builtin_popcount(dp[1][n])<<'\n';
    for(int i = 0; 1 << i <= dp[1][n]; ++i)
        if(dp[1][n] & (1<<i))
            cout<<i<<' ';
    return 0;
}
