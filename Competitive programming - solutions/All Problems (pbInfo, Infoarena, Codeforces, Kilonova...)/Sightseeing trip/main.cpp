#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int Inf = 0x3f3f3f3f;
using PI = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VPI = vector<PI>;
using VVPI = vector<VPI>;

int n,m,ans = Inf;
VVI sirad;
VI dist,v;

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

        for(int i=1;i<=n;++i)
        {
            if(dist[i] > dist[x] + sirad[x][i])
            {
                dist[i] = dist[x] + sirad[x][i];
                q.emplace(dist[i],i);
            }
        }
    }
}
int main()
{
    int x,y,c;
    cin>>n>>m;
    sirad = VVI(n+1,VI(n+1,Inf));
    while(m--)
    {
        cin>>x>>y>>c;
        sirad[x][y] = sirad[y][x] = c;
    }
    for(int i=1;i<=n;++i)
    {
        dist = VI(n+1,Inf);
        Dijkstra(i);
        for(int j=1;j<=n;++j)
        {
            dist[j] = dist[j] + sirad[j][i];
            if(i!=j&&dist[j]<ans)
            {
                ans = dist[j];
                v = dist;
            }
        }
    }
    return 0;
}
