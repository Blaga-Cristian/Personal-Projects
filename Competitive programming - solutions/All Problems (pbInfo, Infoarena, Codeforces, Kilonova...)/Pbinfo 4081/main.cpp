#include <fstream>
using namespace std;
ifstream cin("alpinistii.in");
ofstream cout("alpinistii.out");
const int di[]={-1,0,0,1},dj[]={0,-1,1,0};
int a[201][201],n,m,k=0;
void Fill(int i,int j)
{
    if(i>=1&&i<=n&&j>=1&&j<=m&&a[i][j]==0)
    {
        a[i][j]=-1;
        for(i=0;i<4;i++)Fill(i+di[i],j+dj[j]);
    }
}
int main()
{
    int c,i,j;
    cin>>c>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    if(c==1)
    {
        int max=-1,s=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]==0)
                {
                    Fill(i,j);
                    for(i=1;i<=n;i++)
                    {
                    for(j=1;j<=m;j++)
                    {
                        if(a[i][j]==-1)k++;
                    }
                    }
                    if(s==0)s=k;
                    else s=k-s;
                    k=0;
                    cout<<s<<endl;
                }
            }
        }
        cout<<s;
    }
    return 0;
}
