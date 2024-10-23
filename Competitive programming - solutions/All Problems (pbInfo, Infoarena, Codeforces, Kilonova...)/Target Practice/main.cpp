#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define pb push_back
#define VL vector<ll>
#define VI vector<int>
#define VVI vector<VI>

using namespace std;
const bool testcase = false;
const int N = 2e5 + 9;

ll n, m, k;
map<int, bool> is_target


void solve()
{
    cin >> n >> m >> k;

    int posf = 0;
    FOR(i, 1, n)
    {
        if(s[i] == 'L')posf --;
        if(s[i] == 'R')posf ++;
        if(s[i] == 'F')
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int t = 1;
    if(testcase)cin >> t;
    while(t --)
        solve();
    return 0;
}
