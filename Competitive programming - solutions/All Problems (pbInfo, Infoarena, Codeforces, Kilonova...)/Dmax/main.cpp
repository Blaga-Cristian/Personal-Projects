#include <fstream>

using namespace std;
ifstream cin("dmax.in");
ofstream cout("dmax.out");
int matad[105][105];
int ans,maxi;
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>x>>y;
        matad[x][y]= matad[y][x]=1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(matad[i][j]==0)matad[i][j]=9999999;
        }
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(matad[i][j]>matad[i][k]+matad[k][j])matad[i][j]=matad[i][k]+matad[k][j];
    for(int i=2;i<=n;++i)
    {
        if(matad[1][i]>maxi&&matad[1][i]!=9999999)
        {
            maxi=matad[1][i];
            ans = i;
        }
    }
    cout<<ans;
    return 0;
}
