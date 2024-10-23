#include <fstream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
ifstream cin("genius.in");
ofstream cout("genius.out");
const ll Inf = 1LL<<60;
ll n,m,a,b,c,x,y,cnt,node,k,p,mx;
vector<vector<ll>> sirad;
vector<ll> dist;
void Bfs()
{
    queue<ll> q;
    q.push(k);
    dist[k] = 0;
    while(!q.empty())
    {
        ll x = q.front();
        q.pop();

        for(auto i : sirad[x])
            if(dist[i] > dist[x] + 1)
            {
                dist[i] = dist[x] + 1;
                mx = max(mx,dist[i]);
                q.push(i);
            }
    }
}
int main()
{
    cin>>n>>m;
    sirad = vector<vector<ll>>(n+1);
    dist = vector<ll>(n+1,Inf);
    while(m--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
        sirad[b].push_back(a);
    }

    cin>>k>>p;

    Bfs();

    for(int i=1;i<=n;++i)
    {
        if(dist[i] == Inf)
        {
            cout<<"-1";
            return 0;
        }
    }
    cout<<mx+p;
    return 0;
}
