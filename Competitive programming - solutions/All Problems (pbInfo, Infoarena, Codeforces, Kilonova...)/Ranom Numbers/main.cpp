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
#define VL vector<ll>
using namespace std;
const bool has_test_cases = true;
const int N = 2e5 + 9, Mod = 998244353, Inf = 0x3f3f3f3f;

int n;
string s;
int cnt[5][N];

void solve()
{
    cin >> s;

    FOR(i, 0, size(s) - 1)
        cnt[s[i] - 'A'][i]++;

    ll ans = 0;
    FOR(i, 0, size(s) - 1)
    {
        int mx = 0;
        FOR(j, 1, 4)
            if(cnt[j][size(s) - 1] - cnt[j][i] != 0)
                mx = j;

        ///s[i] = 'A'
        FOR(j, 0, 4)
        {
            if(s[i] - 'A' < mx && j < mx)
                ans = max(ans, pow(10, j) - pow(10, s[i] - 'A'));
            else if(s[i] - 'A' < mx && j >= mx)
            {
                ll candidate = pow(10, j) - pow(10, s[i] - 'A');
                FOR(k, mx + 1, 4)
                    candidate -= 2 * cnt[k][i - 1] * pow(10, k);
                ans = max(ans, candidate);
            }
            else if(s[i] - 'A' >= mx && j < mx)
            {
                ll candidate = pow(10, j) - pow(10, s[i] - 'A');
                FOR(k, mx + 1, s[i] - 'A')
                    candidate += 2 * cnt[k][i - 1] * pow(10, k);
                ans = max(ans, candidate);
            }
            else if(s[i] - 'A' >= mx && j >= mx)
            {
                ll candidate = pow(10, j) - pow(10, s[i] - 'A');
                FOR(k, s[i] - 'A' + 1, j)
                    candidate +=
            }

        }

    }
}

int main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
