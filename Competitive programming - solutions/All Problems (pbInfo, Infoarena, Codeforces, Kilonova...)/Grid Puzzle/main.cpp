#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

//#define int long long
using namespace std;
const int N = 2e5 + 9, Inf = 0x3f3f3f3f;
const bool test_cases = true;

int n, a[N], dp[N][2][2], sp[N][2][2];

void solve()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i];

    vi vec;
    FOR(i, 1, n)if(a[i] <= 4)vec.pb(a[i]);

    if(vec.empty())
    {
        cout << n << '\n';
        return;
    }

    FOR(i, 0, n)FOR(b1, 0, 1)FOR(b2, 0, 1)dp[i][b1][b2] = Inf;

    if(vec[0] == 0)dp[0][0][0] = 0;
    else if(vec[0] <= 2)dp[0][1][0] = 1;
    else dp[0][1][1] = 2;

    FOR(b1, 0, 1)
        FOR(b2, 0, 1)
            sp[0][b1][b2] = dp[0][b1][b2];

    FOR(i, 1, vec.size() - 1)
    {
        FOR(b1, 0, 1)
            FOR(b2, 0, 1)
            {
                int x = vec[i];
                if(b2)x = min(2, x);
                if(b1)x = min(0, x - 2);

                if(x == 0)dp[i][0][0] = min(dp[i][0][0], sp[i - 1][b1][b2]);
                else if(x <= 2 && !b1)dp[i][1][0] = min(dp[i][0][0], sp[i - 1][b1][b2] + 1);
                else if(x <= 2 && b1)dp[i][0][1] = min(dp[i][0][1], sp[i - 1][b1][b2] + 1);
                else if(x > 2)dp[i][1][1] = min(dp[i][1][1], sp[i - 1][b1][b2] + 2);
            }

        FOR(b1, 0, 1)
            FOR(b2, 0, 1)
                sp[i][b1][b2] = min(dp[i][b1][b2], sp[i - 1][b1][b2] + 1);
    }

    int ans = n;
    FOR(i, 0, vec.size() - 1)
        FOR(b1, 0, 1)
            FOR(b2, 0, 1)
                ans = min(ans, dp[1][b1][b2] + n - i - 1);

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
