#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back

using namespace std;
const bool test_cases = true;
const int N = 1e6 + 9;

ll n, a[N];
ll dp[N], cnt[N];
ll viz[N];

void solve()
{
    cin >> n;

    FOR(i, 0, n + 1)
        viz[i] = dp[i] = cnt[i] = 0;

    FOR(i, 1, n)
    {
        cin >> a[i];
        cnt[a[i]] ++;
        viz[a[i]] = 1;
    }

    FOR(i, 1, n)
        if(viz[i])
            for(int j = i + i; j <= n; j += i)viz[j] = 1;

//    FOR(i, 1, n)
//        if(cnt[i])cout << i << ' ' << cnt[i] << '\n';

    FORR(i, n, 1)
    {
        ll nr = cnt[i];
        for(int j = i + i; j <= n; j += i)nr += cnt[j];
        dp[i] = nr * (nr - 1) / 2;
        for(int j = i + i; j <= n; j += i)dp[i] -= dp[j];
    }

    ll ans = 0;
    FOR(i, 1, n)
        if(!viz[i])
            ans += dp[i];


    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    if(test_cases) cin >> t;
    while(t --)
        solve();
    return 0;
}
