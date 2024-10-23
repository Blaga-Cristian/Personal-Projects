#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
using namespace std;
const int N = 2e5 + 9;

int n, a, b, w[N], x;
VVI G;

void Dfs(int x)
{
    w[x] = 1;
    for(auto y : G[x])
    {
        Dfs(y);

        w[x] += w[y];
    }
}

int main()
{
    cin >> n;
    G = VVI(n + 1);

    for(int i = 2; i <= n; ++i)
    {
        cin >> x;
        G[x].push_back(i);
    }

    Dfs(1);

    for(int i = 1; i <= n; ++i)cout << w[i] - 1 << ' ';
    return 0;
}
