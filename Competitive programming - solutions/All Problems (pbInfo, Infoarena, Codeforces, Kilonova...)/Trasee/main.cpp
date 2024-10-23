#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
ifstream cin("trasee.in");
ofstream cout("trasee.out");
using pi = pair<int,int>;
const int N = 206;
int n,m,x,k,C[N][N],t[N],d[N],a,b;
vector<vector<int>> G;
bitset<N> v;

void Bfs(int source)
{
    queue<int> q;
    v.reset();
    v[source] = true;
    d[source] = 1;
    q.push(source);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto y : G[x])
            if(!v[y])
            {
                v[y] = true;
                d[y] = d[x] + 1;
                q.push(y);
            }
    }
}

int BFS(int source)
{
    queue<pair<int,pi>> q;
    v.reset();
    v[source] = true;
    q.push({source,{1,1}});

    while(!q.empty())
    {
        int x = q.front().first,
        dx = q.front().second.first,
        ln = q.front().second.second;
        q.pop();

        if(ln == k)return x;

        for(auto y : G[x])
            if(C[x][y] && !v[y] && d[y] == dx + 1)
            {
                v[y] = true;
                t[y] = x;
                q.push({y,{dx + 1,ln+1}});
            }
    }

    return 0;
}

void Augment(int source,int sink)
{
    for(int i = sink; i != source; i = t[i])
    {
        C[t[i]][i]--;
        C[i][t[i]]++;
    }
}

int MaxFlow(int source)
{
    int F = 0;
    int g;
    for(;true;++F,Augment(source,g))
    {
        g = BFS(source);
        if(!g)break;
    }
    return F;
}
int main()
{
    cin>>n>>m>>x>>k;
    G = vector<vector<int>>(n+1);
    while(m--)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        C[a][b] = C[b][a] = 1;
    }
    Bfs(x);

    cout<<MaxFlow(x);
    return 0;
}
