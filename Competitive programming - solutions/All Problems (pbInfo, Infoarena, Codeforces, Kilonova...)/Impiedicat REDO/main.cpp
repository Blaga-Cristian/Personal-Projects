#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vpi vector<pii>
#define vvpi vector<vpi>
using namespace std;
const string TASK("impiedicat");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 2e5 + 9, LG = 21;

int n, q, d[N], t[N][LG], mx[N][LG], up[N][LG], in[N], out[N], idx, dep[N];
int ans[N];
vvpi v;
vvi G(N);

struct query
{
    int t, x, y, ind;
};
vector<vector<query>> qs(N);

void Dfs(int x = 1, int p = 0)
{
    t[x][0] = p;
    FOR(i, 1, LG - 1)t[x][i] = t[t[x][i - 1]][i - 1];

    mx[x][0] = d[p];///doar tatal e inclus
    FOR(i, 1, LG - 1)mx[x][i] = max(mx[x][i - 1], mx[t[x][i - 1]][i - 1]);

    int v = x;
    FORR(i, LG - 1, 0)
        if(mx[v][i] < d[x])
            v = t[v][i];

    up[x][0] = t[v][0];
    FOR(i, 1, LG - 1)up[x][i] = up[up[x][i - 1]][i - 1];

    dep[x] = dep[p] + 1;
    in[x] = ++idx;

    for(auto y : G[x])
        Dfs(y, x);

    out[x] = ++idx;
}

int get_lca(int x, int y)
{
    if(dep[x] < dep[y])swap(x, y);

    FORR(i, LG - 1, 0)
        if(dep[x] - (1 << i) >= dep[y])
            x = t[x][i];

    if(x == y)return x;

    FORR(i, LG - 1, 0)
        if(t[x][i] != t[y][i])
        {
            x = t[x][i];
            y = t[y][i];
        }

    return t[x][0];
}

struct node
{
    int v, ans, lazy;
    ///v mentine maximul, ans mentine rapunsul
};
node tree[8 * N];

void Update_Set(int p, int v, int nod = 1, int st = 1, int dr = 2 * n)
{
    if(st == dr)
    {
        tree[nod].v = v;
        return;
    }
    int m = (st + dr) >> 1;
    if(p <= m)Update_Set(p, v, nod << 1, st, m);
    else Update_Set(p, v, nod << 1 | 1, m + 1, dr);
    tree[nod].v = max(tree[nod << 1].v, tree[nod << 1 | 1].v);
}

int Query(int l, int r, int nod = 1, int st = 1, int dr = 2 * n)
{
    if(l <= st && dr <= r)return tree[nod].v;
    int m = (st + dr) >> 1;
    if(r <= m)return Query(l, r, nod << 1, st, m);
    else if(l > m)return Query(l, r, nod << 1 | 1, m + 1, dr);
    return max(Query(l, r, nod << 1, st, m), Query(l, r, nod << 1 | 1, m + 1, dr));
}

int Query_Cb(int v, int nod = 1, int st = 1, int dr = 2 * n)///cm din st element mai mare
{
    if(st == dr)return st;
    int m = (st + dr) >> 1;
    if(tree[nod << 1].v > v)return Query_Cb(v, nod << 1, st, m);
    return Query_Cb(v, nod << 1 | 1, m + 1, dr);
}

int Query_Bc(int v, int nod = 1, int st = 1, int dr = 2 * n)///cm din dr elemebt
{
    if(st == dr)return st;
    int m = (st + dr) >> 1;
    if(tree[nod << 1 | 1].v > v)return Query_Bc(v, nod << 1 | 1, m + 1, dr);
    return Query_Bc(v, nod << 1, st, m);
}

void Push(int nod, int st, int dr)
{
    if(st == dr || tree[nod].lazy == 0)return;

    int l = tree[nod].lazy;
    tree[nod].lazy = 0;

    tree[nod << 1].ans += l;
    tree[nod << 1].lazy += l;

    tree[nod << 1 | 1].ans += l;
    tree[nod << 1 | 1].lazy += l;
}

void Show(int nod = 1, int st = 1, int dr = 2 * n)
{
    if(st == dr)
    {
        cout << tree[nod].v << ' ';
        return;
    }
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    Show(nod << 1, st, m);
    Show(nod << 1 | 1, m + 1, dr);
}

void Update_Range(int l, int r, int v, int nod = 1, int st = 1, int dr = 2 * n)
{
    if(l <= st && dr <= r)
    {
        tree[nod].ans += v;
        tree[nod].lazy += v;
        return;
    }
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(l <= m)Update_Range(l, r, v, nod << 1, st, m);
    if(r > m)Update_Range(l, r, v, nod << 1 | 1, m + 1, dr);
    tree[nod].v = max(tree[nod << 1].v, tree[nod << 1 | 1].v);
}

int Query_Ans(int p, int nod = 1, int st = 1, int dr = 2 * n)
{
    if(st == dr)return tree[nod].ans;
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(p <= m)return Query_Ans(p, nod << 1, st, m);
    return Query_Ans(p, nod << 1 | 1, m + 1, dr);
}

void Dfs_Solve(int x = 1, int p = 0)
{
    Update_Set(in[x], d[x]);

    int prv = 0;
    if(Query(1, in[x]) > d[x])prv = Query_Bc(d[x]);

    Update_Range(prv + 1, in[x], 1);///up nu e bun pt ca imi da elementul mai mare sau egal

//    cout << "At vertex " << x << " :";
//    Show();
//    cout << '\n';

    for(auto [t, v, y, ind] : qs[x])
    {
        if(Query(in[v], in[y]) >= t)
        {
            int st = in[v], dr = in[y], m, pos;
            while(st <= dr)
            {
                m = (st + dr) >> 1;
                if(Query(in[v], m) >= t)
                {
                    pos = m;
                    dr = m - 1;
                }
                else st = m + 1;
            }

//            cout << pos << '\n';

            ans[ind] += Query_Ans(pos);
        }
    }

    for(auto y : G[x])
        Dfs_Solve(y, x);

    Update_Range(prv + 1, in[x], - 1);
    Update_Set(in[x], 0);
}

int main()
{
    cin >> n >> q;
    FOR(i, 1, n)cin >> d[i];

    FOR(i, 0, n)FOR(j, 0, LG - 1)mx[i][j] = 0x3f3f3f3f;

    int p;
    FOR(i, 2, n)
    {
        cin >> p;
        G[p].pb(i);
    }

    Dfs();

    int x, y;
    FOR(i, 1, q)
    {
        cin >> x >> y;
        int lca = get_lca(x, y);

        if(x == lca)qs[y].pb({0, lca, y, i});
        else
        {
        ///solve first
        ans[i] = 1;
        FORR(b, LG - 1, 0)
            if(dep[up[x][b]] > dep[lca])
            {
                ans[i] += (1 << b);
                x = up[x][b];
            }
        qs[y].pb({d[x], lca, y, i});
        }
    }

//    FOR(i, 1, q)cout << ans[i] << ' ';
//    cout << '\n';

//    vi sir(2 * n + 1);
//    FOR(i, 1, n)sir[in[i]] = i, sir[out[i]] = i;
//    cout << "             ";
//    FOR(i, 1, 2 * n)cout << sir[i] << ' ';
//    cout << '\n';

    Dfs_Solve();

    FOR(i, 1, q)cout << ans[i] << '\n';

//    Update_Set(1, 4);
//    Update_Set(2, 9);
//    Update_Set(3, 5);
//    Update_Set(4, 8);
//    Show();
    return 0;
}
