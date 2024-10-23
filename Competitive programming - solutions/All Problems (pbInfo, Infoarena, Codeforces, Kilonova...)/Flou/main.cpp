#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
ifstream cin("maxflow.in");
ofstream cout("maxflow.out");
const int N = 1009,Inf = 0x3f3f3f3f;
int n,m,a,b,c,C[N][N],t[N];
vector<vector<int>> G;
queue<int> q;
bitset<N> v;

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
    while(Bf(source,sink))
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
    G = vector<vector<int>>(n+1);
    while(m--)
    {
        cin>>a>>b>>c;
        G[a].push_back(b);
        G[b].push_back(a);
        C[a][b] += c;
    }

    cout<< MaxFlow(1,n);
    return 0;
}
