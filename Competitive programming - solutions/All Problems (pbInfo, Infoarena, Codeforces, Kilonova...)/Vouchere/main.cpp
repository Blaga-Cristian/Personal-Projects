#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("vacanta2020.in");
ofstream cout("vacanta2020.out");
const int Inf = 0x3f3f3f3f;
int n,m,k;
vector<vector<pair<int,int> > > sirad;
vector<vector<int> > d;

void Dijkstra()
{
    priority_queue < pair<int,pair<int,int> >, vector<pair<int,pair<int,int> >>, greater<pair<int,pair<int,int> >>>q;
    for(int i=0;i<=k;++i)
        d[i][1]=0;
    q.push({d[0][1],{1,0}});
    while(!q.empty())
    {
        int dx = q.top().first,
        x = q.top().second.first,
        curr = q.top().second.second;
        q.pop();

        if(d[curr][x]<dx)continue;

        for(auto i:sirad[x])
        {
            int y = i.first, w = i.second;
            if(d[curr][y]>d[curr][x]+w)
            {
                d[curr][y] = d[curr][x] + w;
                q.push({d[curr][y],{y,curr}});
            }
            if(curr<k&&d[curr+1][y]>d[curr][x])
            {
                d[curr+1][y] = d[curr][x];
                q.push({d[curr+1][y],{y,curr+1}});
            }
        }
    }
}
int main()
{
    int a,b,c;
    cin>>n>>m>>k;
    sirad = vector<vector<pair<int,int>> >(n+1);
    d = vector<vector<int> >(k+1,vector<int>(n+1,Inf));
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>c;
        sirad[a].emplace_back(b,c);
        sirad[b].emplace_back(a,c);
    }
    Dijkstra();
    for(int i=1;i<=n;++i)
    {
        int mini = Inf;
        for(int j=0;j<=k;++j)
            mini = min(mini,d[j][i]);
        cout<<mini<<' ';
    }
    return 0;
}
