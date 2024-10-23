#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
const bool has_testcases = true;
const int N = 2e5 + 9;

int n, m, a[N], b[N];


void solve_testcase()
{
    cin >> n >> m;
    FOR(i, 1, n)cin >> a[i];
    FOR(i, 1, m)cin >> b[i];

    sort(b + 1, b + m + 1);
    int p = m;

    FOR(i, 1, n)
    {
        while(p >= 1 && b[p] >= a[i])cout << b[p --] << ' ';
        cout << a[i] << ' ';
    }

    while(p >= 1)cout << b[p --] << ' ';

    cout << '\n';
}

int main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_testcases) cin >> t;
    while(t --)
        solve_testcase();
    return 0;
}
