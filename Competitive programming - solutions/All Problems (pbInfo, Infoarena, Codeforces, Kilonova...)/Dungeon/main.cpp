#include <bits/stdc++.h>
//#include <bits/extc++.h>
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
#define double long double
#define eb emplace_back
#define lo(x) (2 * (x) - 1)
#define up(x) (2 * (x))
//#define int long long
using namespace std;
//using namespace __gnu_pbds;

const string TASK("linegraph");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
const int N = 1009, Inf = 0x3f3f3f3f;

int n, m;
vvi G(N);
int low[N], lvl[N], idx, comp[N], t[N], nr_ap[N];
stack<pii> stk;
bool mat[N][N], viz[N];

vvi cbc;
vi c;

void extract_cbc(int x, int y)
{
    c.clear();
    int a, b;
    do
    {
        a = stk.top().ff, b = stk.top().ss;
        stk.pop();
        comp[a] = comp[b] = (int)cbc.size() + 1;
        c.pb(a), c.pb(b);
    }while(a != x && b != y);
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    cbc.pb(c);
}

void Dfs(int x, int p)
{
    low[x] = lvl[x] = ++idx;

    for(auto y : G[x])
    {
        if(y == p)continue;

        if(!lvl[y])
        {
            stk.push({x, y});
            Dfs(y, x);
            low[x] = min(low[x], low[y]);

            if(lvl[x] <= low[y])
                extract_cbc(x, y);
        }
        else low[x] = min(low[x], lvl[y]);
    }
}

vpi ans;
void Dfs_T(int x = 1, int p = n + 1)
{
    viz[x] = true;

    if(!t[comp[x]])
    {
        t[comp[x]] = p;

        for(auto i : cbc[comp[x] - 1])
            if(i != p)
                ans.pb({i, p});
    }

    for(auto y : G[x])
        if(!viz[y])
            Dfs_T(y, x);
}

void RESET()
{
    idx = 0;
    cbc.clear();
    ans.clear();
    FOR(i, 1, n)
    {
        nr_ap[i] = viz[i] = t[i] = low[i] = lvl[i] = comp[i] = 0;
        G[i].clear();
        FOR(j, 1, n)mat[i][j] = 0;
    }
}

void solve()
{
    cin >> n >> m;

    RESET();

    int x, y;
    FOR(i, 1, m)
    {
        cin >> x >> y;
        mat[x][y] = mat[y][x] = true;
        G[x].pb(y);
        G[y].pb(x);
    }

    if(n == 1 && m == 0)
    {
        cout << "DA\n2\n1 2\n";
        return;
    }

    Dfs(1, 0);

    FOR(i, 1, n)
        if(!lvl[i])
        {
            cout << "NU\n";
            return;
        }

    for(auto i : cbc)
        for(auto j : i)
            nr_ap[j] ++;

    FOR(i, 1, n)
        if(nr_ap[i] != 1 && nr_ap[i] != 2)
        {
            cout << "NU\n";
            return;
        }

    for(auto ev : cbc)
        for(int i = 0; i < ev.size(); ++i)
            for(int j = 0; j < ev.size(); ++j)
                if(i != j && !mat[ev[i]][ev[j]])
                {
                    cout << "NU\n";
                    return;
                }


//    for(auto i : cbc)
//    {
//        for(auto j : i)
//            cout << j << ' ';
//        cout << '\n';
//    }

    ///muchia i cor cu 2 * i - 1 e lo, si 2 * i e up
    Dfs_T(1);///det tatii

    cout << "DA\n";
    cout << (int)ans.size() + 1 << '\n';
    for(auto i : ans)cout << i.ff << ' ' << i.ss << '\n';
}

signed main()
{
//    cin >> p;
    int t = 1;
    cin >> t;
//    cout << fixed << setprecision(12);
    while(t --)
        solve();
    return 0;
}
