#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 2e5 + 9, Inf = LLONG_MAX >> 4;

int n, q, a[N];

struct node
{
    int sum, mn, cmn, smn, mx, cmx, smx;
    int lazymn, lazymx, lazy;

    node() : sum(0), mn(Inf), cmn(0), smn(Inf), mx(-Inf), cmx(0), smx(-Inf),
            lazymn(Inf), lazymx(-Inf), lazy(0){}

    friend node operator + (node const& a, node const& b)
    {///noul nod nu are niciun tip de lazy
        node c;

        c.sum = a.sum + b.sum;

        if(a.mx < b.mx)
        {
            c.mx = b.mx;
            c.cmx = b.cmx;
            c.smx = max(a.mx, b.smx);
        }
        else if(a.mx > b.mx)
        {
            c.mx = a.mx;
            c.cmx = a.cmx;
            c.smx = max(a.smx, b.mx);
        }
        else
        {
            c.mx = a.mx;
            c.cmx = a.cmx + b.cmx;
            c.smx = max(a.smx, b.smx);
        }

        if(a.mn < b.mn)
        {
            c.mn = a.mn;
            c.cmn = a.cmn;
            c.smn = min(a.smn, b.mn);
        }
        else if(a.mn > b.mn)
        {
            c.mn = b.mn;
            c.cmn = b.cmn;
            c.smn = min(a.mn, b.smn);
        }
        else
        {
            c.mn = a.mn;
            c.cmn = a.cmn + b.cmn;
            c.smn = min(a.smn, b.smn);
        }

        return c;
    }
};
node t[4 * N];

void Build(int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        t[nod].sum = t[nod].mn = t[nod].mx = a[st];
        t[nod].cmn = t[nod].cmx = 1;
        t[nod].smn = Inf;
        t[nod].smx = -Inf;
        return;
    }
    int m = (st + dr) >> 1;
    Build(nod << 1, st, m);
    Build(nod << 1 | 1, m + 1, dr);
    t[nod] = t[nod << 1] + t[nod << 1 | 1];
}

void Push(int nod, int st, int dr)
{
    if(st == dr || (t[nod].lazymn == Inf && t[nod].lazymx == -Inf && t[nod].lazy == 0))return;

    int m = (st + dr) >> 1, mn = t[nod].lazymn, mx = t[nod].lazymx, s = t[nod].lazy;
    t[nod].lazymn = Inf, t[nod].lazymx = -Inf, t[nod].lazy = 0;

    t[nod << 1].sum += (m - st + 1) * s;
    t[nod << 1].mx += s; if(t[nod << 1].smx != -Inf)t[nod << 1].smx += s;
    t[nod << 1].mn += s; if(t[nod << 1].smn != Inf)t[nod << 1].smn += s;

    if(t[nod << 1].lazymn != Inf)t[nod << 1].lazymn += s;
    if(t[nod << 1].lazymx != -Inf)t[nod << 1].lazymx += s;
    t[nod << 1].lazy += s;
    t[nod << 1].lazymn = min(t[nod << 1].lazymn, mn);
    t[nod << 1].lazymx = max(t[nod << 1].lazymx, mx);

    if(t[nod << 1].mx > mn)
    {
        t[nod << 1].sum += (mx - t[nod << 1].mx) * t[nod << 1].cmx;

        if(t[nod << 1].mx == t[nod << 1].mn)
            t[nod << 1].mx = t[nod << 1].mn = mx;
        else if(t[nod << 1].mx == t[nod << 1].smn)
            t[nod << 1].mx = t[nod << 1].smn = mx;
        else t[nod << 1].mx = mx;
    }
    if(t[nod << 1].mn < mx)
    {
        t[nod << 1].sum += (mn - t[nod << 1].mn) * t[nod << 1].cmn;

        if(t[nod << 1].mn == t[nod << 1].mx)
            t[nod << 1].mn = t[nod << 1].mx = mn;
        else if(t[nod << 1].mn == t[nod << 1].smx)
            t[nod << 1].mn = t[nod << 1].smx = mn;
        else t[nod << 1].mn = mn;
    }

    t[nod << 1 | 1].sum += (dr - m) * s;
    t[nod << 1 | 1].mx += s; if(t[nod << 1 | 1].smx != -Inf)t[nod << 1 | 1].smx += s;
    t[nod << 1 | 1].mn += s; if(t[nod << 1 | 1].smn != Inf)t[nod << 1 | 1].smn += s;

    if(t[nod << 1 | 1].lazymn != Inf)t[nod << 1 | 1].lazymn += s;
    if(t[nod << 1 | 1].lazymx != -Inf)t[nod << 1 | 1].lazymx += s;
    t[nod << 1 | 1].lazy += s;
    t[nod << 1 | 1].lazymn = min(t[nod << 1 | 1].lazymn, mn);
    t[nod << 1 | 1].lazymx = max(t[nod << 1 | 1].lazymx, mx);

    if(t[nod << 1 | 1].mx > mn)
    {
        t[nod << 1 | 1].sum += (mx - t[nod << 1 | 1].mx) * t[nod << 1 | 1].cmx;

        if(t[nod << 1 | 1].mx == t[nod << 1 | 1].mn)
            t[nod << 1 | 1].mx = t[nod << 1 | 1].mn = mx;
        else if(t[nod << 1 | 1].mx == t[nod << 1 | 1].smn)
            t[nod << 1 | 1].mx = t[nod << 1 | 1].smn = mx;
        else t[nod << 1 | 1].mx = mx;
    }
    if(t[nod << 1 | 1].mn < mx)
    {
        t[nod << 1 | 1].sum += (mn - t[nod << 1 | 1].mn) * t[nod << 1 | 1].cmn;

        if(t[nod << 1 | 1].mn == t[nod << 1 | 1].mx)
            t[nod << 1 | 1].mn = t[nod << 1 | 1].mx = mn;
        else if(t[nod << 1 | 1].mn == t[nod << 1 | 1].smx)
            t[nod << 1 | 1].mn = t[nod << 1 | 1].smx = mn;
        else t[nod << 1 | 1].mn = mn;
    }
}

