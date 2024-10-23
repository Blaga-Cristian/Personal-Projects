#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vpi vector<pii>

using namespace std;
const int N = 2e5 + 9, V = 1e6 + 9;

int n, q, x[N], y[N];
vpi qs;
bool vis[V];

struct info
{
    int i, l, r;
    bool operator < (info const& oth)
    {
        return i < oth.i;
    }
};
vector<info> opt;

struct node
{
    int v, lazyv, lazys;
};
node tree[4 * V];

void Push(int nod, int st, int dr)
{
    if(st == dr || (tree[nod].lazyv == 0 && tree[nod].lazys == -1))return;

    int v = tree[nod].lazyv, s = tree[nod].lazys;
    tree[nod].lazyv = 0, tree[nod].lazys = -1;

    if(s == -1)
    {
        tree[nod << 1].v += v;
        tree[nod << 1].lazyv += v;
        tree[nod << 1 | 1].v += v;
        tree[nod << 1 | 1].lazyv += v;
    }
    else
    {
        tree[nod << 1].v = s + v;
        tree[nod << 1].lazyv = v;
        tree[nod << 1].lazys = s;
        tree[nod << 1 | 1].v = s + v;
        tree[nod << 1 | 1].lazyv = v;
        tree[nod << 1 | 1].lazys = s;
    }
}

void Update_Add(int l, int r, int v, int nod = 1, int st = 0, int dr = V - 1)
{
    if(l <= st && dr <= r)
    {
        tree[nod].v += v;
        tree[nod].lazyv += v;
        return;
    }
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(l <= m)Update_Add(l, r, v, nod << 1, st, m);
    if(r > m)Update_Add(l, r, v, nod << 1 | 1, m + 1, dr);
}

void Update_Set(int l, int r, int v, int nod = 1, int st = 0, int dr = V - 1)
{
    if(l <= st && dr <= r)
    {
        tree[nod].v = v;
        tree[nod].lazyv = 0;
        tree[nod].lazys = v;
        return;
    }
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(l <= m)Update_Set(l, r, v, nod << 1, st, m);
    if(r > m)Update_Set(l, r, v, nod << 1 | 1, m + 1, dr);
}

int Get(int p, int nod = 1, int st = 0, int dr = V - 1)
{
    if(st == dr)return tree[nod].v;
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(p <= m)return Get(p, nod << 1, st, m);
    return Get(p, nod << 1 | 1, m + 1, dr);
}

vector<pii> stk;

int main()
{
    cin >> n >> q;

    FOR(i, 1, n)
    {
        cin >> x[i] >> y[i];
        qs.pb({y[i] - 1, x[i]});
    }
    sort(qs.begin(), qs.end());

//    for(auto i : qs)cout << i.ff << ' ' << i.ss << '\n';

    multiset<int> mst;
    mst.insert(0), mst.insert(V);

    int op, t;
    FOR(i, 1, q)
    {
        cin >> op >> t;

        if(op == 1)///split
            mst.insert(t);
        else///skip
            if(!vis[t])
                opt.pb({t, *(--mst.upper_bound(t)), *mst.upper_bound(t) - 1});
    }
    sort(opt.begin(), opt.end());

//    cout << opt[5].ff << ' ' << opt[5].ss << '\n';

    int ans = 0, p = 0, pt = 0;
    FOR(i, 1, V - 1)
    {
        while(!stk.empty() && stk.back().ss < i)stk.pop_back();

//        for(auto x : stk)cout << x.ff << ',' << x.ss << ' ';
//        if(i <= 20)cout << '\n';

        if(stk.empty())Update_Add(0, i, 1);
        else
        {
            int p = stk.back().ff;
            Update_Add(p + 1, i, 1);
        }

        for(; pt < opt.size() && opt[pt].i == i; ++pt)
        {
            if(stk.size())
            {
                int pos = stk.back().ff;
                int res = Get(opt[pt].l);
                Update_Set(opt[pt].l, i, 0);
                Update_Add(pos + 1, opt[pt].l - 1, - res);
            }
            else
            {
                int res = Get(opt[pt].l);
                Update_Set(opt[pt].l, i, 0);
                Update_Add(0, opt[pt].l - 1, - res);
            }

            stk.pb({i, opt[pt].r});
//            cout << i << ' ' << opt[i].ss << ' ';
        }

//        FOR(j, 1, 10)cout << Get(j) << ' ';
//        cout << '\n';

        for(; p < n && qs[p].ff == i; ++p)
        {
//            cout << "ONE QUERY\n";
            ans += Get(qs[p].ss);
        }
    }

    cout << ans << '\n';
    return 0;
}
