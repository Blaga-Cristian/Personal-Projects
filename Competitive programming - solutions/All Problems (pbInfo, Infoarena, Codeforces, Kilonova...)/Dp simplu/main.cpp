#include <fstream>

using namespace std;
ifstream cin("joc2.in");
ofstream cout("joc2.out");
const int N = 106;
int Diana[N][N],Jonny[N][N],a[N][N],n,m;
void diana()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            Diana[i][j] = max(Diana[i-1][j],Diana[i][j-1]) + a[i][j];
}
void john()
{
    for(int j=m;j>=1;--j)
        for(int i=1;i<=n;++i)
            Jonny[i][j] = max(Jonny[i-1][j],Jonny[i][j+1]) + a[i][j];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    john();
    diana();
    if(Diana[n][m]>Jonny[n][1])
        cout<<1<<' '<<Diana[n][m];
    else if(Diana[n][m]<Jonny[n][1])
        cout<<2<<' '<<Jonny[n][1];
    else
        cout<<3<<' '<<Diana[n][m];
    return 0;
}
