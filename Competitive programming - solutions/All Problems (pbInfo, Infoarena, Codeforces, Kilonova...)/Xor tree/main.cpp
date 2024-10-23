#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int N = 200009,Inf = 0x3f3f3f3f;
int n;
vector<vector<int>> G;
int c[N];
ll dp[2][N],a,b;///dp[1][i] = sum max daca sterg nodul i
///dp[0][i] = suma ma daca nu sterg nodul i

void Dfs(int x,int p)
{
    if(G[x].size() == 1 && p != 0)
    {
        dp[0][x] = c[x];
        dp[1][x] = 0;
        return;
    }

    dp[0][x] = -Inf;
    dp[1][x] = -Inf;

    for(auto i : G[x])
    {
        if(i == p)continue;
        Dfs(i,x);

        if(dp[0][x] == -Inf && dp[1][x] == -Inf)
        {
            dp[0][x] = dp[0][i];
            dp[1][x] = dp[1][i];
            continue;
        }

        ll dp1 = dp[1][x],dp0 = dp[0][x];
        dp[1][x] = max(dp0 + dp[1][i],dp1 + dp[0][i]);
        dp[0][x] = max(dp0 + dp[0][i], dp1 + dp[1][i]);
    }


    dp[0][x] += c[x];
}
int main()
{
    cin>>n;
    G = vector<vector<int>>(n+1);
    for(int i = 1; i < n; ++i)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i <= n;++i)
        cin>>c[i];
    Dfs(1,0);

    cout<<max(dp[1][1],dp[0][1]);
    return 0;
}
