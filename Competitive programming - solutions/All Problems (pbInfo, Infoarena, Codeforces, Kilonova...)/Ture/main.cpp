#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("ture.in");
ofstream cout("ture.out");
const int N = 259;
int n,m,k,p,a,b;
int A[N][N],B[N][N];
long long dp[N][35000];
int main()
{
    cin>>n>>m>>k;
    cin>>p;
    while(p--)
    {
        cin>>a>>b;
        a--,b--;
        A[a][b] = 1;
    }


    if(n < m)
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                B[j][i] = A[i][j];
        memcpy(A,B,sizeof(B));
        swap(n,m);
    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int s = 0; s < (1<<m); ++s)
        {
            dp[i][s] += dp[i-1][s];
            for(int k = 0; k < m; ++k)
                if(!A[i-1][k] && !(s&(1<<k)))
                    dp[i][s | (1<<k)] += dp[i-1][s];
        }

    long long ans = 0;
    for(int s = 0; s < (1<<m); ++s)
        if(__builtin_popcount(s) == k)
            ans += dp[n][s];
    cout<<ans;
    return 0;
}
