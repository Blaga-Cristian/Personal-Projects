#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
ifstream cin("lca.in");
ofstream cout("lca.out");
const int N = 100009;

int n,m,t,a,b,x,y;
vector<vector<int>> sirad;
int tour[2*N],dep[N],first[N],st[2*N][20];
int idx;
void Dfs(int x,int p)
{
    tour[++idx] = x;
    first[x] = idx;
    dep[x] = dep[p] + 1;
    for(auto i : sirad[x])
    {
        if(i == p)return;
        Dfs(i,x);
        tour[++idx] = x;
    }
}
void Process()
{
    for(int i = 1; i <= idx; ++i)
        st[i][0] = tour[i];

    for(int k = 1; 1 << k <= idx; ++k)
        for(int i = 1; i + (1<<k) <= idx; ++i)
            if(dep[st[i][k-1]] < dep[st[i + (1<<(k-1))][k-1]])
                st[i][k] = st[i][k-1];
            else
                st[i][k] = st[i + (1<<(k-1))][k-1];
}
int lca(int x,int y)
{
    x = first[x];
    y = first[y];
    if(x > y)
        swap(x,y);
    int k = log2(y - x + 1);
    return (dep[st[x][k]] < dep[st[y - (1<<k) + 1][k]]) ? st[x][k] : st[y - (1<<k) + 1][k];
}
int main()
{
    cin>>n>>m;
    sirad = vector<vector<int>>(n+1);
    for(int i=2;i<=n;++i)
    {
        cin>>t;
        sirad[t].push_back(i);
    }

    Dfs(1,0);
    Process();

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<'\n';
    }
    return 0;
}
