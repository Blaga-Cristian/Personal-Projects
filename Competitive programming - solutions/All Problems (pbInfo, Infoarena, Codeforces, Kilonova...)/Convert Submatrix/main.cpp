#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("convert_submatrix.in");
ofstream cout("convert_submatrix.out");
const int N = 106;
int n;
int dp[N][N],ans;///dp[i][j] = dimensiunile patratului maxim care are coltul din dreapta jos in i,j
bool mat[N][10];
char s[110];
void Dynamic(int x)
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=8;++j)
        {
            if(mat[i][j]==x)
            {
                dp[i][j] = 1;
                int sz = min(dp[i][j-1],dp[i-1][j]);
                if(mat[i-sz][j-sz]!=x)sz--;
                dp[i][j] = max(dp[i][j],sz+1);
                ans = max(ans,dp[i][j]);
            }
        }
}
void Clear()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=8;++j)
            dp[i][j] = 0;
}
int main()
{
    cin.get(s,109);
    cin.get();
    n = strlen(s);
    for(int i=0;i<strlen(s);++i)
    {
        int x = s[i];
        for(int k=0;k<8;++k)
        {
            mat[i+1][8-k] = x%2;
            x >>= 1;
        }
    }
    Dynamic(0);
    Clear();
    Dynamic(1);
    cout<<ans;
    return 0;
}
