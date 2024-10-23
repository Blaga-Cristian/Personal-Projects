#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define ll long long
using namespace std;
const int N = 2e5 + 9, LG = 20;

int x, k, n, m, a, b, t[N][LG], dep[N];
VVI G;

void Dfs(int x, int p)
{
    if(x != 1)dep[x] = dep[p] + 1;
    t[x][0] = p;
    for(int i = 1; i < LG; ++i)
        t[x][i] = t[t[x][i - 1]][i - 1];

    for(auto y : G[x])
        Dfs(y, x);
}

int main()
{
    cin >> n >> m;
    G = VVI(n + 1);
    for(int i = 2; i <= n; ++i)
    {
        cin >> x;
        G[x].push_back(i);
    }

    Dfs(1, 0);

    while(m --)
    {
        cin >> a >> b;

        if(dep[a] < dep[b])swap(a, b);

        for(int i = LG - 1; i >= 0; --i)
            if(dep[a] - (1 << i) >= dep[b])
                a = t[a][i];

        if(a == b)
        {
            cout << a << '\n';
            continue;
        }

        for(int i = LG - 1; i >= 0; --i)
            if(t[a][i] != t[b][i])
            {
                a = t[a][i];
                b = t[b][i];
            }

        cout << t[a][0] << '\n';
    }
    return 0;
}
