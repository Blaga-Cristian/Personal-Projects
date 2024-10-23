#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

//#define int long long
using namespace std;
const string TASK("ciclueuler");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9, M = 5e5 + 9;

int n, m;
bool viz[M];
vvpi G(N);


vi ans;
void Dfs(int x)
{
    while(!G[x].empty())
    {
        auto [y, id] = G[x].back();
        G[x].pop_back();

        if(viz[id])continue;
        viz[id] = true;

        Dfs(y);
    }
    ans.pb(x);
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    int x, y;
    FOR(i, 1, m){
        cin >> x >> y;
        G[x].pb({y, i});
        G[y].pb({x, i});
    }

    FOR(i, 1, n)
        if(G[x].size() % 2)
        {
            cout << "-1\n";
            return 0;
        }

    Dfs(1);

    if(ans.size() != m + 1)cout << "-1\n";
    else for(auto e : ans)cout << e << ' ';
    return 0;
}