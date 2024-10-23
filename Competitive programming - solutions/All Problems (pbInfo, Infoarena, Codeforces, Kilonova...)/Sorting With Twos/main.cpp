#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VVP vector<VP>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll


using namespace std;
const bool has_multiple_testcases = true;
const int N = 30;

int n, a[N];

void solve_testcase()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i];
    bool ok = true;

    int p = 4;
    for(; p <= n; p *= 2)
        FOR(i, p / 2 + 1, p - 1)
            if(a[i] > a[i + 1])
                ok = false;

    FOR(i, p / 2 + 1, n - 1)
        if(a[i] > a[i + 1])
            ok = false;

    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_multiple_testcases) cin >> t;
    while(t --)
        solve_testcase();
    return 0;
}
