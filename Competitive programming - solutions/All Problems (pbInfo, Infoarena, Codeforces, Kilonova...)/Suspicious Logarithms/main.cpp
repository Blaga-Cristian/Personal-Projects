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
const bool has_multiple_testcases = false;
const int N = 1e5 + 9, Mod = 1e9 + 7;

int q;
ll p[63][63];

inline ll get_g(ll& l, ll& r, ll val)
{
    ll ret = 0;
    ll lb, rb;

    int start = max(1, (int)(log2(l) / log2(val) - 1)), stop = log2(r) / log2(val) + 1;
    FOR(i, start, stop)
    {
        if(p[val][i - 1] > LLONG_MAX / val)break;

        ll st = p[val][i], dr = p[val][i + 1] - 1;
        if(st > LLONG_MAX / val)dr = LLONG_MAX;

        lb = max(st, l), rb = min(dr, r);
        if(lb <= rb)ret = (ret + (rb - lb + 1) % Mod * i % Mod) % Mod;
    }

    return ret;
}

inline ll solve(ll& l, ll& r)
{
    ll ret = 0;
    ll lb, rb;

    int start = max(2, (int)(log2(l) - 1)), stop = log2(r) + 1;
    FOR(i, start, stop)
    {
        if(p[2][i] > r)break;

        lb = max(p[2][i], l), rb = min(p[2][i + 1] - 1, r);
        if(lb <= rb)ret = (ret + get_g(lb, rb, i)) % Mod;
    }
    return ret;
}

void precalc()
{
    FOR(i, 1, 62)
    {
        p[i][0] = 1;
        FOR(j, 1, 62)
            p[i][j] = p[i][j - 1] * i;
    }
}

void solve_testcase()
{
    cin >> q;

    precalc();

    ll l, r;
    while(q --)
    {
        cin >> l >> r;
        cout << solve(l, r) << '\n';
    }
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
