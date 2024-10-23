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
const string TASK("rafaela");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 2e5 + 9, M = 2e5 + 9, Inf = 0x3f3f3f3f, Mod = 1e9 + 7;

int n, q, a[N], w[N], head[N], t[N], dep[N], heavy_son[N], sm[N], idx, total, pos[N];
set<int> st[N];
vvi G(N);

void Dfs(int x = 1, int p = 0)
{
    t[x] = p;
    dep[x] = dep[p] + 1;
    w[x] = 1;
    sm[x] = a[x];

    heavy_son[x] = -1;
    for(auto y : G[x])
    {
        if(y == p)continue;

        Dfs(y, x);
        w[x] += w[y];
        sm[x] += sm[y];

        if(heavy_son[x] == - 1 || w[heavy_son[x]] < w[y])
            heavy_son[x] = y;
    }
}

int aib[N];
void Update(int p, int v)
{
    for(; p <= n; p += p & -p)
        aib[p] += v;
}
void Update(int l, int r, int v)
{
    Update(l, v);
    Update(r + 1, - v);
}
int Get(int p)
{
    int ret = 0;
    for(; p; p -= p & -p)
        ret += aib[p];
    return ret;
}

void Decomp(int x = 1, int hd = 1)
{
    pos[x] = ++ idx;
    head[x] = hd;
    Update(pos[x], pos[x], sm[x]);

    if(heavy_son[x] != -1)Decomp(heavy_son[x], hd);

    for(auto y : G[x])
        if(y != t[x] && y != heavy_son[x])
        {
            st[x].insert(sm[y]);
            Decomp(y, y);
        }
}

void Update_Tree(int p, int v)///adaug v
{
    total += v;
    for(; p; p = t[head[p]])
    {
        auto it = st[t[head[p]]].find(Get(pos[head[p]]));
        if(it != st[t[head[p]]].end())st[t[head[p]]].erase(it);
        Update(pos[head[p]], pos[p], v);
        st[t[head[p]]].insert(Get(pos[head[p]]));
    }
}

int Answer(int x)
{
    int ans = 0;
    if(heavy_son[x])ans = Get(pos[heavy_son[x]]);
    if(!st[x].empty())ans = max(ans, *st[x].rbegin());
    ans = max(ans, total - Get(pos[x]));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> n >> q;

    int x, y;
    FOR(i, 2, n)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    FOR(i, 1, n)
    {
        cin >> a[i];
        total += a[i];
    }

    Dfs();
    Decomp();

    char c;
    FOR(i, 1, q)
    {
        cin >> c;

        if(c == 'Q')
        {
            cin >> x;
            cout << Answer(x) << '\n';
        }
        else
        {
            cin >> x >> y;
            Update_Tree(y, x);
        }
    }
    return 0;
}
