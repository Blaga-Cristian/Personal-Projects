#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
using namespace std;
const int N = 1e5 + 9, LG = 21;
const ll normalize = 1e9 + 9;
const ll Inf = 0x3f3f3f3f;
const bool test_cases = false;

int n, m, a[N];

struct node
{
    int val;
    bool lazy;
};
node tree[LG + 1][4 * N];

void Push(int bit, int nod, int st, int dr)
{
    if(st == dr || tree[bit][nod].lazy == 0)return;

    int m = (st + dr) >> 1;
    tree[bit][nod << 1].val = m - st + 1 - tree[bit][nod << 1].val;
    tree[bit][nod << 1].lazy ^= 1;
    tree[bit][nod << 1 | 1].val = dr - m - tree[bit][nod << 1 | 1].val;
    tree[bit][nod << 1 | 1].lazy ^= 1;

    tree[bit][nod].lazy = 0;
}

void Build(int bit, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        tree[bit][nod].val = ((a[st] & (1 << bit)) != 0);
        return;
    }
    int m = (st + dr) >> 1;
    Build(bit, nod << 1, st, m);
    Build(bit, nod << 1 | 1, m + 1, dr);
    tree[bit][nod].val = tree[bit][nod << 1].val + tree[bit][nod << 1 | 1].val;
}

void Flip(int bit, int l, int r, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)
    {
        tree[bit][nod].val = dr - st + 1 - tree[bit][nod].val;
        tree[bit][nod].lazy ^= 1;
        return;
    }
    Push(bit, nod, st, dr);
    int m = (st + dr) >> 1;
    if(l <= m)Flip(bit, l, r, nod << 1, st, m);
    if(r > m)Flip(bit, l, r, nod << 1 | 1, m + 1, dr);
    tree[bit][nod].val = tree[bit][nod << 1].val + tree[bit][nod << 1 | 1].val;
}

int Query(int bit, int l, int r, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)return tree[bit][nod].val;
    Push(bit, nod, st, dr);
    int m = (st + dr) >> 1;
    if(r <= m)return Query(bit, l, r, nod << 1, st, m);
    else if(l > m)return Query(bit, l, r, nod << 1 | 1, m + 1, dr);
    return Query(bit, l, r, nod << 1, st, m) + Query(bit, l, r, nod << 1 | 1, m + 1, dr);
}

void solve()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i];

    FOR(b, 0, LG)Build(b);

    cin >> m;
    int op, l, r, x;
    FOR(i, 1, m)
    {
        cin >> op >> l >> r;
        if(op == 1)
        {
            ll ans = 0;
            FOR(b, 0, LG)
                ans += (1LL << b) * Query(b, l, r);

            cout << ans << '\n';
        }
        else
        {
            cin >> x;
            FOR(b, 0, LG)
                if((x & (1 << b)) != 0)
                    Flip(b, l, r);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
