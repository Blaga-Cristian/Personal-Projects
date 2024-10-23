#include <fstream>
#include <vector>


using namespace std;
ifstream cin("lca.in");
ofstream cout("lca.out");
const int N = 1e5 + 9, LG = 18;
int n,m,x,a,b;
int t[N][LG],dep[N];
vector<vector<int>> G;

void Dfs(int x,int p)
{
    for(auto y : G[x])
    {
        if(y == p)continue;
        dep[y] = dep[x] + 1;
        Dfs(y,x);
    }
}

int get_lca(int a,int b)
{
    if(dep[a] < dep[b])
        swap(a,b);

    for(int i = LG - 1; i >= 0; --i)
        if(dep[a] - (1<<i) >= dep[b])
            a = t[a][i];


    if(a == b)return a;


    for(int i = LG - 1; i >= 0; --i)
        if(t[a][i] && t[a][i] != t[b][i])
        {
            a = t[a][i];
            b = t[b][i];
        }

    return t[a][0];
}

int main()
{
    cin>>n>>m;
    G = vector<vector<int>>(n+1);
    for(int i = 2; i <= n; ++i)
    {
        cin>>x;
        G[x].push_back(i);
        t[i][0] = x;
    }

    for(int k = 1; 1 << k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            t[i][k] = t[t[i][k-1]][k-1];

    Dfs(1,0);

    while(m--)
    {
        cin>>a>>b;
        cout<<get_lca(a,b)<<'\n';
    }

    return 0;
}
