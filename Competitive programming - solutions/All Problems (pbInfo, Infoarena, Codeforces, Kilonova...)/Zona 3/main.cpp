#include <fstream>
#include <vector>
using namespace std;
ifstream cin("zona3.in");
ofstream cout("zona3.out");
vector<vector<int> > v;
const int di[]={-1,0,1,0},dj[]={0,1,0,-1};
int n,cnt=0,m;
void Fill(int i,int j,int val)
{
    if(i>=0&&i<n&&j>=0&&j<m&&v[i][j]!=0&&v[i][j]!=val)
    {
        cnt++;
        v[i][j]=val;
        for(int k=0;k<4;k++)Fill(i+di[k],j+dj[k],val);
    }
}
int main()
{
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        vector<int>a;
        for(j=0;j<m;j++)
        {
            int b;
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
                cnt=0;
                Fill(i,j,2);
                Fill(i,j,cnt);
            }
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
