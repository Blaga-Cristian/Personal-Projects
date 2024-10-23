#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
const int N = 5009;

int n, k, a[N];
ll dp[N][2];

int sp[N];
ll C(int i, int j)
{
    return 1LL * (sp[j] - sp[i - 1]) * (sp[j] - sp[i - 1]) * (sp[j] - sp[i - 1]);
}

void compute(int j, int l, int r, int optl, int optr)
{
    if(l > r)return;

    int m = (l + r) >> 1;
    pair<ll, int> best(LLONG_MAX, -1);

    for(int i = optl; i <= min(m, optr); ++i)
        best = min(best, {dp[i - 1][j ^ 1] + C(i, m), i});

    dp[m][j] = best.ff;
    int opt = best.ss;

    compute(j, l, m - 1, optl, opt);
    compute(j, m + 1, r, opt, optr);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n)cin >> a[i];

    FOR(i, 1, n)sp[i] = sp[i - 1] + a[i];

    FOR(i, 1, n)dp[i][0] = LLONG_MAX >> 1;
    FOR(j, 1, k)compute(j & 1, 1, n, 1, n);

    cout << dp[n][k & 1] << '\n';
    return 0;
}
