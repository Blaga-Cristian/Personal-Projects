#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long

using namespace std;
const int N = 400, Mod = 1e9 + 7, V = 5000;

int n, p;
char c[N];

ll mul(ll a, ll b)
{
    return (a * b) % Mod;
}
ll pt_lg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)ret = mul(ret, base);
    return ret;
}

int get(char *p)
{
    int ret = 0;
    for(int i = 0; p[i] != 0 && isdigit(p[i]); ++i)
        ret = ret * 10 + (p[i] - '0');
    return ret;
}
int ln(char *p)
{
    int ret = 0;
    for(int i = 0; p[i] != 0 && isdigit(p[i]); ++i)
        ret ++;
    return ret;
}

int l, h;
int Dfs1(int poz, int maxl, int maxh)
{
    if(c[poz] == '*')
    {
        l = max(l, maxl + 1);
        h = max(h, maxh + 1);
        return poz;
    }

    int a = get(c + poz + 1), len = ln(c + poz + 1);

    if(c[poz] == 'H')
    {
        int nxt = Dfs1(poz + 1 + len, maxl, maxh);
        return Dfs1(nxt + 1, maxl, maxh + a);
    }

    if(c[poz] == 'V')
    {
        int nxt = Dfs1(poz + 1 + len, maxl, maxh);
        return Dfs1(nxt + 1, maxl + a, maxh);
    }
}

ll fact[V], invfact[V];
ll ans = 1;
ll catalan(ll n)
{
    return mul(fact[2 * n], mul(invfact[n], mul(invfact[n], pt_lg(n + 1, Mod - 2))));
}

int chain[N];
int Dfs2(int poz)
{
    chain[poz] = 1;

    if(c[poz] == '*')
        return poz;

    int a = get(c + poz + 1), len = ln(c + poz + 1);
    char val = c[poz];

    int nxt = Dfs2(poz + 1 + len);
    int ret = Dfs2(nxt + 1);

    if(c[poz + 1 + len] == val)chain[poz] += chain[poz + 1 + len];
    else ans = mul(ans, catalan(chain[poz + 1 + len]));

    if(c[nxt + 1] == val)chain[poz] += chain[nxt + 1];
    else ans = mul(ans, catalan(chain[nxt + 1]));

    return ret;
}

struct retType
{
    char type;
    int offset;
    string s1, s2;
};
int pos = 0;
int parseInt()
{
    int ret = 0;
    for(; c[pos] && isdigit(c[pos]); pos ++)
        ret = ret * 10 + c[pos] - '0';
    return ret;
}
retType Dfs3()
{
    char currType = c[pos];
    pos ++;

    if(currType == '*')
        return {'*', 0, "", "*"};

    int k = parseInt();
    retType ret = {currType, k, "", ""};

    retType aux1 = Dfs3();
    if(aux1.type == currType)
    {
        ret.s1 += aux1.s1;
        ret.s1 += currType;
        ret.s1 += to_string(k - aux1.offset);
        ret.s1 += aux1.s2;
    }
    else
    {
        ret.s1 += currType;
        ret.s1 += to_string(k);
        ret.s1 += aux1.s1 + aux1.s2;
    }

    retType aux2 = Dfs3();
    if(aux2.type == currType)
    {
        ret.offset += aux2.offset;
        ret.s1 += aux2.s1;
        ret.s2 += aux2.s2;
    }
    else
        ret.s2 += aux2.s1 + aux2.s2;

    return ret;
}

int main()
{
    cin >> p >> c;
    n = strlen(c);

    if(p == 1)
    {
        int cnt = 0;
        FOR(i, 0, n - 1)
            if(c[i] == '*')
                cnt ++;
        cout << cnt << '\n';
    }
    else if(p == 2)
    {
        Dfs1(0, 0, 0);

        cout << h << ' ' << l << '\n';
    }
    else if(p == 3)
    {
        fact[0] = fact[1] = 1;
        FOR(i, 2, V - 1)fact[i] = mul(fact[i - 1], i);

        invfact[V - 1] = pt_lg(fact[V - 1], Mod - 2);
        FORR(i, V - 2, 0)invfact[i] = mul(invfact[i + 1], i + 1);

        Dfs2(0);

        cout << mul(ans, catalan(chain[0])) << '\n';
    }
    else if(p == 4)
    {
        retType aux = Dfs3();
        cout << aux.s1 + aux.s2 << '\n';
    }
    return 0;
}
