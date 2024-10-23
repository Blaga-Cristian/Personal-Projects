#include <fstream>

using namespace std;
ifstream cin("para.in");
ofstream cout("para.out");
const int N = 109,K = 109,mod = 30011;
int n,m,k;
int dp[K][N][N];
///dp[k][i][j] = ne de a plasa k caini pe drept ce se termina in i,j
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)
            dp[0][i][j] = 1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            for(int x=1;x<= min(k,i*j);++x)
            {
                dp[x][i][j] = dp[x][i-1][j];///nu plasez caine pe linia i(pot mereu sa adaug caine)
                if(i == n && j == m)///caz particular
                {
                    dp[x][i][j] += (j-1) * dp[x-1][i-1][j-1];///plasez un caine care nu e atacat (il plasez pe i,j)

                    if(i>=2 && x >= 2)
                        dp[x][i][j] += (j-1) * (i-1) * dp[x-2][i-2][j-1];///plasez caine atacat pe coloana

                    if(j>=2 && x >= 2)
                        dp[x][i][j] +=((j-1) * (j-2)/2)* dp[x-2][i-1][j-2];
                }
                else
                {
                    dp[x][i][j] += j * dp[x-1][i-1][j-1];///plasez un caine care nu e atacat (il plasez pe i,j)

                    if(i>=2 && x >= 2)
                        dp[x][i][j] += j * (i-1) * dp[x-2][i-2][j-1];   /// plasez un caine pe linia i care e "atacat" pe coloana

                    if(j>=2 && x >= 2)
                        dp[x][i][j] +=(j * (j-1)/2)* dp[x-2][i-1][j-2];     /// plasez doi caini pe linia i
                }
                dp[x][i][j] %= mod;
            }
    cout<<dp[k][n][m];
    return 0;
}
