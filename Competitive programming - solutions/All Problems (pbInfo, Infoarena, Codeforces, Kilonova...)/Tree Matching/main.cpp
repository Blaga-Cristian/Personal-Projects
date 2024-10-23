#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
using namespace std;
const int N = 2e5 + 9;

int n, a, b, dp[2][N]; ///dp[0][x] = nu foloseste x, dp[1][x] = foloseste x
VVI G;

void Dfs(int x, int p)
{
    for(auto y : G[x])
    {
        if(y == p)continue;

        Dfs(y, x);

        dp[0][x] += max(dp[0][y], dp[1][y]);
    }

    for(auto y : G[x])
    {
        if(y == p)continue;

        dp[1][x] = max(dp[1][x], dp[0][x] - max(dp[0][y], dp[1][y]) + 1 + dp[0][y]);
    }
}

int main()
{
    cin >> n;
    G = VVI(n + 1);
    for(int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Dfs(1, 0);

    cout << max(dp[0][1], dp[1][1]);
    return 0;
}
