#include <fstream>
#include <vector>
using namespace std;
ifstream cin("zana.in");
ofstream cout("zana.out");
int v[200][200];
const int di[]={-1,0,1,0},dj[]={0,1,0,-1};
int m,n,k,maxi=-9,cnt=0;
void Fill(int i,int j)
{
    if(i>=0&&i<n&&j>=0&&j<m&&v[i][j]!=-1)
    {
        if(v[i][j]==0)
        {
            v[i][j]=-1;
            for(int k=0;k<4;k++)Fill(i+di[k],j+dj[k]);
        }
        else
        {
            if(v[i][j]>maxi)
            {
                cnt=1;
                maxi=v[i][j];
            }
            else if(v[i][j]==maxi)cnt++;
            v[i][j]=-1;
        }
    }
}
int main()
{
    int i,j,x,y;
    cin>>n>>m>>k;
    for(i=0;i<k;i++)
    {
        cin>>x>>y;
        v[x-1][y-1]++;
    }
    Fill(0,0);
    cout<<maxi<<endl<<cnt;
    return 0;
}
