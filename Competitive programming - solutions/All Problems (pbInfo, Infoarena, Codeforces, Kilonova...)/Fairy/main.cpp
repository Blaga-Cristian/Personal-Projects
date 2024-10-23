#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back

using namespace std;
const int N = 1e4 + 9;
const bool test_cases = false;

int n, m, dep[N];
vvpi G(N);
pii edges[N];

bool found;
void Dfs(int x, int p)
{
    dep[x] = dep[p] + 1;

    for(auto [y, _] : G[x])
    {
        if(y == p)continue;

        if(!dep[y])Dfs(y, x);
        else if(dep[y] % 2 == dep[x] % 2)
            found = true;
    }
}

vi bed, ans;
int dp[N], dp2[N];
bool viz[N];
void Dfs_S(int x, int p)
{
    viz[x] = true;

    for(auto [y, id] : G[x])
    {
        if(y == p)continue;

        if(!viz[y])
        {
            Dfs_S(y, x);
            dp[x] += dp[y];
            dp2[x] += dp2[y];
        }
        else if(dep[x] % 2 == dep[y] % 2)
        {
            if(dep[x] > dep[y])
            {
                bed.pb(id);
                dp[x] ++;
            }
            else dp[x] --;
        }
        else
        {
            if(dep[x] > dep[y])dp2[x] ++;
            else dp2[x] --;
        }
    }
}
void Collect(int x, int p)
{
    viz[x] = true;
    for(auto [y, id] : G[x])
    {
        if(y == p)continue;

        if(!viz[y])
        {
            Collect(y, x);
            if(dp[y] == bed.size() && dp2[y] == 0)
                ans.pb(id);
        }
    }
}

void solve()
{
    cin >> n >> m;

    int x, y;
    for(int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        G[x].pb({y, i});
        G[y].pb({x, i});
    }

    int nod = -1, cnt = 0;
    for(int i = 1; i <= n; ++i)
        if(!dep[i])
        {
            found = false;

            Dfs(i, 0);

            if(found)
            {
                nod = i;
                cnt ++;
            }
        }

    if(cnt == 0)
    {
        cout << m << '\n';
        for(int i = 1; i <= m; ++i)
            cout << i << ' ';
    }
    else if(cnt > 1)cout << "0\n";
    else
    {
        Dfs_S(nod, 0);
        fill(viz, viz + n + 1, false);
        Collect(nod, 0);

        if(bed.size() == 1)ans.pb(bed.back());

        sort(ans.begin(), ans.end());

        cout << ans.size() << '\n';
        for(auto i : ans)cout << i << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
