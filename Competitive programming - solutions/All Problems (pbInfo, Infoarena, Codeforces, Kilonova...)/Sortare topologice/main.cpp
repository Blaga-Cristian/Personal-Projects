#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("topsort.in");
ofstream cout("topsort.out");

vector<vector<int> >sir;
vector<bool> viz;
vector<int> deg;
int Q[100005];
int n,m;
inline void solve()
{
    int x;
    for(int i=1;i<=n;++i)
        if(deg[i]==0)Q[++Q[0]]=i;
    for(int i=1;i<=n;++i)
    {
        x = Q[i];
        for(auto i:sir[x])
        {
            deg[i]--;
            if(deg[i]==0)Q[++Q[0]]=i;
        }
    }
}
void Bfs(int x)
{
    queue<int> q;
    q.emplace(x);
    viz[x] = true;
    while(!q.empty())
    {
        x = q.front();
        q.pop();

        for(auto i : sir[x])
        {
            if(viz[x])continue;
            viz[x] = true;
            q.emplace(i);
        }
    }
}
int main()
{
    int a,b;
    cin>>n>>m;
    sir = vector<vector<int> >(n+1);
    //viz.resize(n+1,false);
    deg = vector<int> (n+1);
    while(m--)
    {
        cin>>a>>b;
        sir[a].emplace_back(b);
        deg[b]++;
    }
    //Bfs(1);
    solve();
    for(int i=1;i<=n;++i)cout<<Q[i]<<' ';
    return 0;
}
