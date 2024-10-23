#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("dragoni.in");
ofstream cout("dragoni.out");
const int N = 809,Inf = 0x3f3f3f3f;
int p,n,m,a,b,d;
int dist[N][N];/// dist[i][j] = dist minima necesare pentru a ajunge la punctul j cudragonul i
int dmax[N];
vector<vector<pair<int,int> >> sirad;
void solve1(),solve2();
int main()
{
    cin>>p;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dist[i][j] = Inf;
    sirad = vector<vector<pair<int,int> >> (n+1);
    for(int i=1;i<=n;++i)
        cin>>dmax[i];
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>d;
        sirad[a].emplace_back(b,d);
        sirad[b].emplace_back(a,d);
    }
    if(p==1)solve1();
    else solve2();
    return 0;
}
void solve1()
{
    queue<int> q;
    vector<bool> viz(n+1);
    q.push(1);
    int mx = dmax[1];
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(viz[x]==1)continue;
        viz[x] = 1;

        for(auto i : sirad[x])
        {
            int y = i.first,
            w = i.second;
            if(dmax[1] >= w && !viz[y])
            {
                mx = max(mx,dmax[y]);
                q.push(y);
            }
        }
    }
    cout<<mx;
}
void solve2()
{
    queue<pair<int,int> > q;
    q.emplace(1,1);
    dist[1][1] = 0;
    while(!q.empty())
    {
        int tip = q.front().first,
        nod = q.front().second;
        q.pop();

        for(auto i : sirad[nod])
        {
            int x = i.first,
            w = i.second;

            if(dmax[tip] >= w && dist[tip][x] > dist[tip][nod] + w)
            {
                dist[tip][x] = dist[tip][nod] + w;
                q.emplace(tip,x);
            }
            if(dmax[nod] >= w && dist[nod][x] > dist[tip][nod] + w)
            {
                dist[nod][x] = dist[tip][nod] + w;
                q.emplace(nod,x);
            }
        }
    }
    int ans = Inf;
    for(int i=1;i<=n;++i)
        ans = min(ans,dist[i][n]);
    cout<<ans;
}
