#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 250009, LG = 19;
const ll V = 1000000000000000009;

int n, k, ST[26][LG][N], a, b, x, q, op;
ll ALL[26][N];
char s[N], c, y;

void precalc()
{
    for(int i = 1; i <= n; ++i)
    {
        ST[s[i] - 'a'][0][i] = 1;
        ALL[s[i] - 'a'][0] ++;
    }

    for(int k = 1; (1 << k) <= n; ++k)
        for(int c = 0; c <= 25; ++c)
            for(int i = 1; i + (1 << k) - 1 <= n; ++i)
                ST[c][k][i] = ST[c][k - 1][i] + ST[c][k - 1][i + (1 << (k - 1))];

    for(int c = 0; c <= 25; ++c)
        for(int i = 1; i <= 64; ++i)
            ALL[c][i] = ALL[c][i - 1] * 2;
}
int query(int a, int b, int tip)
{
    int ret = 0;
    for(int i = LG - 1; i >= 0; --i)
        if(a + (1 << i) - 1 <= b)
        {
            ret += ST[tip][i][a];
            a += (1 << i);
        }

    return ret;
}
ll allquery(ll nr, int tip)
{
    ll ret = 0;
    for(int i = 62; i >= 0; --i)
        if((1LL << i) <= nr)
        {
            ret += ALL[tip][i];
            nr -= (1LL << i);
        }

    return ret;
}
ll query_on_period(ll a, ll b, int tip)
{
    ll dif = a;
    a = (a - 1) % n + 1;
    dif -= a;
    b -= dif;


    if(b <= n)return query(a, b, tip);
    else if(b <= 2 * n)return query(a, n, tip) + query(1, b - n, tip);
    return query(a, n, tip) + allquery((b - 1)/ n - 1, tip) + query(1, (b - 1) % n + 1, tip);
}

struct node
{
    int cnt;
    node *l, *r;

    node() : cnt(0), l(0), r(0)
    {}
};

node* roots[26];

void Update(node* nod, ll st, ll dr, ll poz, int val)
{
    if(st == dr)
    {
        nod->cnt += val;
        return;
    }

    ll mij = (st + dr) >> 1;
    if(poz <= mij)
    {
        if(!nod->l)nod->l = new node();
        Update(nod->l, st, mij, poz, val);
    }
    else
    {
        if(!nod->r)nod->r = new node();
        Update(nod->r, mij + 1, dr, poz, val);
    }

    nod->cnt = 0;
    if(nod->l)nod->cnt += nod->l->cnt;
    if(nod->r)nod->cnt += nod->r->cnt;
}
ll TreeQuery(node* nod, ll st, ll dr, ll a, ll b)
{
    if(a <= st && dr <= b)
        return nod->cnt;

    ll mij = (st + dr) >> 1;
    if(b <= mij)
    {
        if(!nod->l)return 0;
        return TreeQuery(nod->l, st, mij, a, b);
    }
    else if(a > mij)
    {
        if(!nod->r)return 0;
        return TreeQuery(nod->r, mij + 1, dr, a, b);
    }
    else
    {
        ll ret = 0;
        if(nod->l)ret += TreeQuery(nod->l, st, mij, a, b);
        if(nod->r)ret += TreeQuery(nod->r, mij + 1, dr, a, b);

        return ret;
    }
}

unordered_map<ll, char> mp;

int main()
{
    freopen("perioade.in", "r", stdin);
    freopen("perioade.out", "w", stdout);

    cin >> n >> k;
    cin.get();
    cin.get(s + 1, N);
    precalc();
    for(int i = 0; i <= 25; ++i)roots[i] = new node();

    Update(roots[0], 1, V, 999, 1);
    Update(roots[0], 1, V, 103, 1);

    cin >> q;
    while(q --)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> x >> y;
            int chr = s[(x - 1) % n + 1];
            if(mp.count(x))chr = mp[x];

            Update(roots[chr - 'a'], 1, V, x, -1);
            Update(roots[y - 'a'], 1, V, x, 1);

            mp[x] = y;
        }
        else
        {
            cin >> a >> b >> c;
            cout << query_on_period(a, b, c - 'a') + TreeQuery(roots[c - 'a'], 1, V, a, b) << '\n';
        }
    }
    return 0;
}
