#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 9, B = 211, M = 1e9 + 123;


struct Treap
{
    bool data, tp, ts, xr, rv;
    int priority, sz, mx, p, s, lz, c1, c0;

    array<Treap*, 2> sons;

    Treap(bool x)
    {
        tp = ts = data = x;
        p = s = mx = sz = 1;
        c1 = (x == 1), c0 = (x == 0);
        lz = -1;
        xr = rv = 0;
        priority = rand();
        sons = {NULL, NULL};
    }
};

struct info
{
    int mx, p, s, sz;
    bool tp, ts;

    info(int mx = 0, int p = 0, int s = 0, int sz = 0,
         bool tp = 0, bool ts = 0) :
             mx(mx), p(p), s(s), sz(sz), tp(tp), ts(ts) {}
};
info combine(info a, info b)
{
    info c;

    c.mx = max({a.mx, b.mx});
    if(a.ts == b.ts)c.mx = max(c.mx, a.s + b.p);
    c.p = a.p;
    if(a.p == a.sz && a.tp == b.tp)c.p += b.p;
    c.s = b.s;
    if(b.s == b.sz && a.ts == b.ts)c.s += a.s;
    c.sz = a.sz + b.sz;
    c.tp = a.tp;
    c.ts = b.ts;

    return c;
}

int size(Treap* t)
{
    return t == NULL ? 0 : t -> sz;
}

void prop(Treap* t)
{
    if(t == NULL)return;

    if(t -> lz != -1)
    {
        t -> mx = t -> p = t -> s = t -> sz;
        t -> data = t -> tp = t -> ts = t -> lz;
        if(t -> lz == 0)t -> c0 = t -> sz;
        else t -> c1 = t -> sz;

        if(t -> sons[0])t -> sons[0] -> lz = t -> lz;
        if(t -> sons[1])t -> sons[1] -> lz = t -> lz;
    }
    else
    {
        if(t -> xr)
        {
            swap(t -> c0, t -> c1);
            t -> data ^= 1;
            t -> tp ^= 1;
            t -> ts ^= 1;

            if(t -> sons[0])t -> sons[0] -> xr ^= 1;
            if(t -> sons[1])t -> sons[1] -> xr ^= 1;
        }
        if(t -> rv)
        {
            swap(t -> sons[0], t -> sons[1]);
            if(t -> sons[0])t -> sons[0] -> rv ^= 1;
            if(t -> sons[1])t -> sons[1] -> rv ^= 1;
        }
    }

    t -> lz = -1;
    t -> rv = t -> xr = 0;
}

void recalc(Treap* t)
{
    if(t == NULL)return;

    t -> sz = 1;
    t -> mx = t -> p = t -> s = 1;
    t -> tp = t -> ts = t -> data;
    if(t -> data == 0)t -> c0 = 1;
    else t -> c1 = 1;

    info ic = info(t -> mx, t -> p, t -> s, t -> sz,
                   t -> tp, t -> ts);

    if(t -> sons[0])
    {
        auto l = t -> sons[0];
        info il = info(l -> mx, l -> p, l -> s, l -> sz,
                   l -> tp, l -> ts);

        ic = combine(il, ic);

        t -> c1 += l -> c1;
        t -> c0 += l -> c0;
    }
    if(t -> sons[1])
    {
        auto r = t -> sons[1];
        info ir = info(r -> mx, r -> p, r -> s, r -> sz,
                   r -> tp, r -> ts);

        ic = combine(ic, ir);

        t -> c1 += r -> c1;
        t -> c0 += r -> c0;
    }

    t -> mx = ic.mx;
    t -> p = ic.p;
    t -> s = ic.s;
    t -> tp = ic.tp;
    t -> ts = ic.ts;
    t -> sz = ic.sz;
}

array<Treap*, 2> split(Treap *t, int left)
{
    if(t == NULL)return {NULL, NULL};
    prop(t);
    if(size(t -> sons[0]) >= left)
    {
        auto res = split(t -> sons[0], left);
        t -> sons[0] = res[1];
        recalc(t);
        return {res[0], t};
    }
    else
    {
        left -= size(t -> sons[0]) + 1;
        auto res = split(t -> sons[1], left);
        t -> sons[1] = res[0];
        recalc(t);
        return {t, res[1]};
    }
}

Treap* merge(Treap *a, Treap *b)
{
    if(a == NULL)return b;
    if(b == NULL)return a;

    prop(a), prop(b);

    if(a -> priority < b -> priority)
    {
        a -> sons[1] = merge(a -> sons[1], b);
        recalc(a);
        return a;
    }
    else
    {
        b -> sons[0] = merge(a, b -> sons[0]);
        recalc(b);
        return b;
    }
}

void Dfs(Treap* t)
{
    if(t == NULL)return;
    prop(t);
    Dfs(t -> sons[0]);
    cout << t -> data;
    Dfs(t -> sons[1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    srand(time(NULL));

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    Treap *t = NULL;
    for(int i = 0; i < n; ++i)
        t = merge(t, new Treap(s[i] - '0'));

    int op, l, r;
    while(q --)
    {
        cin >> op >> l >> r;

        if(op == 1)
        {
            auto a = split(t, l - 1);
            auto b = split(a[1], r - l + 1);
            b[0] -> xr ^= 1;
            t = merge(a[0], merge(b[0], b[1]));
        }
        else if(op == 2)
        {
            auto a = split(t, l - 1);
            auto b = split(a[1], r - l + 1);
            b[0] -> rv ^= 1;
            t = merge(a[0], merge(b[0], b[1]));
        }
        else if(op == 3)
        {
            auto a = split(t, l - 1);
            auto b = split(a[1], r - l + 1);
            int nr0 = b[0] -> c0;
            auto c = split(b[0], nr0);
            if(c[0])c[0] -> lz = 0;
            if(c[1])c[1] -> lz = 1;
            t = merge(a[0], merge(merge(c[0], c[1]), b[1]));
        }

        cout << t -> mx << '\n';
    }
    return 0;
}
