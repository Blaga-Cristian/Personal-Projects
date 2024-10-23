#include <fstream>
#include <vector>
using namespace std;
ifstream cin("parcela.in");
ofstream cout("parcela.out");
vector<vector<bool> > v;
const int di[]={-1,0,1,0},dj[]={0,1,0,-1};
int n,s,m;
void Fill(int i,int j)
{
    if(i>=0&&i<n&&j>=0&&j<m&&v[i][j]==1)
    {
        v[i][j]=0;
        s++;
        for(int k=0;k<4;k++)Fill(i+di[k],j+dj[k]);
    }
}
int main()
{
    int i,j,cnt=0,max=-1,nr=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        vector<bool>a;
        for(j=0;j<m;j++)
        {
            bool b;
            cin>>b;
            a.push_back(b);
        }
        v.push_back(a);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(v[i][j]==1)
            {
                s=0;
                Fill(i,j);
                cnt++;
                if(s>max)
                {
                    max=s;
                    nr=cnt;
                }
            }
        }
    }
    cout<<cnt<<" "<<max<<" "<<nr;
    return 0;
}
