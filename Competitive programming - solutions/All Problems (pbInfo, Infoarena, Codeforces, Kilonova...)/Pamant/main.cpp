#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream cin("pamant.in");
ofstream cout("pamant.out");
using pi = pair<int,int>;
const int N = 1e5 + 9;
int n,m,a,b;
vector<vector<int>> G;
vector<int> low,lvl,t;
vector<bool> part;
vector<int> cbc;
stack<pi> stk;

void extract(int x,int y)
{
    int mn = 999999;
    while(true)
    {
        int tx = stk.top().first,ty = stk.top().second;
        stk.pop();
        mn = min(mn,min(tx,ty));
        if(x == tx && y == ty)break;
    }
    cbc.push_back(mn);
}

void Dfs(int x,int p)
{
    t[x] = p;
    low[x] = lvl[x] = lvl[p] + 1;

    for(auto i : G[x])
        if(i != p)
        {
            stk.push({i,x});
            Dfs(i,x);
            low[x] = min(low[x],low[i]);
            if(low[i] >= lvl[x])
                extract(i,x);
        }
        else
            low[x] = min(low[x],lvl[i]);
}

int main()
{
    cin>>n>>m;
    G = vector<vector<int>>(n+1);
    t = low = lvl = vector<int>(n+1);
    part = vector<bool>(n+1);
    while(m--)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i)
        if(lvl[i] == 0)
            Dfs(i,0);

    part[1] = (G[1].size() > 1);
    for(int i = 1; i <= n; ++i)
    {
        if(t[i] == 1 || i == 1)continue;
        if(low[i] >= lvl[t[i]])
            part[t[i]] = true;
    }

    for(auto i : cbc)
        cout<<i<<'\n';
    return 0;
}
