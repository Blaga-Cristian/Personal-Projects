#include <fstream>
#include <bitset>
#include <queue>
#include <vector>
using namespace std;
ifstream cin("drumuri2.in");
ofstream cout("drumuri2.out");
const int N = 109,Inf = 0x3f3f3f3f;
int n,m,a,b,in[N],out[N],C[N][N],t[N];
bitset<N> v;
vector<vector<int>> G;
queue<int> q;

bool Bf(int source,int sink)
{
    v.reset();
    v[source] = 1;
    q.push(source);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto y : G[x])
            if(!v[y] && C[x][y] > 0)
            {
                v[y] = 1;
                t[y] = x;
                q.push(y);
            }
    }

    return v[sink];
}

int MaxFlow(int source,int sink)
{
    int maxflow = 0, fmin;
    while( Bf(source,sink) )
        for(auto x : G[sink])
        {
            if(!v[x] || C[x][sink] <= 0)continue;

            t[sink] = x;
            fmin = Inf;
            for(int i = sink; i != source; i = t[i])
                fmin = min(fmin,C[t[i]][i]);

            if(!fmin)continue;

            for(int i = sink; i != source; i = t[i])
            {
                C[t[i]][i] -= fmin;
                C[i][t[i]] += fmin;
            }

            maxflow += fmin;
        }

    return maxflow;
}
int main()
{
    cin>>n>>m;
    G = vector<vector<int>>(n+4);
    while(m--)
    {
        cin>>a>>b;
        out[a]++;
        in[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
        C[a][b] += 1;
    }

    for(int i = 1; i <= n; ++i)
    {
        if(in[i] == 0)
        {
            G[0].push_back(i);
            G[i].push_back(0);
            C[0][i] = Inf;
        }
        if(out[i] == 0)
        {
            G[i].push_back(n+1);
            G[n+1].push_back(i);
            C[i][n+1] = Inf;
        }
    }

    cout<<MaxFlow(0,n+1);
    return 0;
}
