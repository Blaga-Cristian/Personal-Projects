#include <fstream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
ifstream cin("dijkstra2.in");
ofstream cout("dijkstra2.out");

using PI = pair<int,int>;
const int Inf  = 0x3f3f3f3f;
vector<PI > c[100005];
int d[100005];
int n,m,p;
void ReadGraph();
void Dijkstra(int x);
void Write();
int main()
{
    ReadGraph();
    Dijkstra(p);
    Write();
    return 0;
}
inline void ReadGraph()
{
    int a,b,val;
    cin>>n>>m>>p;
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>val;
        c[a].push_back({b,val});
        c[b].push_back({a,val});
    }
    for(int i=1;i<=n;++i)d[i] = Inf;
}
inline void Dijkstra(int x)
{
    priority_queue<PI, vector<PI>,greater<PI> > q;
    d[x]=0;
    q.push({0,x});
    while(!q.empty())
    {
        PI mini = q.top();
        q.pop();
        if(mini.first>d[mini.second])continue;
        for(auto i:c[mini.second])
        {
            if( d[i.first] > mini.first + i.second)
            {
                d[i.first] = mini.first + i.second;
                q.push({d[i.first],i.first});
            }
        }
    }
}
inline void Write()
{
    for(int i=1;i<=n;++i)
    {
        if(d[i]==Inf)cout<<-1<<' ';
        else cout<<d[i]<<' ';
    }
}
