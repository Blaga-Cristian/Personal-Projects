#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9;

int n, x, y;
vector<vector<int>> G(N);

long double ans = 0;

int dep[N];
void Dfs(int x = 1, int p = 0)
{
    dep[x] = dep[p] + 1;
    ans += (long double)1 / dep[x];

    for(auto y : G[x])
        if(y != p)
            Dfs(y, x);
}

int main()
{
    cin >> n;

    for(int i = 1; i < n; ++i)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    Dfs();

    cout << fixed << setprecision(12);
    cout << ans << '\n';
    return 0;
}
