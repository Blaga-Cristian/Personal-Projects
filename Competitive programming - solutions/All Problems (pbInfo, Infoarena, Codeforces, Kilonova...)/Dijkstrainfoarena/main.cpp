#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("dijkstra.in");
ofstream cout("dijkstra.out");
const int Inf = 0x3f3f3f3f;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
using VVPI = vector<VPI>;

int n,m;
VVPI sirad;
VI dist;

void Dijkstra(int x)
{
    priority_queue< PI, vector<PI>, greater<PI> > q;
    q.emplace(0,x);
    dist[x] = 0;
    while(!q.empty())
    {
        int dx = q.top().first,
        x = q.top().second;
        q.pop();

        if(dx > dist[x])continue;

        for(auto nod : sirad[x])
        {
            int y = nod.first,
            w = nod.second;
            if(dist[y] > dist[x] + w)
            {
                dist[y] = dist[x] + w;
                q.emplace(dist[y],y);
            }
        }
    }
}
int main()
{
    int x,y,c;
    cin>>n>>m;
    sirad = VVPI(n+1);
    dist = VI(n+1,Inf);
    while(m--)
    {
        cin>>x>>y>>c;
        sirad[x].emplace_back(y,c);
    }
    Dijkstra(1);
    for(int i =2; i<=n;++i)
        if(dist[i]==Inf)cout<<"0 ";
        else cout<<dist[i]<<' ';
    return 0;
}
