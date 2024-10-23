#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define int long long
#define ll long long

using namespace std;
const int N = 1e5 + 9, LG = 18, P = 457, Mod = 1e9 + 123;

int n, q;
int a[N];
vvi G(N);

int t[N][LG], tour[2 * N], first[N], last[N], sz, dep[N];
void Dfs(int x = 1, int p = 0)
{
    dep[x] = dep[p] + 1;

    t[x][0] = p;
    FOR(i, 1, LG - 1)
        t[x][i] = t[t[x][i - 1]][i - 1];

    first[x] = ++sz;
    tour[sz] = x;

    for(auto y : G[x])
        if(y != p)
            Dfs(y, x);

    last[x] = ++sz;
    tour[sz] = x;
}

ll mul(ll a, ll b)
{
    return (a * b) % Mod;
}
ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
}

ll tree[8 * N];
void Update(int p, ll v, int nod = 1, int st = 1, int dr = sz)
{
    if(st == dr)
    {
        tree[nod] = v;
        return;
    }
    int m = (st + dr) >> 1;
    if(p <= m)Update(p, v, nod << 1, st, m);
    else Update(p, v, nod << 1 | 1, m + 1, dr);
    tree[nod] = add(tree[nod << 1], tree[nod << 1 | 1]);
}
ll Query(int l, int r, int nod = 1, int st = 1, int dr = sz)
{
    if(l <= st && dr <= r)return tree[nod];
    int m = (st + dr) >> 1;
    if(r <= m)return Query(l, r, nod << 1, st, m);
    else if(l > m)return Query(l, r, nod << 1 | 1, m + 1, dr);
    return add(Query(l, r, nod << 1, st, m), Query(l, r, nod << 1 | 1, m + 1, dr));
}


ll pt[2 * N], invpt[2 * N], inv[309];
ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp /= 2, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    char ch;
    FOR(i, 1, n)
    {
        cin >> ch;
        a[i] = ch;
    }

//    FOR(i, 1, n)cout << a[i] << ' ';


    int p;
    FOR(i, 2, n)
    {
        cin >> p;
        G[p].pb(i);
    }

    Dfs();

    pt[0] = 1;
    FOR(i, 1, 2 * n)pt[i] = mul(P, pt[i - 1]);

    invpt[2 * n] = PtLg(pt[2 * n], Mod - 2);
    FORR(i, 2 * n - 1, 0)invpt[i] = mul(P, invpt[i + 1]);

    FOR(i, 1, 300)inv[i] = PtLg(i, Mod - 2);

    FOR(i, 1, n)
    {
        Update(first[i], mul(pt[dep[i]], a[i]));
        Update(last[i], Mod - mul(pt[dep[i]], a[i]));
    }

//    FOR(i, 1, 2 * n)cout << tour[i] << ' ';
//    cout << '\n';
//
//    cout << Query(first[3], first[3]) << ' ' << Query(last[3], last[3]) << '\n';
//
//    cout << Query(first[1], first[3]) << '\n';
//    cout << (pt[1] * a[1] % Mod + pt[2] * a[2] % Mod + pt[3] * a[3] % Mod) % Mod << '\n';
//    cout << Query(first[1], first[5]) << '\n';
//    cout << (pt[1] * a[1] % Mod + pt[2] * a[2] % Mod + pt[3] * a[5] % Mod) % Mod << '\n';
//
//    cout << Query(first[1], last[1]) << '\n';

    cin >> q;

    int op, x, y;
    while(q --)
    {
        cin >> op;

        if(op == 1)
        {
            cin >> x >> y;

            if(a[x] != a[y])
            {
                cout << "0\n";
                continue;
            }

            int l = 1;
            FORR(i, LG - 1, 0)
                if(t[x][i] && t[y][i] &&
                   mul(invpt[dep[t[x][i]] - 1], Query(first[t[x][i]], first[x])) ==
                   mul(invpt[dep[t[y][i]] - 1], Query(first[t[y][i]], first[y])))
                {
                    l += (1 << i);
                    x = t[x][i];
                    y = t[y][i];
                }

            cout << l << '\n';
        }
        else
        {
            cin >> x >> ch;

            a[x] = ch;
            Update(first[x], mul(pt[dep[x]], a[x]));
            Update(last[x], Mod - mul(pt[dep[x]], a[x]));
        }
    }
    return 0;
}
