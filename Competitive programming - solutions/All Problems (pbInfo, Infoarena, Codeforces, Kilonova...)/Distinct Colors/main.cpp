#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 9;
int n, x, a, b, ans[N];
set<int> d[N];
vector<vector<int>> G;

void Build(int x, int p)
{
    for(auto y : G[x])
    {
        if(y == p)continue;

        Build(y, x);

        if(d[x].size() < d[y].size())swap(d[x], d[y]);

        for(auto aux : d[y])d[x].insert(aux);
    }

    ans[x] = d[x].size();
}

int main()
{
    cin >> n;
    G = vector<vector<int>>(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> x;
        d[i].insert(x);
    }

    for(int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Build(1, 0);

    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    return 0;
}
