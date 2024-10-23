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
#define ll long long
#define ull unsigned ll
#define VL vector<ll>
using namespace std;
const bool has_test_cases = true;
const int N = 3e5 + 9, Mod = 998244353, Inf = 0x3f3f3f3f;

int n;
ll a[N], sp[N];

void solve()
{
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
        sp[i] = sp[i - 1] + a[i];
    }

    ll cur = 0, poz = -1, mn = LLONG_MAX, pozmn = -1;
    FOR(i, 1, n)
    {
        if(cur + a[i] >= 0)
        {
            cur = 0;
            poz = -1;
        }
        else if(cur == 0 && a[i] < 0)
        {
            cur = a[i];
            poz = i;
        }
        else
            cur += a[i];

        if(cur < mn)
        {
            mn = cur;
            pozmn = poz;
        }
    }

    cout << sp[pozmn - 1] << '\n';
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
