#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
//#define int long long

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int random(int st, int dr)
{
    uniform_int_distribution<int> dist(st, dr);
    return dist(rng);
}

struct treap // implicit key treap
{
    int prior, val, cnt;
    bool reversed;
    treap *l, *r;
    treap(int val) : val(val), prior(random(1, 1e9)), cnt(1), l(nullptr), r(nullptr), reversed(false) {}
};

int cnt(treap *t)
{
    return t ? t->cnt : 0;
}

void upd(treap *&t)
{
    if (t)
    {
        t->cnt = cnt(t->l) + cnt(t->r) + 1;
        if (t->reversed)
        {
            swap(t->l, t->r);
            if (t->l)
            {
                t->l->reversed ^= 1;
            }
            if (t->r)
            {
                t->r->reversed ^= 1;
            }
            t->reversed = false;
        }
    }
}

void merge(treap *&t, treap *l, treap *r)
{
    if (!l || !r)
    {
        t = (l ? l : r);
        return;
    }
    upd(l), upd(r);
    if (r->prior > l->prior)
    {
        merge(r->l, l, r->l);
        t = r;
    }
    else
    {
        merge(l->r, l->r, r);
        t = l;
    }
    upd(t);
}

void split(treap *t, treap *&l, treap *&r, int key, int add = 0)
{
    if (!t)
    {
        l = r = nullptr;
        return;
    }
    upd(t);
    int curr_key = add + cnt(t->l) + 1;
    if (curr_key <= key)
    {
        split(t->r, t->r, r, key, add + cnt(t->l) + 1);
        l = t;
        upd(l);
    }
    else
    {
        split(t->l, l, t->l, key, add);
        r = t;
        upd(r);
    }
}

void insert(treap *&t, int pos, int val)
{
    treap *adam1, *adam2;
    adam1 = adam2 = nullptr;
    split(t, adam1, adam2, pos);
    treap *je = new treap(val);
    merge(adam1, adam1, je);
    merge(t, adam1, adam2);
}

void reverse(treap *&t, int st, int dr)
{
    if (st > dr)
    {
        return;
    }
    treap *adam1, *adam2, *adam3;
    adam1 = adam2 = adam3 = nullptr;
    split(t, adam1, adam2, st - 1);
    split(adam2, adam2, adam3, (dr - st + 1));
    adam2->reversed ^= 1;
    merge(adam2, adam1, adam2);
    merge(t, adam2, adam3);
}

void del(treap *&t, int st, int dr)
{
    if (st > dr)
    {
        return;
    }
    treap *adam1, *adam2, *adam3;
    adam1 = adam2 = adam3 = nullptr;
    split(t, adam1, adam2, st - 1);
    split(adam2, adam2, adam3, (dr - st + 1));
    merge(t, adam1, adam3);
}

int kth(treap *t, int k)
{
    treap *adam1, *adam2, *adam3;
    adam1 = adam2 = adam3 = nullptr;
    split(t, adam1, adam2, k);
    split(adam1, adam3, adam1, k - 1);
    int ans = adam1->val;
    merge(adam1, adam3, adam1);
    merge(t, adam1, adam2);
    return ans;
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    treap *t = nullptr;
    int q, bullshit;
    cin >> q >> bullshit;
    while (q--)
    {
        char type;
        cin >> type;
        if (type == 'I')
        {
            int pos, val;
            cin >> pos >> val;
            --pos;
            insert(t, pos, val);
        }
        if (type == 'A')
        {
            int pos;
            cin >> pos;
            cout << kth(t, pos) << '\n';
        }
        if (type == 'R')
        {
            int st, dr;
            cin >> st >> dr;
            reverse(t, st, dr);
        }
        if (type == 'D')
        {
            int st, dr;
            cin >> st >> dr;
            del(t, st, dr);
        }
    }
    for (int i = 1; i <= cnt(t); ++i)
    {
        cout << kth(t, i) << ' ';
    }
}
