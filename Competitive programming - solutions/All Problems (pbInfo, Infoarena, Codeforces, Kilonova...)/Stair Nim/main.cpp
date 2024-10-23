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
const bool has_multiple_testcases = true;
const int N = 2e5 + 9;

void solve_testcase()
{
    int n, x, xr = 0;
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> x;
        if(i % 2 == 0)xr ^= x;
    }

    if(xr != 0)cout << "first\n";
    else cout << "second\n";
}

int main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_multiple_testcases)cin >> t;
    while(t --)
        solve_testcase();
    return 0;
}
