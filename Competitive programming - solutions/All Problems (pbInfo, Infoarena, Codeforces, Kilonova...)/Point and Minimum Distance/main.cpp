#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VB vector<bool>
#define VVP vector<VP>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll

using namespace std;
const bool has_test_cases = true;
const int N = 109;

int n, a[2 * N];

void solve_testcase()
{
    cin >> n;
    FOR(i, 1, 2 * n)
        cin >> a[i];

    ll ans = 0;

    sort(a + 1, a + 2 * n + 1);
    VP rez;
    PI lst = {a[1], a[2 * n]}, nxt;
    int st = 2, dr = 2 * n - 1;
    while(st < dr)
    {
        nxt = {a[st], a[dr]};
        ans += nxt.F - lst.F + lst.S - nxt.S;
        rez.pb(lst);
        lst = nxt;
        st ++;
        dr --;
    }
    rez.pb(lst);

    cout << ans << '\n';
    for(auto i : rez)
        cout << i.F << ' ' << i.S << '\n';
}

int main()
{
    int t = 1;
    if(has_test_cases) cin >> t;
    while(t --)
        solve_testcase();
    return 0;
}
