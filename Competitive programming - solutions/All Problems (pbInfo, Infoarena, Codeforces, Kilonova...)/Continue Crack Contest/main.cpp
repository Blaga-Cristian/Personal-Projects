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
#define int long long
using namespace std;
const int N = 1e6 + 9;
const int Mod = 1e9 + 7;
const bool test_cases = false;

int n, k;
vi dp1, dp2;

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

void solve()
{
    cin >> n >> k;
    dp1 = dp2 = vi(k + 1);

    dp1[1] = k;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            dp2[j] = add(mul((i - 1), dp1[j]), ///ma conectez la un nod precedent
                        mul((i - 1), mul((k - j + 1), dp1[j - 1])));///aleg o noua culoare
        }
        swap(dp1, dp2);
    }

    int ans = 0;
    for(int j = 1; j <= k; ++j)cout << dp1[j] << ' ';
    cout << ans << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

//    Ciur();

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
