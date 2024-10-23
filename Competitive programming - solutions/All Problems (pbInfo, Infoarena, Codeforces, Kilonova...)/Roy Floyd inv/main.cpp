#include <fstream>

using namespace std;
ifstream cin("rfinv.in");
ofstream cout("rfinv.out");
const int T = 33,N = 54,Inf = 0x3f3f3f3f;
int n,t,m,x,y,mat[N][N],rf[N][N];
void solver()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
    {
        mat[i][j] = rf[i][j] = 0;
        if(i!=j)mat[i][j] = Inf;
    }
    while(m--)
    {
        cin>>x>>y;
        mat[x][y] = mat[y][x] = 1;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
    {
        cin>>rf[i][j];
        if(mat[i][j]==1)mat[i][j] = rf[i][j];
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                mat[i][j] = min(mat[i][j],mat[i][k] + mat[k][j]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(mat[i][j] != rf[i][j])
    {
        cout<<"NU\n";
        return;
    }
    cout<<"DA\n";
}
int main()
{
    cin>>t;
    while(t--)
        solver();
    return 0;
}
