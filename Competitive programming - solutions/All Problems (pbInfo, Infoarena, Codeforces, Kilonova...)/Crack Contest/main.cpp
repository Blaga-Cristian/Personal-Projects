#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back
#define ll long long
using namespace std;
const int N = 1e5 + 9;
const int Mod = 1e9 + 7;
const bool test_cases = false;

int n, x, a[N];


bool p[N];
int d[N];
void Ciur()
{
    p[0] = p[1] = true;
    d[0] = d[1] = 1;

    for(int i = 2; i < N; ++i)
        if(!p[i])
    {
        d[i] = i;
        for(int j = 2 * i; j < N; j += i)
        {
            p[j] = true;
            d[j] = i;
        }
    }
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
    for(; exp; exp >>= 1, base *= base)
        if(exp & 1)
            ret *= base;
    return ret;
}

int get_sum(int x)
{
    int ret = 0;
    for(int i = 1; i * i <= x; ++i)
        if(x % i == 0)
    {
        ret += i;
        if(i * i != x)ret += x / i;
    }
    return ret;
}

map<int, int> mp;

void solve()
{
    cin >> n >> x;

    for(int i = 1; i <= n; ++i)cin >> a[i];

    int ans = 0, nr1 = 0;

    for(int i = 1; i <= n; ++i)
    {
        if(a[i] == 1)
        {
            nr1 ++;
            continue;
        }


    }

    cout << ans << '\n';
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Ciur();

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
