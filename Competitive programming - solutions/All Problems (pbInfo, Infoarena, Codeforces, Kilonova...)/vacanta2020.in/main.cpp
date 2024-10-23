#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("vacanta2020.in");
ofstream cout("vacanta2020.out");
using PI  = pair<int, int>;
const int Inf = 0x3f3f3f3f;
vector<vector<pair<int,int> > >c;
int d[35009][11];
vector<PI>t;
int n,m,k;
void Dijkstra()
{
    priority_queue<pair<int,pair<int,int> >, vector< pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> >>> q;
    q.push({0,{1,0}});
    for(int i=1;i<=n;++i)
        for(int j=0;j<=k;++j)d[i][j] = Inf;
    d[1][0] = 0;
    int dx,x,y,w,nod,nr_tick;
    while(!q.empty())
    {
        dx = q.top().first;
        x = q.top().second.first;
        nr_tick = q.top().second.second;
        q.pop();

        if(d[x][nr_tick]<dx)continue;

        for(auto i:c[x])
        {
            y = i.first;
            w = i.second;
            if(d[y][nr_tick] > d[x][nr_tick] + w)
            {
                d[y][nr_tick] = d[x][nr_tick]+w;
                q.push({d[y][nr_tick],{y,nr_tick}});
            }
            if(nr_tick<k)
            {
                if(d[y][nr_tick+1]>d[x][nr_tick])
                {
                    d[y][nr_tick+1] = d[x][nr_tick];
                    q.push({d[y][nr_tick+1],{y,nr_tick+1}});
                }
            }
        }
    }
}
int main()
{
    int u,v,w;
    cin>>n>>m>>k;
    c = vector<vector<pair<int,int> > >(n+1);
    t = vector<PI> (n+1);
    t[1].first = t[1].second = 0;
    for(int i=1;i<=m;++i)
    {
        cin>>u>>v>>w;
        c[u].emplace_back(v,w);
        c[v].emplace_back(u,w);
    }
    Dijkstra();
    int mini;
    for(int i=1;i<=n;++i)
    {
        mini = 2147483647;
        for(int j=0;j<=k;++j)mini = min(mini,d[i][j]);
        cout<<mini<<' ';
    }
    return 0;
}
