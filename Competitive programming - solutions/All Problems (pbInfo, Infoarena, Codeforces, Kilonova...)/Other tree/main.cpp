#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi = pair<int,int>;
const int N = 2 * (1e5) + 1;
vector<vector<int>> G;
vector<bool> viz;
vector<int> d;
int n,m,a,b,x,y,t;

void solve()
{
    cin>>n>>m;
    priority_queue<pi,vector<pi>,greater<pi>> q;
    G = vector<vector<int>>(n+1);
    viz = vector<bool>(n+1);
    d = vector<int>(n+1);

    for(int i = 1; i <= n; ++i)
    {
        cin>>d[i];
        if(d[i] == 0)
            q.push({0,i});
    }

    while(m--)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int str = 0;
    while(!q.empty())
    {
        int dx = q.top().first,
        x = q.top().second;
        q.pop();

        if(dx > str || viz[x])continue;

        viz[x] = true;
        str++;

        for(auto y : G[x])
            if(!viz[y])
                q.push({d[y],y});
    }

    cout<<str<<'\n';

    if(str >= n)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main()
{
    cin>>t;
    while(t--)
        solve();
    return 0;
}
