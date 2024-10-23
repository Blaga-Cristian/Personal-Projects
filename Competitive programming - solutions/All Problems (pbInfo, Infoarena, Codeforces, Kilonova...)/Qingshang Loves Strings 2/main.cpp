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

int n, m;
string s, t;
bool first, last;

void solve_testcase()
{
    cin >> n >> m;
    cin >> s >> t;

    first = t[0] - '0';
    last = t[m - 1] - '0';

    bool can_add_t = true;
    FOR(i, 0, m - 2)
        if(t[i] == t[i + 1])
            can_add_t = false;

    bool solvable = true;
    FOR(i, 0, n - 2)
        if(s[i] == s[i + 1])
        {
            if(can_add_t && (s[i] != first + '0' && last + '0' != s[i + 1]));
            else solvable = false;
        }

    if(solvable)cout << "Yes\n";
    else cout << "No\n";
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
