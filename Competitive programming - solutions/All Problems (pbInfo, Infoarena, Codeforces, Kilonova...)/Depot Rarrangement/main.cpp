#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vpi vector<pii>
#define vvpi vector<vpi>
#define ll long long
//#define int long long
using namespace std;
const string TASK("ulei");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 15009, M = 100009;

int n, m;
int x[M], y[M], col[M];
vvpi G(N);
unordered_map<int, int> mat[N];
bool viz[M];

void solve()
{
    cin >> n >> m;

    FOR(i, 1, n)mat[i].clear();
    FOR(i, 1, m)viz[i] = false;

    int u, v, t;
    FOR(i, 1, m)
    {
        cin >> u >> v >> t;
        G[u].pb({v, i});
        G[v].pb({u, i});
        x[i] = u;
        y[i] = v;
        col[i] = t;
    }

    FOR(i, 1, n)
    {
        sort(G[i].begin(), G[i].end(), [&](pii a, pii b){return col[a.ss] < col[b.ss];});

        int m = G[i].size() / 2;
        FOR(j, 0, m - 1)
        {
            mat[i][G[i][j].ss] = G[i][j + m].ss;
            mat[i][G[i][j + m].ss] = G[i][j].ss;
        }
    }

//    FOR(i, 1, n)
//    {
//        cout << "For node " << i << ' ';
//        for(auto j : mat[i])cout << j.ff << ',' << j.ss << ' ';
//        cout << '\n';
//    }

    vi ans;
    stack<pii> stk;
    stk.push({1, 0});
    while(!stk.empty())
    {
        int u = stk.top().ff, id = stk.top().ss;

        while(!G[u].empty() && viz[G[u].back().ss])G[u].pop_back();

        if(G[u].empty())
        {
            ans.pb(u);
            stk.pop();
            continue;
        }

        int nxt = G[u].back().ss;

        if(id && (col[id] == col[nxt] || col[mat[u][id]] == col[mat[u][nxt]]))
            nxt = mat[u][nxt];

        while(!viz[nxt])
        {
            viz[nxt] = true;
            u = (u == x[nxt]) ? y[nxt] : x[nxt];
            stk.push({u, nxt});
            nxt = mat[u][nxt];
        }
    }

    for(auto i : ans)cout << i << ' ';
    cout << '\n';
}

signed main()
{
    int t = 1;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
