#include <bits/stdc++.h>
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
using namespace std;
const int N = 1e5 + 9;

int n, c[N];
VVI G, GI;

VI v;
int comp[N], id, cnt = 1;


bool incycle[N];
int viz[N];

int low[N], lvl[N], idx;
stack<int> stk;
void Get_Cycle(int x)
{
    lvl[x] = low[x] = ++idx;
    stk.push(x);

    for(auto y : G[x])
        if(lvl[y] == -1)
        {
            Get_Cycle(y);
            low[x] = min(low[x], low[y]);
        }
        else low[x] = min(low[x], lvl[y]);

    if(low[x] == lvl[x])
    {
        if(x == stk.top())
        {
            stk.pop();
            return;
        }

        while(true)
        {
            int a = stk.top();
            stk.pop();
            incycle[a] = true;
            v.push_back(a);
            if(a == x)break;
        }
    }
}

void Dfs1(int x)
{
    viz[x] = cnt;
    comp[x] = id;
    for(auto y : GI[x])
        if(viz[y] != cnt)
            Dfs1(y);

    if(!incycle[x])
        cout << x << ' ';
}

void Dfs2(int x)
{
    cout << x << ' ';

    viz[x] = cnt;
    for(auto y : G[x])
        if(viz[y] != cnt && incycle[y])
            Dfs2(y);

}

void solve()
{
    cin >> n;

    GI = G = VVI(n + 1);
    cnt = idx = id = 0;
    fill(lvl + 1, lvl + n + 1, -1);
    fill(low + 1, low + n + 1, -1);
    fill(incycle + 1, incycle + n + 1, false);
    fill(comp + 1, comp + n + 1, 0);
    fill(viz + 1, viz + n + 1, 0);

    int j;
    FOR(i, 1, n)
    {
        cin >> j;
        G[i].pb(j);
        GI[j].pb(i);
    }

    FOR(i, 1, n)
        cin >> c[i];


    for(int i = 1; i <= n; ++i)
    {
        if(comp[i])continue;
        id++;


        v.clear();
        Get_Cycle(i);
        for(auto i : v)
            incycle[i] = true;

        ++cnt;
        Dfs1(v[0]);

        int nod = -1, mn = INT_MAX;
        for(auto i : v)
            if(c[i] < mn)
            {
                mn = c[i];
                nod = i;
            }

        ++cnt;
        Dfs2(G[nod][0]);
    }

    cout << '\n';

}

int main()
{
    FAST_IN_OUT

    int t = 1;
    if(hast_test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
