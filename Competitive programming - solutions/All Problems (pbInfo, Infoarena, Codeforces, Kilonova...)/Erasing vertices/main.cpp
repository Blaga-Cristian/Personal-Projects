#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pi = pair<ll,int>;
const int N = 2 * 1e5 + 9;
ll n,m,a,b,cost[N],rem[N];
vector<vector<int>> G;
ll ans = -14;
bool removed[N];


void Dij()
{
    priority_queue<pi,vector<pi>,greater<pi>> q;
    for(int i = 1; i <= n; ++i)
        q.push({rem[i],i});

    while(!q.empty())
    {
        ll rx = q.top().first;
        int x = q.top().second;
        q.pop();

        if(rx > rem[x] || removed[x])continue;

        ans = max(ans,rx);
        removed[x] = true;

        for(auto y : G[x])
        {
            if(removed[y])continue;
            rem[y] -= cost[x];
            q.push({rem[y],y});
        }
    }
}

int main()
{
    cin>>n>>m;
    G = vector<vector<int>>(n+1);
    for(int i = 1; i <= n; ++i)
        cin>>cost[i];
    while(m--)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int x = 1; x <= n; ++x)
        for(auto y : G[x])
            rem[x] += cost[y];

    Dij();

    cout<<ans;
    return 0;
}
