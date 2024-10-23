#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("distante.in");
ofstream cout("distante.out");

const int Inf = 0x3f3f3f3f;
using PI = pair<int,int>;
using VI = vector<int>;
using VPI = vector<PI>;
using VVPI = vector<VPI>;
int t,n,m,s;
VVPI sirad;
VI dist,d;

bool Dijkstra(int x)
{
    priority_queue<PI,VPI,greater<PI>>q;
    q.emplace(0,x);
    d[x] = 0;
    while(!q.empty())
    {
        int dx = q.top().first,
        x = q.top().second;
        q.pop();

        if(dx > d[x])continue;

        for(auto i : sirad[x])
        {
            int y = i.first,
            w = i.second;
            if(d[y] > d[x] + w)
            {
                d[y] = d[x] + w;
                if(dist[y] > d[y])return 0;
                q.emplace(d[y],y);
            }
        }
    }
    return 1;
}
int main()
{
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>n>>m>>s;
        sirad = VVPI(n+1);
        dist = d = VI(n+1,Inf);
        for(int i=1;i<=n;++i)
            cin>>dist[i];
        while(m--)
        {
            cin>>a>>b>>c;
            sirad[a].emplace_back(b,c);
            sirad[b].emplace_back(a,c);
        }
        if(dist[s] != 0)cout<<"NU\n";
        else if(Dijkstra(s))cout<<"DA\n";
        else cout<<"NU\n";
    }
    return 0;
}
