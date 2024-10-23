#include <iostream>
#include <queue>
#include <tuple>
#define maxi 2147483647
using namespace std;
int n,x,y,z,t,v[1502][1502], cost[1502][1502];
const int di[]={-1,0,1,0},dj[]={0,1,0,-1};
using Trei = tuple<int,int,int>;
priority_queue<Trei,vector<Trei>,greater<Trei> > q;
bool verif(int a,int b)
{
    return a>=1&&a<=n&&b>=1&&b<=n;
}
void Lee(int i, int j)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cost[i][j]=maxi;
        }
    }
    cost[1][1]=v[1][1];
    q.push(make_tuple(v[1][1],1,1));
    while(!q.empty())
    {
        int val,x,y;
        tie(val,x,y)=q.top();
        q.pop();
        for(int k=0;k<4;k++)
        {
            int ii=x+di[k];
            int jj=y+dj[k];
            if(verif(ii,jj)&&cost[x][y]+v[ii][jj]<cost[ii][jj])
            {
                cost[ii][jj]=cost[x][y]+v[ii][jj];
                q.push((make_tuple(cost[ii][jj],ii,jj)));
            }
        }
    }
}
int main()
{
    int i,j;
    cin>>n>>x>>y>>z>>t;
    for(i=1;i<=n;i++)cin>>v[1][i];
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            v[i][j]=1 + (v[i-1][j-1] * x + v[i-1][j] *y + v[i-1][j+1] * z) % t;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    Lee(1,1);
    cout<<cost[n][n];
    return 0;
}
