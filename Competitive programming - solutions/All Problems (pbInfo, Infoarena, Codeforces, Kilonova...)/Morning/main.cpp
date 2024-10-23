#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define VP vector<PI>
#define VVP vector<VP>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long
#define ull unsigned ll
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
const bool has_test_cases = true;
const int N = 2e5 + 9;

int n, a[N];

void solve()
{
    cin >> n;

    FOR(i, 1, n)cin >> a[i];

    int prv = 0;
    ll ans = 0;
    FOR(i, 2, n)
        if(log2(a[i - 1]) + prv > log2(a[i]))
        {
            int x = prv + ceil(log2(a[i - 1]) - log2(a[i]));
            ans += x;
            prv = x;
        }
        else prv = 0;

    cout << ans << '\n';
}

int main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_test_cases) cin >> t;
    while(t --)
        solve();
    return 0;
}
