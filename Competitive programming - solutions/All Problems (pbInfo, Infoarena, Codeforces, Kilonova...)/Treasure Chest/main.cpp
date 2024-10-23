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

void solve_testcase()
{
    int x, y, k;
    cin >> x >> y >> k;
    if(y <= x)cout << x << '\n';
    else
    {
        if(y - x <= k)cout << y << '\n';
        else cout << y + (y - x - k) << '\n';
    }
}

int main()
{
    int t = 1;
    if(has_test_cases) cin >> t;
    while(t --)
        solve_testcase();
    return 0;
}
