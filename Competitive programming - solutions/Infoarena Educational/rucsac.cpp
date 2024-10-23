#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back

#define int long long
using namespace std;
const string TASK("rucsac");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 10009, LG = 19, Inf = 0x3f3f3f3f;

int n, g, dp[N];

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> g;

    for(int i = 0; i <= g; ++i)dp[i] = -1;
    dp[0] = 0;

    int w, p;
    for(int i = 1; i <= n; ++i)
    {
        cin >> w >> p;

        for(int s = g - w; s >= 0; --s)
            if(dp[s] != -1)
                dp[s + w] = max(dp[s + w], dp[s] + p);
    }

    int ans = 0;
    for(int i = 0; i <= g; ++i)ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}