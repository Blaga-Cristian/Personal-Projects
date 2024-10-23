#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream cin("ct.in");
ofstream cout("ct.out");
const int N = 100009;

int n,m,t,a,b,x,y,k,ans;
vector<vector<int>> sirad;
vector<bool> sters,v;
int tour[2*N],dep[N],first[N],st[2*N][20];
int idx;
struct element
{
    int a,b,lca;
};
vector<element> elements;
void Dfs(int x,int p)
{
    v[x] = true;
    tour[++idx] = x;
    first[x] = idx;
    dep[x] = dep[p] + 1;
    for(auto i : sirad[x])
    {
        if(v[i])continue;
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
bool cmp (element& a, element& b)
{
    return dep[a.lca] > dep[b.lca];
}
void sterge(int x)
{
    sters[x] = true;
    for(auto i : sirad[x])
        if(sters[i] == 0 && dep[i] > dep[x])
            sterge(i);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        idx = 0;
        ans = 0;
        elements.clear();
        sirad = vector<vector<int>>(n+1);
        sters = vector<bool>(n+1);
        v = vector<bool>(n+1);
        for(int i=1;i<n;++i)
        {
            cin>>a>>b;
            sirad[a].push_back(b);
            sirad[b].push_back(a);
        }

        Dfs(1,0);
        Process();


        while(k--)
        {
            cin>>a>>b;
            elements.push_back({a,b,lca(a,b)});
        }

        sort(elements.begin(),elements.end(),cmp);

        for(auto i : elements)
        {
            if(!sters[i.a] && !sters[i.b])
            {
                ans ++;
                sterge(i.lca);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