void Update_Min(int l, int r, int v, int nod = 1, int st = 1, int dr = n)
{
    if(dr < l || st > r || t[nod].mx <= v)return;
    if(l <= st && dr <= r && t[nod].smx < v)
    {
        t[nod].sum += (v - t[nod].mx) * t[nod].cmx;

        if(t[nod].mx == t[nod].mn)
            t[nod].mx = t[nod].mn = v;
        else if(t[nod].mx == t[nod].smn)
            t[nod].mx = t[nod].smn = v;
        else t[nod].mx = v;

        t[nod].lazymn = min(t[nod].lazymn, v);
        return;
    }

    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    Update_Min(l, r, v, nod << 1, st, m);
    Update_Min(l, r, v, nod << 1 | 1, m + 1, dr);

    t[nod] = t[nod << 1] + t[nod << 1 | 1];
}

void Update_Max(int l, int r, int v, int nod = 1, int st = 1, int dr = n)
{
//    cout << nod << ' ' << st << ' ' << dr << '\n';
    if(dr < l || st > r || t[nod].mn >= v)return;
    if(l <= st && dr <= r && t[nod].smn > v)
    {
        t[nod].sum += (v - t[nod].mn) * t[nod].cmn;

        if(t[nod].mn == t[nod].mx)
            t[nod].mn = t[nod].mx = v;
        else if(t[nod].mn == t[nod].smx)
            t[nod].mn = t[nod].smx = v;
        else t[nod].mn = v;

        t[nod].lazymx = max(t[nod].lazymx, v);
        return;
    }

    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    Update_Max(l, r, v, nod << 1, st, m);
    Update_Max(l, r, v, nod << 1 | 1, m + 1, dr);

    t[nod] = t[nod << 1] + t[nod << 1 | 1];
}

void Update_Add(int l, int r, int v, int nod = 1, int st = 1, int dr = n)
{
    if(dr < l || st > r)return;
    if(l <= st && dr <= r)
    {
        t[nod].sum += (st - dr + 1) * v;
        t[nod].mn += v, t[nod].smn += v;
        t[nod].mx += v, t[nod].smx += v;

        t[nod].lazy += v;///suma este adaugata mereu PRIMA
        if(t[nod].lazymn != Inf)t[nod].lazymn += v;
        if(t[nod].lazymx != -Inf)t[nod].lazymx += v;
        return;
    }

    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    Update_Add(l, r, v, nod << 1, st, m);
    Update_Add(l, r, v, nod << 1 | 1, m + 1, dr);

    t[nod] = t[nod << 1] + t[nod << 1 | 1];
}

int Query(int l, int r, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)return t[nod].sum;
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(r <= m)return Query(l, r, nod << 1, st, m);
    else if(l > m)return Query(l, r, nod << 1 | 1, m + 1, dr);
    return Query(l, r, nod << 1, st, m) + Query(l, r, nod << 1 | 1, m + 1, dr);
}

node Get(int p, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)return t[nod];
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    if(p <= m)return Get(p, nod << 1, st, m);
    return Get(p, nod << 1 | 1, m + 1, dr);
}
void Visit(int nod = 1, int st = 1, int dr = n)
{
    cout << nod << ' ' << t[nod].mn << ' ' << t[nod].smn << ' ' << t[nod].mx << ' ' << t[nod].smx << '\n';
    if(st == dr)return;
    Push(nod, st, dr);
    int m = (st + dr) >> 1;
    Visit(nod << 1, st, m);
    Visit(nod << 1 | 1, m + 1, dr);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i)cin >> a[i];

    Build();

///Push e problema

//    Update_Add(1, 5, 100);
//    for(int i = 1; i <= n; ++i)cout << Query(i, i) << ' ';
//    cout << '\n';
//
//    Visit();
//    cout << "\n\n";
//
//    Update_Min(1, 3, 10);
//    for(int i = 1; i <= n; ++i)cout << Query(i, i) << ' ';
//    cout << '\n';
//
//    Update_Max(3, 5, 20);
//    for(int i = 1; i <= n; ++i)cout << Query(i, i) << ' ';
//    cout << '\n';



//    auto nd = Get(3);
//    cout << nd.mn << ' ' << nd.mx;

    int op, l, r, val;
    while(q --)
    {
        cin >> op;

        if(op == 0)
        {
            cin >> l >> r >> val;
            ++l;
            Update_Min(l, r, val);
        }
        else if(op == 1)
        {
            cin >> l >> r >> val;
            ++l;
            Update_Max(l, r, val);
        }
        else if(op == 2)
        {
            cin >> l >> r >> val;
            ++l;
            Update_Add(l, r, val);
        }
        else
        {
            cin >> l >> r;
            ++l;
            cout << Query(l, r) << '\n';
        }
    }
    return 0;
}
