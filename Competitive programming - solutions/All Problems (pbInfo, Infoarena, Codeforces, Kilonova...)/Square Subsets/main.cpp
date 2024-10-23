#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define ll long long
#define ull unsigned ll
#define pb push_back
#define pii pair<ll, ll>
#define ff first
#define ss second
using namespace std;
const string TASK("bsir");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout
const int N = 2e5 + 9, LG = 61, Mod = 30103;
const bool test_cases = false;

ll n;

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

ll ans[LG];

void solve()
{
    cin >> n;

    ll inv3 = PtLg(3, Mod - 2);
    ans[0] = ans[1] = 0;
    for(int i = 2; i < LG; ++i)
    {
        if(i % 2 == 0)ans[i] = add(mul(2, ans[i - 1]), PtLg(2, i - 1));
        else ans[i] = add(mul(2, ans[i - 1]), mul(2, mul(add(PtLg(2, i - 1), - 1), inv3)));
    }

    int ret = 0, pos = 0;
    for(int i = LG - 1; i >= 0; --i)
        if(n & (1LL << i))
        {
            ret = add(ret, ans[i]);
            if(pos != 0)
            {
                if(__builtin_popcount(pos) == __builtin_popcount(pos + 1))ret = add(ret, n);///primul caz, formeaza pal cu tot sirul
                else
                {
                    if(i == 1)ret = (ret + 2) % Mod;
                    else ret = (ret + (2 * ((((PtLg(2, i + 2) - 1 + Mod) % Mod) * inv3) % Mod)) % Mod +
                           ((n ^ (1LL << i)) % Mod - PtLg(2, i) + Mod) % Mod) % Mod;
                }
            }
            pos ^= (1LL << i);
            n ^= (1LL << i);
        }

    cout << ret << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
