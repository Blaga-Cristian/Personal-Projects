#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
using pi = pair<int,int>;
const int N = 1e5 + 9,Inf = 0x3f3f3f3f;
int c,n,m,a,b,comp[N],in[N],w[N],cost,dist[N];
bool resedinta[N];
vector<vector<pi>> G,Gback;
vector<vector<int>> nG;
vector<int> order;

vector<int> low,lvl;
vector<bool> instk;
stack<int> stk;
vector<vector<int>> ctc;
vector<int> caux;
int idx,nrctc;
void Dfs(int x)
{
    stk.push(x);
    instk[x] = true;
    low[x] = lvl[x] = ++idx;

    for(auto i : G[x])
    {
        int y = i.first;
        if(lvl[y] == -1)
        {
            Dfs(y);
            low[x] = min(low[x],low[y]);
        }
        else
            if(instk[y])low[x] = min(low[x],lvl[y]);
    }

    if(low[x] == lvl[x])
    {
        caux.clear();
        while(true)
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;
            comp[a] = nrctc;
            caux.push_back(a);
            if(a == x)break;
        }
        ctc.push_back(caux);
        nrctc++;
    }
}
void Tarjan()
{
    for(int i = 1;i <= n; ++i)
        if(lvl[i] == -1)
            Dfs(i);
}

void sorttopo()
{
    queue<int> q;
    for(int i = 0; i < nrctc; ++i)
        if(in[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        order.push_back(x);

        for(auto y : nG[x])
        {
            in[y] --;
            if(in[y] == 0)
                q.push(y);
        }
    }
}

void Dijkstra()
{
    priority_queue<pi,vector<pi>,greater<pi>> q;
    for(int i = 1; i <= n; ++i)
        if(resedinta[i])
        {
            dist[i] = 0;
            q.push({0,i});
        }
        else
            dist[i] = Inf;

    while(!q.empty())
    {
        int dx = q.top().first,
        x = q.top().second;
        q.pop();

        if(dx > dist[x])continue;

        for(auto i : Gback[x])
        {
            int y = i.first,
            w = i.second;
            if(dist[y] > dist[x] + w)
            {
                dist[y] = dist[x] + w;
                q.push({dist[y],y});
            }
        }
    }
}

int main()
{
    cin>>c>>n>>m;
    G = vector<vector<pi>>(n+1);
    Gback = vector<vector<pi>>(n+1);
    low = lvl = vector<int>(n+1,-1);
    instk = vector<bool>(n+1);

    while(m--)
    {
        cin>>a>>b>>cost;
        G[a].push_back({b,cost});
        Gback[b].push_back({a,cost});
    }

    Tarjan();

    nG = vector<vector<int>>(nrctc);
    for(int i = 1; i <= n; ++i)
    {
        for(auto aux : G[i])
        {
            int j = aux.first,
            w = aux.second;
            if(comp[i] != comp[j])
                nG[comp[i]].push_back(comp[j]);
        }
    }

    for(auto& i : nG)
    {
        sort(i.begin(),i.end());
        i.erase(unique(i.begin(),i.end()),i.end());
        for(auto x : i)
            in[x] ++;
    }

    //for(int i = 1; i <= n; ++i)
        //cout<<comp[i]<<'\n';
    /// sunt indexate de la 0
    sorttopo();

    for(int i = 0; i < nrctc; ++i)
        w[i] = 1;

    //for(int i = 1; i <= n; ++i)
        //cout<<comp[i]<<' ';
    //cout<<'\n';
    //for(auto i : order)
        //cout<<i<<' ';
    //cout<<'\n';

    for(auto x : order)
        for(auto y : nG[x])
            w[y] += w[x];

    //cout<<'\n';
    //cout<<nrctc<<'\n';
    //for(int i = 0; i < nrctc; ++i)
        //cout<<w[order[i]]<<' ';
    //cout<<'\n';

    vector<int> ans;
    for(int i = 0; i < nrctc; ++i)
        if(w[i] == nrctc)
        {
            for(auto x : ctc[i])
            {
                ans.push_back(x);
            }
        }

    sort(ans.begin(),ans.end());
    for(auto i : ans)
        resedinta[i] = true;

    if(c == 1)
    {
        for(auto i : ans)
            cout<<i<<' ';
        return 0;
    }

    Dijkstra();
    for(int i = 1; i <= n; ++i)
        cout<<dist[i]<<' ';
    return 0;
}
