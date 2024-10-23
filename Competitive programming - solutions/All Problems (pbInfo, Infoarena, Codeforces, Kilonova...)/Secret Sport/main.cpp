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
const int N = 1e5 + 9;

void solve_testcase()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    cout << s[s.size() - 1] << '\n';
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
