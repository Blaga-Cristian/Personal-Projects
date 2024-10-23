#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

//const string TASK("secv8");
//ifstream fin(TASK + ".in");
//ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout

const int N = 2e5 + 9;

struct Treap
{
    int data, priority, sz;
    bool rev;

    Treap *l, *r;

    Treap(int x)
    {
        data = x;
        priority = rand();
        sz = 1;
        rev = false;
        l = r = NULL;
    }
};

int size(Treap* t)
{
    return t == NULL ? 0 : t -> sz;
}

void recalc(Treap* t)
{
    if(t == NULL)return;
    t -> sz = size(t -> l) + size(t -> r) + 1;
}

void prop(Treap *t)
{
    if(t == NULL)return;
    if(t -> rev == 0)return;
    t -> rev = 0;
    swap(t -> l, t -> r);
    if(t -> l)t -> l -> rev ^= 1;
    if(t -> r)t -> r -> rev ^= 1;
}

pair<Treap*, Treap*> split(Treap *t, int left)
{
    if(t == NULL)return {NULL, NULL};
    prop(t);
    if(size(t -> l) >= left)
    {
        auto res = split(t -> l, left);
        t -> l = res.ss;
        recalc(t);
        return {res.ff, t};
    }
    else
    {
        left -= size(t -> l) + 1;
        auto res = split(t -> r, left);
        t -> r = res.ff;
        recalc(t);
        return {t, res.ss};
    }
}

Treap* merge(Treap *a, Treap *b)
{
    if(a == NULL)return b;
    if(b == NULL)return a;
    prop(a), prop(b);
    if(a -> priority < b -> priority)
    {
        a -> r = merge(a -> r, b);
        recalc(a);
        return a;
    }
    else
    {
        b -> l = merge(a, b -> l);
        recalc(b);
        return b;
    }
}

void Dfs(Treap *t)
{
    if(t == NULL)return;
    prop(t);

    Dfs(t -> l);
    cout << t -> data << ' ';
    Dfs(t -> r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    srand(time(NULL));

    int n;bool _;
    cin >> n >> _;

    Treap *t = NULL;

    char op;
    int x, y;
    while(n --)
    {
        cin >> op;

        if(op == 'I')
        {
            cin >> x >> y;

            auto a = split(t, x - 1);
            t = merge(merge(a.ff, new Treap(y)), a.ss);
        }
        else if(op == 'A')
        {
            cin >> x;
            auto a = split(t, x - 1);
            auto b = split(a.ss, 1);
            cout << b.ff -> data << '\n';
            t = merge(a.ff, merge(b.ff, b.ss));
        }
        else if(op == 'R')
        {
            cin >> x >> y;
            auto a = split(t, x - 1);
            auto b = split(a.ss, y - x + 1);
            b.ff -> rev ^= 1;
            t = merge(a.ff, merge(b.ff, b.ss));
        }
        else if(op == 'D')
        {
            cin >> x >> y;
            auto a = split(t, x - 1);
            auto b = split(a.ss, y - x + 1);
            t = merge(a.ff, b.ss);
        }
    }

    Dfs(t);
    return 0;
}
