#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
using namespace std;
const int N = 2e5 + 9;

int n, a, b, path[N], spath[N];
VVI G;

void Dfs(int x, int p)
{
    for(auto y : G[x])
    {
        if(y == p)continue;

        Dfs(y, x);

        if(path[x] < path[y] + 1)
        {
            spath[x] = path[x];
            path[x] = path[y] + 1;
        }
        else if(spath[x] < path[y] + 1)
            spath[x] = path[y] + 1;
    }
}

int main()
{
    cin >> n;
    G = VVI(n + 1);
    for(int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }

    Dfs(1, 0);

    int ans = 0;
    for(int i = 1; i <= n; ++i)ans = max(ans, path[i] + spath[i]);
    cout << ans;
    return 0;
}
