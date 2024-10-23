#include <fstream>

using namespace std;
ifstream cin("easyocr.in");
ofstream cout("easyocr.out");
const int di[]={-1,-1,0,1,1,1,0,-1},dj[]={0,1,1,1,0,-1,-1,-1};
bool a[1005][1005];
int v[11];
int n,m;
int verificare(int i,int j)
{
    if(a[i][j+1]==1&&a[i+1][j]==1&&a[i+3][j+3]==0)return 0;
    else if(a[i+1][j-1]==1)return 1;
    else if(a[i][j+1]==1&&a[i+1][j]==0&&a[i+4][j]==1)return 2;
    else if(a[i][j+1]==1&&a[i+1][j]==0&&a[i+4][j]==0&&a[i+4][j+2]==0)return 3;
    else if(a[i][j+1]==0&&a[i+1][j]==1)return 4;
    else if(a[i][j+1]==1&&a[i+1][j]==1&&a[i+1][j+4]==0&&a[i+4][j]==0)return 5;
    else if(a[i][j+1]==1&&a[i+1][j]==1&&a[i+3][j+3]==1&&a[i+1][j+4]==0)return 6;
    else if(a[i+4][j+2]==1)return 7;
    else if(a[i][j+1]==1&&a[i+1][j]==1&&a[i+1][j+4]==1&&a[i+3][j+1]==1&&a[i+4][j]==1)return 8;
    else if(a[i][j+1]==1&&a[i+1][j]==1&&a[i+1][j+4]==1&&a[i+3][j+1]==1&&a[i+4][j]==0)return 9;
}
void Fill(int i,int j)
{
    if(i>=0&&i<n&&j>=0&&j<m&&a[i][j]==1)
    {
        a[i][j]=0;
        for(int k=0;k<8;k++)Fill(i+di[k],j+dj[k]);
    }
}
int main()
{
    int i,j,k,l,cnt=0;
    char x;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>x;
            a[i][j]=x-'0';
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==1)
            {
                v[verificare(i,j)]++;
                cnt++;
                Fill(i,j);
            }
        }
    }
    cout<<cnt<<endl;
    for(i=0;i<=9;i++)
    {
        if(v[i]!=0)cout<<i<<" "<<v[i]<<" ";
    }
    return 0;
}
