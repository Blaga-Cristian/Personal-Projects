#include <fstream>
#include <vector>
using namespace std;
ifstream cin("grupuri.in");
ofstream cout("grupuri.out");
vector<vector<bool> > v;
const int di[]={-1,0,1,0},dj[]={0,1,0,-1};
int n;
void Fill(int i,int j)
{
    if(i>=0&&i<n&&j>=0&&j<n&&v[i][j]==1)
    {
        v[i][j]=0;
        for(int k=0;k<4;k++)Fill(i+di[k],j+dj[k]);
    }
}
int main()
{
    int i,j,cnt=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        vector<bool>a;
        for(j=0;j<n;j++)
        {
            bool b;
            cin>>b;
            a.push_back(b);
        }
        v.push_back(a);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(v[i][j]==1)
            {
                Fill(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
