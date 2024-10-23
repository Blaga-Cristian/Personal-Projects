#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("parc.in");
ofstream cout("parc.out");

const int Inf = 0x3f3f3f3f;
vector<vector<pair<int,int> > >v;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
vector<int> D,t;
int n,m,c;
int ind;
void Dijkstra()
{
    int dx,x;
    while(!q.empty())
    {
        dx = q.top().first;
        x = q.top().second;
        q.pop();

        if(D[x]<dx)continue;

        for(auto p:v[x])
        {
            int y = p.first;
            int w = p.second;
            if(D[y]>D[x]+w)
            {
                t[y] = t[x];
                D[y] = D[x]+w;
                q.emplace(D[y],y);
            }
        }
    }
}
int main()
{
    int a,b,w,p,x;
    cin>>n>>m>>c;
    v = vector<vector<pair<int,int> > >(n+1);
    t = vector<int>(n+1);
    D = vector<int>(n+1,Inf);
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>w;
        v[a].emplace_back(b,w);
        v[b].emplace_back(a,w);
    }
    cin>>p;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        D[x]=0;
        t[x]=x;
        q.emplace(0,x);
    }
    Dijkstra();
    cout<<t[c];
    return 0;
}
