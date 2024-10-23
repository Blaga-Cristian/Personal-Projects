#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("epidemie.in");
ofstream cout("epidemie.out");
vector<vector<int> >sirad;
queue <int> q;
int traseu[100];
int ans,maxi;
void bfs()
{
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(traseu[x]>maxi)maxi=traseu[x];
        for(auto i:sirad[x])
        {
            if(traseu[i]==0)
            {
                traseu[i]=traseu[x]+1;
                q.push(i);
            }
        }
    }
}
int main()
{
    int n,m,x,y,k;
    cin>>n>>m;
    sirad = vector<vector<int> >(n+1);
    for(int i=1;i<=m;++i)
    {
        cin>>x>>y;
        sirad[x].push_back(y);
        sirad[y].push_back(x);
    }
    cin>>k;
    for(int i=1;i<=k;++i)
    {
        cin>>x;
        traseu[x]=1;
        q.push(x);
    }
    bfs();
    cout<<maxi;
    return 0;
}
