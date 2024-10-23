#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 709;

int n, k, v[N], b[N], dp[N][N];
int lst[N], nxt[N];

signed main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)cin >> v[i];
    for(int i = 1; i <= n; ++i)cin >> b[i];

    for(int i = n; i >= 1; --i)
    {
        if(lst[b[i] + k])nxt[i] = lst[b[i] + k];
        else nxt[i] = n + 1;
        lst[b[i]] = i;
    }

    for(int len = 2; len <= n; len ++)
        for(int i = 1, j = i + len - 1; j <= n; ++i, ++j)
        {
            dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j - 1]));

            if(b[i] + k == b[j])
                dp[i][j] = max(dp[i][j], v[i] + dp[i + 1][j - 1] + v[j]);

            for(int p = i; p <= j; ++p)
                dp[i][j] = max(dp[i][j], dp[i][p] + dp[p + 1][j]);
        }

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            ans = max(ans, dp[i][j]);
    cout << ans << '\n';
    return 0;
}
