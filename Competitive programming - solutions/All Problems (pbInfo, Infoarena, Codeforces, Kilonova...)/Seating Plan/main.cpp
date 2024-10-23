#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N = 1e5 + 9, Mod = 998244353;
const bool test_cases = true;

int n, k;

int s(int x)
{
    return x * (x - 1) / 2;
}

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * y) % Mod;
}

ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}

int fact[N], invfact[N];
void Precalc()
{
    fact[0] = 1;
    for(int i = 1; i < N; ++i)fact[i] = mul(i, fact[i - 1]);

    invfact[N - 1] = PtLg(fact[N - 1], Mod - 2);
    for(int i = N - 2; i >= 0; --i)invfact[i] = mul(i + 1, invfact[i + 1]);
}
ll comb(ll n, ll k)
{
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

void solve()
{
    cin >> n >> k;

    ///cazul 1, row-urile de la capat sunt 0
    ///avem 2 * (k - 1) sume de tip s(t)

//    if(n == k + 1)
//    {
//        cout << "0 1\n";
//        return;
//    }

    int y = n - 2 * k * (n / (2 * k)), x = 2 * k - y, t = n / (2 * k);
    ///x sunt t, y sunt t + 1

    int cst = x * s(t) + y * s(t + 1);
    cout << cst << ' ';

    int ans = 0;
    ///k - 1 grupuri in mijloc
    ///f - grupare 2t, g - grupare 2t + 1, h - grupare 2t + 2
    ///caz 1, randurile de la geam sunt goale
    {
        for(int g = 0; g < k; ++g)
        {
            if((x - g) % 2 == 1 || (y - g) % 2 == 1)continue;

            int f = (x - g) / 2, h = (y - g) / 2;
            if(f >= 0 && h >= 0 && f + g + h == k - 1)
            {
                ans += mul(comb(f + g + h, g), comb(f + h, f));
//                cout << f << ' ' << g << ' ' << h << '\n';
            }
        }
    }

    for(int i = 0; i < 4; ++i)
    {
        if(i & 1)y --;
        else x --;
        if(i & 2)y --;
        else x --;

//        cout << x << ' ' << y << '\n';

        for(int g = 0; g < k; ++g)
        {
            if((x - g) % 2 == 1 || (y - g) % 2 == 1)continue;

            int f = (x - g) / 2, h = (y - g) / 2;
            if(x >= 0 && y >= 0 && f >= 0 && h >= 0 && f + g + h == k - 1)
            {
                ans += mul(comb(f + g + h, g), comb(f + h, f));
//                cout << f << ' ' << g << ' ' << h << ' ' << i << '\n';
            }
        }

        if(i & 1)y ++;
        else x ++;
        if(i & 2)y ++;
        else x ++;
    }

    cout << ans << '\n';

//    cout << x << ' ' << y << ' ' << t << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Precalc();

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
