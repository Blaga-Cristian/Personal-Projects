#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

#define int unsigned long long
using namespace std;
const int N = 1e5 + 9, BLOCK = 350;

int n, m, in[N], out[N], sz, t[N], dep[N], cnt[BLOCK][N], cor[N], inv[N], idx, to_add[N];
vi cnt_dep[N];
vvi G(N);

void Dfs1(int x = 1, int p = 0)
{
    in[x] = ++sz;

    for(auto y : G[x])
    {
        if(y == p)continue;

        t[y] = x;
        dep[y] = dep[x] + 1;
        Dfs1(y, x);
    }

    out[x] = ++sz;
}

void Dfs(int x, int p, int d)
{
    if(dep[x] == d)
    {
        cnt[idx][x] = 1;
        return;
    }

    for(auto y : G[x])
    {
        if(y == p)continue;

        Dfs(y, x, d);
        cnt[idx][x] += cnt[idx][y];
    }
}

int v[2 * N], block[2 * N];
void Update(int p, int val)
{
    v[p] += val;
    block[p / BLOCK] += val;
}
int Query(int l, int r)
{
    int ret = 0;

    int i;
    for(i = l; i <= r && i / BLOCK == l / BLOCK; ++i)
        ret += v[i];
    for(; i + BLOCK <= r; i += BLOCK)
        ret += block[i / BLOCK];
    for(; i <= r; ++i)
        ret += v[i];

    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    int u, v;
    for(int i = 2; i <= n; ++i)
    {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    for(int i = 1; i <= n; ++i)dep[i] = -1;
    dep[1] = 0;

    Dfs1();

    for(int i = 0; i <= n; ++i)
        if(dep[i] != -1)
            cnt_dep[dep[i]].push_back(i);

    for(int i = 0; i <= n; ++i)
        if(cnt_dep[i].size() > BLOCK)
        {
            cor[i] = ++idx;
            inv[idx] = i;

            Dfs(1, 0, i);
        }


    int op, l, x, y;
    while(m --)
    {
        cin >> op;

        if(op == 1)
        {
            cin >> l >> y;

            if(cnt_dep[l].size() > BLOCK)to_add[cor[l]] += y;
            else
                for(auto x : cnt_dep[l])
                    Update(in[x], y);
        }
        else
        {
            cin >> x;

            int sum = Query(in[x], out[x]);
            for(int i = 1; i <= idx; ++i)
                sum += cnt[i][x] * to_add[i];

            cout << sum << '\n';
        }
    }

    return 0;
}
