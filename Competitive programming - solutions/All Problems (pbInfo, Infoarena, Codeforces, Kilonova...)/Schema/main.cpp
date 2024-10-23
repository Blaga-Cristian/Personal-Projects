#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2009, G = 5009, Inf = 0x3f3f3f3f;

int n, g, v[N], ans = -Inf, sum;
bool dp[G];

int main()
{
    freopen("schema.in", "r", stdin);
    freopen("schema.out", "w", stdout);

    cin >> n >> g;
    for(int i = 1; i <= n; ++i)cin >> v[i], sum += v[i];

    sort(v + 1, v + n + 1, greater<int>());

    dp[0] = true;
    for(int i = 1; i <= n; ++i)
    {
        /// nu voi folosi v[i]
        sum -= v[i];
        for(int s = g - v[i - 1]; s >= 0; --s)
            if(dp[s])dp[s + v[i - 1]] = true;
        for(int s = 0; s <= g; ++s)
            if(dp[s] && g - sum - s < v[i] && g - sum - s >= 0)ans = max(ans, g - sum - s);
    }

    if(ans == -Inf)
    {
        for(int i = 1; i <= n ; ++i)g -= v[i];
        cout << g;
    }
    else
        cout << ans;

    return 0;
}
