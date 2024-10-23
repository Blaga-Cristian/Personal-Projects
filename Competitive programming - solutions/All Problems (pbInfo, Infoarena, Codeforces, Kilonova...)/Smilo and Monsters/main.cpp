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
const int N = 2e5 + 9;

int n, a[N];

void solve_testcase()
{
    cin >> n;
    FOR(i, 1, n)cin >> a[i];

    sort(a + 1, a + n + 1);

    int ans = 0;

    int st = 1, dr = n;
    ll x = 0;
    while(st <= dr)
    {
        //cout << st << ' ' << dr << ' ' << x << ' ' << ans << '\n';

        if(st == dr)
        {
            a[st] -= x;
            if(a[st] == 1)
                ans += 1 + (x != 0);
            else if(a[st] % 2 == 0)
                ans += 1 + a[st] / 2;
            else if(a[st] % 2 == 1)
                ans += 1 + (a[st] + 1) / 2;
            a[st] = 0;
        }
        else if(a[st] + x >= a[dr])
        {
            a[st] -= a[dr] - x;
            ans += a[dr] - x;
            ans ++;
            x = 0;
            a[dr] = 0;
        }
        else if(a[st] + x < a[dr])
        {
            x += a[st];
            ans += a[st];
            a[st] = 0;
        }

        if(a[st] == 0)st ++;
        if(a[dr] == 0)dr --;
    }

    cout << ans << '\n';
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