#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second

#define ll long long
//#define int long long
using namespace std;
const int N = 2e5 + 9, M = 1e9 + 123, P = 1e6 + 3;

int n, k;
int hsh[N], pt[N], inv[N], sz = 0;

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= M)x -= M;
    if(x < 0)x += M;
    return x;
}
ll mul(ll a, ll b)
{
    return (a * b) % M;
}
ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    pt[0] = 1;
    FOR(i, 1, n)pt[i] = mul(pt[i - 1], P);
    inv[n] = PtLg(pt[n], M - 2);
    FORR(i, n - 1, 0)inv[i] = mul(inv[i + 1], P);

    char op;
    int x;
    FOR(i, 1, n)
    {
        cin >> op;

        if(op == '+')
        {
            cin >> x;

            v[sz] = x;
            hsh[sz] = mul(x, p[sz]);
            ++ sz;
        }
        else --sz;

        if(sz <= 1)cout << "0\n";
        else
        {
            if(v[sz] != v[0])cout << "0\n";
            else
            {

            }
        }
    }
    return 0;
}
