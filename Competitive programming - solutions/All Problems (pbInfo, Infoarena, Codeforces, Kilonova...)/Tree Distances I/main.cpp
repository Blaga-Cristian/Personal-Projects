#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
using namespace std;
const int N = 2e5 + 9;

int n, a, b, up[N], down[N], sdown[N];
VVI G;

void Dfs1(int x, int p)
{
    for(auto y : G[x])
    {
        if(y == p)continue;

        Dfs1(y, x);

        if(down[x] < down[y] + 1)
        {
            sdown[x] = down[x];
            down[x] = down[y] + 1;
        }
        else if(sdown[x] < down[y] + 1)
            sdown[x] = down[y] + 1;
    }
}

void Dfs2(int x, int p)
{
    if(p != 0)
    {
        if(down[x] + 1 == down[p])up[x] = max(up[p], sdown[p]) + 1;
        else up[x] = max(up[p], down[p]) + 1;
    }

    for(auto y : G[x])
        if(y != p)
            Dfs2(y, x);
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

    Dfs1(1, 0);
    Dfs2(1, 0);

    for(int i = 1; i <= n; ++i)
        cout << max(up[i], down[i]) << ' ';
    return 0;
}
