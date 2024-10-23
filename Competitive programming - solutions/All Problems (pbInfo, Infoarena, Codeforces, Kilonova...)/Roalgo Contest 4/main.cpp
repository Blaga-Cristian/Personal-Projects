#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define pb push_back
#define vvi vector<vi>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define all(v) (v).begin(), (v).end()
#define int long long

using namespace std;
const int N = 109, V = 709, Mod = 998244353;

int n, a[N], dp[N][V * N / 2], fact[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    FOR(i, 1, n)cin >> a[i];

    fact[0] = 1;
    FOR(i, 1, n)fact[i] = (fact[i - 1] * i) % Mod;

    int sum = 0;
    FOR(i, 1, n)sum += a[i];

    if(sum % 2 == 1)
    {
        cout << "0\n";
        return 0;
    }

    dp[0][0] = 1;
    FOR(i, 1, n)
        FORR(j, n, 1)
            FORR(s, sum / 2, a[i])
                dp[j][s] = (dp[j][s] + dp[j - 1][s - a[i]]) % Mod;

    int ans = 0;
    FOR(i, 1, n)
        ans = (ans + ((dp[i][sum / 2] * fact[i]) % Mod * fact[n - i]) % Mod) % Mod;

    cout << ans << '\n';
    return 0;
}
