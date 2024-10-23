#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <cstring>
using namespace std;
ifstream cin("fmcm.in");
ofstream cout("fmcm.out");

const int N = 359,Inf = 0x3f3f3f3f;
using pi = pair<int,int>;
int n,m,S,D,a,b,c,z,FCst;
vector<vector<int>> G;
bitset<N> in_queue;
int C[N][N],t[N],cst[N][N],old_d[N],d[N],real_d[N];
int ans = 0;

void Bellman(int source)
{
    in_queue.reset();
    memset(old_d,Inf,sizeof(old_d));
    queue<int> q;
    q.push(source);
    in_queue[source] = true;
    old_d[source] = 0;

    while(!q.empty())
    {
        int x = q.front();
        in_queue[x] = false;
        q.pop();

        for(auto y : G[x])
            if( C[x][y] )
            {
                if( old_d[y] <= old_d[x] + cst[x][y])continue;
                old_d[y] = old_d[x] + cst[x][y];
                if(!in_queue[y])continue;
                q.push(y);
                in_queue[y] = true;
            }
    }
}
bool Dijkstra(int source,int sink)
{
    memset(d,Inf,sizeof(d));
    priority_queue<pi,vector<pi>,greater<pi>>q;
    q.emplace(0,source);
    d[source] = 0;
    real_d[source] = 0;

    while(!q.empty())
    {
        int dx = q.top().first,
        x = q.top().second;
        q.pop();

        if(d[x] != dx)continue;

        for(auto y : G[x])
            if( C[x][y] )
            {
                int new_d = d[x] + cst[x][y] + old_d[x] - old_d[y];
                if(d[y] > new_d)
                {
                    d[y] = new_d;
                    real_d[y] = real_d[x] + cst[x][y];
                    t[y] = x;
                    q.emplace(d[y],y);
                }
            }
    }
    memcpy(old_d,real_d,sizeof(d));

    return (d[sink] != Inf);
}
void MaxFlow(int source,int sink)
{
    int fmin;
    while( Dijkstra(source,sink) )
    {
        fmin = Inf;
        for(int i = sink; i != source; i = t[i])
            fmin = min(fmin,C[t[i]][i]);

        FCst += fmin * real_d[D];
        for(int i = sink; i != source; i = t[i])
            C[t[i]][i] -= fmin,
            C[i][t[i]] += fmin;
    }
}
int main()
{
    cin>>n>>m>>S>>D;
    G = vector<vector<int>>(n+1);
    while(m--)
    {
        cin>>a>>b>>c>>z;
        G[a].push_back(b);
        G[b].push_back(a);
        cst[a][b] = z;
        cst[b][a] = -z;
        C[a][b] = c;
    }

    Bellman(S);
    MaxFlow(S,D);

    cout<<FCst;
    return 0;
}
