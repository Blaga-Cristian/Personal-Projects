#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 9, LG = 21, Mod = 1e9 + 7;

int n, q, a[N];

int basis[LG + 1], sz;
void insertvector(int x)
{
    for(int i = LG; i >= 0; --i)
    {
        if((x & (1 << i)) == 0)continue;

        if(!basis[i])
        {
            basis[i] = x;
            ++ sz;
            return;
        }

        x ^= basis[i];
    }
}

ll mul(ll a, ll b)
{
    return (a * b) % Mod;
}
ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}

bool check(int x)
{
    for(int i = LG; i >= 0; --i)
        if(x & (1 << i))x ^= basis[i];
    return (x == 0);
}

struct query
{
    int ind, l, x, ans;
};
vector<query> queries;

int main()
{
    cin >> n >> q;
    FOR(i, 1, n)cin >> a[i];

    int l, x;
    FOR(i, 1, q)
    {
        cin >> l >> x;
        queries.pb({i, l, x, -1});
    }

    sort(queries.begin(), queries.end(), [](query a, query b){return a.l < b.l;});
    for(int i = 0, j = 0; i < queries.size(); ++i)
    {
        while(j < queries[i].l)insertvector(a[++ j]);

        if(!check(queries[i].x))queries[i].ans = 0;
        else queries[i].ans = PtLg(2, j - sz);
    }

    sort(queries.begin(), queries.end(), [](query a, query b){return a.ind < b.ind;});

    for(auto e : queries)cout << e.ans << '\n';
    return 0;
}
