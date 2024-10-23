#include <bits/stdc++.h>
#include <bits/extc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long

using namespace std;
using namespace __gnu_pbds;
const int N = 1e5 + 9, BUCKET = 300;

int n, m;
vi src;
vvi G(N);
pii qs[N];

int dep[N], t[N], j[N];
void Dfs(int x = 1, int p = 0)
{
    t[x] = p;
    dep[x] = dep[p] + 1;

    if(dep[j[t[x]]] - dep[t[x]] == dep[j[j[t[x]]]] - dep[j[t[x]]])
        j[x] = j[j[t[x]]];
    else j[x] = t[x];

    for(auto y : G[x])
        if(y != p)
            Dfs(y, x);
}

int get_lca(int x, int y)
{
    if(dep[x] < dep[y])swap(x, y);

    for(; dep[x] != dep[y];)
        if(dep[j[x]] >= dep[y])
            x = j[x];
        else x = t[x];

    for(; x != y;)
        if(j[x] != j[y])
        {
            x = j[x];
            y = j[y];
        }
        else
        {
            x = t[x];
            y = t[y];
        }

    return x;
}

int d[N];
void Bfs()
{
    queue<int> q;
    for(int i = 1; i <= n; ++i)d[i] = INT_MAX;

    for(auto x : src)
    {
        q.push(x);
        d[x] = 0;
    }

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto y : G[x])
            if(d[y] > d[x] + 1)
            {
                d[y] = d[x] + 1;
                q.push(y);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    int x, y;
    for(int i = 2; i <= n; ++i)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    Dfs();

    for(int i = 1; i <= m; ++i)cin >> qs[i].ff >> qs[i].ss;

    src.pb(1);
    for(int k = 1; k <= m; k += BUCKET)
    {
        Bfs();

        vi cur;
        for(int i = k; i <= min(m, k + BUCKET - 1); ++i)
            if(qs[i].ff == 1)
            {
                src.pb(qs[i].ss);
                cur.pb(qs[i].ss);
            }
            else
            {
                int ans = d[qs[i].ss];
                for(auto x : cur)ans = min(ans, dep[qs[i].ss] + dep[x] -
                                           2 * dep[get_lca(qs[i].ss, x)]);

                cout << ans << '\n';
            }
    }
    return 0;
}
