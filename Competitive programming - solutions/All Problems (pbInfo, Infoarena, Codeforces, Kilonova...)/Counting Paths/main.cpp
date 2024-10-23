#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define pb push_back
#define eb emplace_back
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)

using namespace std;
const int N = 2e5 + 9, LG = 25;

int n, m, a, b;
VVI G;

int first[N], dep[N], ST[2 * N][LG], tour[2 * N], sz;
void Dfs(int x, int p = 0)
{
    dep[x] = dep[p] + 1;
    tour[++sz] = x;
    first[x] = sz;

    for(auto y : G[x])
        if(y != p)
        {
            Dfs(y, x);
            tour[++sz] = x;
        }

}
void Precalc()
{
    Dfs(1);

    for(int i = 1; i <= sz; ++i)
        ST[i][0] = tour[i];

    for(int k = 1; (1 << k) <= sz; ++k)
        for(int i = 1; i + (1 << k) - 1 <= sz; ++i){
            ST[i][k] = ST[i][k - 1];
            if(dep[ST[i][k - 1]] > dep[ST[i + (1 << (k - 1))][k - 1]])
                ST[i][k] = ST[i + (1 << (k - 1))][k - 1];
        }
}
int get_lca(int a, int b)
{
    a = first[a], b = first[b];
    if(b < a)swap(a, b);

    int k = log2(b - a + 1);
    return dep[ST[a][k]] < dep[ST[b - (1 << k) + 1][k]] ? ST[a][k] : ST[b - (1 << k) + 1][k];
}

int mrs[N], start[N], stop[N], ans[N];
void Propagate(int x, int p = 0)
{
    for(auto y : G[x])
    {
        if(y == p)continue;

        Propagate(y, x);

        ans[x] += mrs[y];
        mrs[x] += mrs[y];
    }

    ans[x] += start[x] - stop[x];
}

int main()
{
    cin >> n >> m;
    G = VVI(n + 1);

    REP(i, 2, n)
    {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    Precalc();

    REP(i, 1, m)
    {
        cin >> a >> b;

        mrs[a] ++;
        mrs[b] ++;
        mrs[get_lca(a, b)] -= 2;

        start[a] ++;
        start[b] ++;
        int c = get_lca(a, b);
        if(c != a && c != b)stop[c] ++;
        else start[c] --;
    }
    Propagate(1);

    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    return 0;
}
