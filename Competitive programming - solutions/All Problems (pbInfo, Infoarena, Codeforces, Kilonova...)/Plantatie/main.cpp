#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("plantatie.in");
ofstream cout("plantatie.out");
const int N = 509,L = 9;
int n,m,v[N][N],ST[N][N][L]; ///ST[i][j][k] = maximul patratului de lungime 2^k care are coltul stanga sus in i,j
void process()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            ST[i][j][0] = v[i][j];
    for(int k = 1; 1<<k <= n; ++k)
        for(int i = 1; i + (1<<k) - 1 <= n; ++i)
            for(int j = 1; j + (1<<k) -1 <= n; ++j)
                ST[i][j][k] = max(ST[i][j][k-1],max(ST[i+(1<<(k-1))][j][k-1],max(ST[i][j+(1<<(k-1))][k-1],ST[i+(1<<(k-1))][j+(1<<(k-1))][k-1])));
}
int Query(int i,int j,int len)
{
    int k = log2(len);
    return max(ST[i][j][k],max(ST[i + len - (1<<k)][j][k],max(ST[i][j + len - (1<<k)][k],ST[i + len - (1<<k)][j + len - (1<<k)][k])));
}
int main()
{
    int i,j,len;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>v[i][j];
    process();
    while(m--)
    {
        cin>>i>>j>>len;
        cout<<Query(i,j,len)<<'\n';
    }
    return 0;
}
