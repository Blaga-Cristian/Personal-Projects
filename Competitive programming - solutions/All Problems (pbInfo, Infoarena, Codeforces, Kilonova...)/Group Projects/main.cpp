#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long

using namespace std;
const int N = 201, K = 1001, Mod = 1e9 + 7;

int n, k, a[N];
int dp[N][N][K];
///dp[n][s][stress] =
///int cate moduri pot pune cei n copii, si am s seturi deschise cu un stres total de strees

ll add(ll x, ll y)
{
    ll z = x + y;
    if(z >= Mod)z -= Mod;
    if(z < 0)z += Mod;
    return z;
}
ll mul(ll x, ll y)
{
    return (x * y) % Mod;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n)cin >> a[i];

    sort(a + 1, a + n + 1);

    dp[1][1][0] = 1;
    dp[1][0][0] = 1;
    FOR(i, 2, n)
        FOR(j, 0, i)
            FOR(t, 0, k)
            {
                int v = dp[i - 1][j][t];
                int val = t + j * (a[i] - a[i - 1]);
                if(val > k)continue;
                dp[i][j][val] = add(dp[i][j][val], v);
                dp[i][j][val] = add(dp[i][j][val], mul(j, v));
                dp[i][j + 1][val] = add(dp[i][j + 1][val], v);
                if(j > 0)dp[i][j - 1][val] = add(dp[i][j - 1][val], mul(j, v));
            }

    int ans = 0;
    FOR(i, 0, k)ans = add(ans, dp[n][0][i]);
    cout << ans << '\n';
    return 0;
}
