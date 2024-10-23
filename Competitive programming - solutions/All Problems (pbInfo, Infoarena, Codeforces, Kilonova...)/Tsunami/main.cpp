#include <fstream>
#include <vector>
#include <queue>
#define Nmax 1005
using namespace std;
ifstream cin("tsunami.in");
ofstream cout("tsunami.out");
const int di[]={-1,0,1,0},dj[]={0,1,0,-1};
int m,n,h,cnt=0;
vector<vector<int> > v;
queue<pair<int,int>>q;
int main()
{
    int i,j,x;
    cin>>n>>m>>h;
    vector<int>a;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>x;
            a.push_back(x);
        }
        v.push_back(a);
        a.clear();
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(v[i][j])
            {
                int ok=0;
                for(int k=0;k<4;k++)
                {
                    if(i+di[k]>=0&&j+dj[k]>=0&&i+di[k]<n&&j+dj[k]<m)
                    {
                        if(v[i+di[k]][j+dj[k]]==0)ok=1;
                    }
                }
                if(ok==1)q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        if(v[x][y]!=0)
        {
            if(v[x][y]<h)
            {
            v[x][y]=0;
            cnt++;
            for(int k=0;k<4;k++)
            {
                if(x+di[k]>=0&&y+dj[k]>=0&&x+di[k]<n&&y+dj[k]<m)
                {
                    if(v[x+di[k]][y+dj[k]]>0)
                    {
                        q.push(make_pair(x+di[k],y+dj[k]));
                    }
                }
            }
            }
        }
        q.pop();
    }
    cout<<cnt;
    return 0;
}
