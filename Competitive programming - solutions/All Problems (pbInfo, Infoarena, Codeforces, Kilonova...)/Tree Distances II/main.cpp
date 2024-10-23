#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define ll long long
using namespace std;
const int N = 2e5 + 9;

int n, a, b, w[N];
ll down[N], up[N];
VVI G;

void Dfs1(int x, int p)
{
    w[x] = 1;

    for(auto y : G[x])
    {
        if(y == p)continue;

        Dfs1(y, x);

        w[x] += w[y];
        down[x] += down[y] + w[y];
    }
}

void Dfs2(int x, int p)
{
    if(x != 1)up[x] = up[p] + down[p] - down[x] - w[x] + (n - w[x]);

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
        cout << up[i]
        << ' ';
    return 0;
}
