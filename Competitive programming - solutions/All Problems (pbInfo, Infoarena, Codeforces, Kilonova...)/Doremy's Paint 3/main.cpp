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

int n, nr[3], a[N];


void solve_testcase()
{
    cin >> n;
    map<int, int> mp;
    FOR(i, 1, n)
    {
        cin >> a[i];
        mp[a[i]] ++;
    }

    if(mp.size() == 1)
    {
        cout << "Yes\n";
        return;
    }
    if(mp.size() > 2)
    {
        cout << "No\n";
        return;
    }

    nr[1] = nr[2] = 0;
    int cnt = 0;
    for(auto i : mp)
        nr[++cnt] = i.S;

    if(max(nr[1], nr[2]) - min(nr[1], nr[2]) > 1)cout << "No\n";
    else cout << "Yes\n";
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
