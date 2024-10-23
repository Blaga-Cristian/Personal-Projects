#include <fstream>
#include <vector>

using namespace std;
ifstream cin("smallworld.in");
ofstream cout("smallworld.out");
const int N = 1e5 + 9;
int n,a,b;
vector<vector<int>> G;
int path[N],spath[N];
int up[N];
int dep[N];

void Dfs1(int x,int p)
{
    for(auto y : G[x])
    {
        if(y == p)continue;

        Dfs1(y,x);

        if(path[x] < path[y] + 1)
            spath[x] = path[x],path[x] = path[y] + 1;
        else if(spath[x] < path[y] + 1)
            spath[x] = path[y] + 1;
    }
}

void Dfs2(int x,int p)
{
    for(auto y : G[x])
    {
        if(y == p)continue;

        up[y] = up[x] + 1;
        if(path[y] + 1 == path[x])
            up[y] = max(up[y],spath[x] + 1);
        else
            up[y] = max(up[y],path[x] + 1);

        Dfs2(y,x);
    }
}

int main()
{
    cin>>n;
    G = vector<vector<int>>(n+1);
    for(int i = 1;i < n; ++i)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Dfs1(1,0);
    Dfs2(1,0);

    for(int i = 1; i <= n; ++i)
        cout<<max(up[i],path[i])<<'\n';
    return 0;
}
