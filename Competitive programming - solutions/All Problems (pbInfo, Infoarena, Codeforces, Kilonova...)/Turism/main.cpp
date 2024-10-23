#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define ll long long

using namespace std;
string TASK("turism");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 3e5 + 9, Mod = 1e9 + 7;

int t, n, m, q;
vvi G(N);

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
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


vi ctc;

int lvl[N], low[N], idx;
bool instk[N];
stack<int> stk;
void Dfs(int x)
{
    lvl[x] = low[x] = ++idx;
    stk.push(x);
    instk[x] = true;

    for(auto y : G[x])
    {
        if(!lvl[y])
        {
            Dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y])low[x] = min(low[x], lvl[y]);
    }

    if(low[x] == lvl[x])
    {
        int cnt = 0;
        while(true)
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;

            cnt ++;

            if(x == a)break;
        }
        ctc.pb(cnt);
    }
}

int fact[N], invfact[N];
void Precalc()
{
    fact[0] = 1;
    FOR(i, 1, n)fact[i] = mul(i, fact[i - 1]);

    invfact[n] = PtLg(fact[n], Mod - 2);
    FORR(i, n - 1, 0)invfact[i] = mul(i + 1, invfact[i + 1]);
}
ll aran(ll n, ll k)
{
    if(n < k)return 0;
    return mul(fact[n], invfact[n - k]);
}


int main()
{
    cin >> t;
    cin >> n >> m >> q;

    int a, b;
    FOR(i, 1, m)
    {
        cin >> a >> b;
        G[a].pb(b);
    }

    FOR(i, 1, n)
        if(!lvl[i])
            Dfs(i);

    if(t == 1)
    {
        sort(ctc.begin(), ctc.end());

        vpi v;///ff - marime, ss - cate sunt
        for(auto i : ctc)
        {
            if(v.empty() || i != v.back().ff)v.pb({i, 1});
            else v.back().ss ++;
        }

        vi mem;
        for(auto i : v)mem.pb(i.ff);
        for(auto& i : v)i.ff = 1;

        int sum;
        FOR(i, 1, q)
        {
            sum = 0;
            for(int i = 0; i < v.size(); ++i)
            {
                v[i].ff = mul(v[i].ff, mem[i]);
                sum = add(sum, mul(v[i].ff, v[i].ss));
            }
            cout << sum << '\n';
        }
    }
    else
    {
        Precalc();

        vi ans(q + 1);
        for(auto i : ctc)
            for(int j = 1; j <= i; ++j)
                ans[j] = add(ans[j], aran(i, j));

        FOR(i, 1, q)cout << ans[i] << '\n';
    }
    return 0;
}
