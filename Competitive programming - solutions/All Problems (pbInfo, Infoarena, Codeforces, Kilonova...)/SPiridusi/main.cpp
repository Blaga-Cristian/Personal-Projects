#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 1e5 + 9, LG = 19;

int n, C, s[N], p[N], a, b;
int spath[N], ppath[N], sol;
vector<vector<int>> G;
vector<int> stk;

struct info
{
    int smax, pre, suf, sum;

    info operator + (info a)
    {
        return {max(smax, max(a.smax, suf + a.pre)),
        max(pre, sum + a.pre),
        max(a.suf, suf + a.sum),
        sum + a.sum};
    }
};
info tree[N][LG];
int t[N][LG], dep[N];

void Precalc(int x, int parent)
{
    tree[x][0] = {max(0, p[x]), max(0, p[x]), max(0, p[x]), p[x]};
    t[x][0] = parent;
    dep[x] = dep[parent] + 1;
    spath[x] = spath[parent] + s[x];
    ppath[x] = ppath[parent] + p[x];

    for(int i = 1; i < LG; ++i)
    {
        tree[x][i] = tree[x][i - 1] + tree[t[x][i - 1]][i - 1];
        t[x][i] = t[t[x][i - 1]][i - 1];
    }

    for(auto y : G[x])
        if(y != parent)
            Precalc(y, x);
}
int get_max_sum(int a, int b) /// lca(a, b) = a sau b
{
    if(dep[a] < dep[b])
        swap(a, b);

    info ans = {0, 0, 0, 0};
    for(int k = LG; k >= 0; --k)
        if(dep[a] - (1 << k) >= dep[b])
        {
            ans = ans + tree[a][k];
            a = t[a][k];
        }

    ans = ans + tree[a][0];
    return ans.smax;
}

int cb()
{
    int st = 0, dr = stk.size() - 1, mij, poz = -1;
    while(st <= dr)
    {
        mij = (st + dr) >> 1;
        if(spath[stk.back()] - spath[stk[mij]] + s[stk[mij]] <= C)
        {
            dr = mij - 1;
            poz = mij;
        }
        else
            st = mij + 1;
    }
    return poz;
}

void Dfs(int x, int parent)
{
    stk.push_back(x);

    int poz = cb();
    if(poz != -1)sol = max(sol, get_max_sum(x, stk[poz]));

    for(auto y : G[x])
        if(y != parent)
            Dfs(y, x);

    stk.pop_back();
}

int main()
{
    freopen("spiridusi.in", "r", stdin);
    freopen("spiridusi.out", "w", stdout);

    cin >> n >> C;
    G = vector<vector<int>>(n + 1);
    for(int i = 1; i <= n; ++i)cin >> s[i];
    for(int i = 1; i <= n; ++i)cin >> p[i];
    for(int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Precalc(1, 0);

    Dfs(1, 0);

    cout << sol;
    return 0;
}
