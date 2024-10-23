#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <bitset>
#define MAX_M    2001
#define MAX_COST 301
using namespace std;
ifstream cin("furtuna.in");
ofstream cout("furtuna.out");
const int N = 409, Inf = 0x3f3f3f3f;
using pi = pair<int,int>;
int n,m,T,C,t[N],cap[N][N],a,b,c,x,p,tur[N],S,D;
int cab[N],nr[N],f[N][N],Q[N];
vector<vector<pi>> G;
priority_queue<pi,vector<pi>,greater<pi>>q;
int d[N],dist[201][201],s[201];

void Dijkstra(int x)
{
    memset(d,Inf,sizeof(d));
    d[x] = 0;
    q.emplace(0,x);

    while(!q.empty())
    {
        int dx = q.top().first,
        x = q.top().second;
        q.pop();

        if(dx > d[x])continue;

        for(auto i : G[x])
        {
            int y = i.first,
            w = i.second;
            if(d[y] < d[x] + w)continue;
            d[y] = d[x] + w;
            t[y] = x;
            q.emplace(d[y],y);
        }
    }
}

bool Bfs()
{
    int i,j, h = 0, tr = 0;
    Q[h] = S;
    for(int i = 0; i <= T + C + 1; ++i)
        t[s[i]] = -1;
    while(h <= tr)
    {
        for(int i = Q[h++], j = 0; j <= T + C + 1; ++j)
            if(t[s[j]] == -1 && cap[i][s[j]] > f[i][s[j]])
            {
                Q[++tr] = s[j];
                t[s[j]] = i;
                if(s[j] == D) return true;
            }
    }

    return false;
}

int MaxFlow(int timp)
{
    int flow;
    for(int i = 1; i <= T; ++i)
        for(int j = 1; j <= C; ++j)
            cap[tur[i]][cab[j]] = (dist[tur[i]][cab[j]] <= timp) ? 1 : 0;

    memset(f,0,sizeof(f));
    for(flow = 0; Bfs(); flow++)
        for(int i = D; i != S; i = t[i])
            f[t[i]][i] ++, f[i][t[i]] --;

    return flow;
}

int Solve()
{
    int Tmin;
    int Tmax = MAX_COST * MAX_M;
    int l = 1, r = Tmax, m;
    while(l <= r)
    {
        m = (l+r)/2;
        int Fl = MaxFlow(m);

        if(Fl == T)
            Tmin = m, r = m-1;
        else
            l = m + 1;
    }
    return Tmin;
}

int main()
{
    cin>>n>>m>>T>>C;
    G = vector<vector<pi>>(n+2);
    for(int i = 1; i <= m; ++i)
    {
        cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    for(int i = 1; i <= T; ++i)
        cin>>tur[i];
    for(int i = 1; i <= C; ++i)
        cin>>cab[i]>>nr[i];

    for(int i = 1; i <= T; ++i)
        s[i] = tur[i];
    for(int j = 1; j <= C; ++j)
        s[T+j] = cab[j];

    for(int i = 1; i <= T; ++i)
    {
        Dijkstra(tur[i]);
        for(int j = 1; j <= C; ++j)
            dist[i][T+j] = d[cab[j]];
    }

    S = 0, D = n + 1;
    for(int i = 1; i <= T; ++i)
        cap[S][tur[i]] = 1;
    for(int i = 1; i <= C; ++i)
        cap[cab[i]][D] = nr[i];

    s[0] = S,s[T+C+1] = D;

    cout<<Solve();
    return 0;
}
