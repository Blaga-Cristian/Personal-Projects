#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
ifstream cin("critice.in");
ofstream cout("critice.out");
using pi = pair<int,int>;
using ppi = pair<int,pi>;
const int N = 1009, Inf = 0x3f3f3f3f;
int n,m,a,b,z;
int t[N],C[N][N],F[N][N];
vector<vector<pi>> G;
bitset<N> v;
queue<int> q;
vector<int> ans;
int dist[N];

bool Bf(int source,int sink)
{
    v.reset();
    v[source] = 1;
    q.push(source);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(x == sink)continue;

        for(auto aux : G[x])
        {
            int y = aux.first;
            if(!v[y] && C[x][y] > 0)
            {
                v[y] = 1;
                t[y] = x;
                q.push(y);
            }
        }
    }

    return v[sink];
}
void MaxFlow(int source,int sink)
{
    int fmin;
    while( Bf(source, sink) )
        for(auto aux : G[sink])
        {
            int x = aux.first;

            if(!v[x] || C[x][sink] <= 0)continue;

            t[sink] = x;
            fmin = Inf;
            for(int i = sink; i != source; i = t[i])
                fmin = min(fmin, C[t[i]][i]);

            if(!fmin)continue;

            for(int i = sink; i != source; i = t[i])
            {
                C[t[i]][i] -= fmin;
                C[i][t[i]] += fmin;
            }
        }
}

void Verif()
{
    for(int i = 1; i <= n; ++i)
        dist[i] = Inf;
    q.push(1);
    dist[1] = 0;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto aux : G[x])
        {
            int y = aux.first;
            if(dist[y] != Inf)continue;
            if(C[x][y] == 0)continue;
            dist[y] = dist[x] + 1;
            q.push(y);
        }
    }
}
int main()
{
    cin>>n>>m;
    G = vector<vector<pi>>(n+1);
    for(int i = 1; i <= m; ++i)
    {
        cin>>a>>b>>z;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
        C[a][b] += z;
        C[b][a] += z;
        F[a][b] = F[b][a] = z;
    }

    MaxFlow(1,n);

    Verif();
    for(int i = 1; i <= n; ++i)
    {
        if(dist[i] == Inf)continue;
        for(auto aux : G[i])
        {
            int y = aux.first;
            if(dist[y] != Inf)continue;
            if(F[i][y] == 0)continue;
            ans.push_back(aux.second);
        }
    }

    cout<<ans.size()<<'\n';
    for(auto i : ans)
        cout<<i<<'\n';
    return 0;
}
