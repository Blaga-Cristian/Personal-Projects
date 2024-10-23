#include <bits/stdc++.h>
#define ll long long
#define PI pair<int, int>
#define F first
#define S second
using namespace std;
const int N = 1e5 + 9;

int n, m, a, b, deg[N], cntimpar, cntpar, cntcomp;
bool viz[2 * N], viznode[N];
vector<vector<PI>> G;
vector<int> stk;

void DoEuler(int x)
{
    for(auto i : G[x])
    {

        if(!viz[i.S])
        {
            viz[i.S] = true;
            DoEuler(i.F);
        }
    }

    stk.push_back(x);
}

void Dfs(int x)
{
    viznode[x] = true;

    for(auto y : G[x])
        if(!viznode[y.F])
            Dfs(y.F);
}

int main()
{
    freopen("test_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    G = vector<vector<PI>>(n + 1);
    stk.reserve(15 * N);
    for(int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        deg[a]++;
        deg[b]++;
    }

    for(int i = 1; i <= n; ++i)
        if(deg[i] % 2)++cntimpar;
        else ++cntpar;

    for(int i = 1; i <= n; ++i)
        if(!viznode[i])
        {
            cntcomp ++;
            Dfs(i);
        }


    if(cntpar != n)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }


    DoEuler(1);

    bool ok = true;
    for(int i = 1; i <= m; ++i)
        if(!viz[i])
            ok = false;
    if(!ok)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(auto i : stk)
        cout << i << ' ';
    return 0;
}
