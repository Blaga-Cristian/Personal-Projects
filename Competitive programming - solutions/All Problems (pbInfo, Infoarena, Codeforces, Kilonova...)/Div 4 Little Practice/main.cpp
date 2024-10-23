#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long

using namespace std;
const int N = 509;
const bool test_cases = true;

int n, a[3][N];
vvi G(2 * N);

int opp(int x)
{
    return x <= n ? x + n : x - n;
}

int low[2 * N], lvl[2 * N], idx, comp[2 * N];
bool instk[2 * N];
stack<int> stk;
int cnt;

void Dfs(int x)
{
    low[x] = lvl[x] = ++ idx;
    stk.push(x);
    instk[x] = true;

    for(auto y : G[x])
        if(!lvl[y])
        {
            Dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y])low[x] = min(low[x], lvl[y]);

    if(low[x] == lvl[x])
    {
        ++ cnt;
        while(true)
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;

            comp[a] = cnt;

            if(a == x)break;
        }
    }
}

void solve()
{
    cin >> n;

    FOR(i, 1, 3)
        FOR(j, 1, n)
        {
            cin >> a[i][j];
//            if(a[i][j] < 0)a[i][j] = n - a[i][j];
        }
//
//    FOR(i, 1, 3)
//        FOR(j, 1, n)
//            cout << a[i][j] << " \n"[j == n];


//    FOR(i, 1, n)
//        FOR(j, 1, 3)
//            FOR(k, 1, 3)
//                if(k != j)
//                    G[opp(a[j][i])].pb(a[k][i]);

//    FOR(i, 1, 2 * n)
//        if(!lvl[i])
//            Dfs(i);

//    FOR(i, 1, n)
//        if(comp[i] == comp[opp(i)])
//        {
//            cout << "NO\n";
//            return;
//        }
//
//    cout << "YES\n";
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
