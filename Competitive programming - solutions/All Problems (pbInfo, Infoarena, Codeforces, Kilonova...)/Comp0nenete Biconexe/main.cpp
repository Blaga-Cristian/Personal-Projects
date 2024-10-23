#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VB vector<bool>
#define VVP vector<VP>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll

using namespace std;
const int N = 100009;

int n, m;
VVI G, cbc;
VI c;

VI low(N), lvl(N);
stack<PI> stk;
void Dfs(int x, int p, int idx)
{
    lvl[x] = low[x] = idx;

    for(auto y : G[x])
    {
        if(y == p)continue;

        if(!lvl[y])
        {
            stk.push({x, y});

            Dfs(y, x, idx + 1);

            low[x] = min(low[x], low[y]);

            if(low[y] >= lvl[x])
            {
                c.clear();
                while(true)
                {
                    PI a = stk.top();
                    stk.pop();

                    c.pb(a.F);
                    c.pb(a.S);

                    if(a.F == x && a.S == y)break;
                }
                sort(c.begin(), c.end());
                c.erase(unique(c.begin(), c.end()), c.end());
                cbc.pb(c);
            }
        }
        else low[x] = min(low[x], lvl[y]);
    }
}
void Tarjan()
{
    FOR(i, 1, n)
        if(!lvl[i])
            Dfs(i, 0, 1);
}

int main()
{
    freopen("biconex.in", "r", stdin);
    freopen("biconex.out", "w", stdout);

    cin >> n >> m;
    G = VVI(n + 1);
    int a, b;
    FOR(i, 1, m)
    {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    Tarjan();

    cout << cbc.size() << '\n';
    for(auto i : cbc)
    {
        for(auto j : i)cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
