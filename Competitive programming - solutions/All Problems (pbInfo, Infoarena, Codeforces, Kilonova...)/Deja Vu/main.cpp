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

int n, q, a[N], x[N], order[31], first[31], sz;

void solve_testcase()
{
    cin >> n >> q;

    fill(order, order + 31, 0);
    fill(first, first + 31, 0);
    sz = 0;

    FOR(i, 1, n)cin >> a[i];
    FOR(i, 1, q)cin >> x[i];

    FOR(i, 1, q)
        if(first[x[i]] == 0)
        {
            first[x[i]] = i;
            order[++sz] = x[i];
        }

    FOR(i, 1, n)
        FOR(j, 1, sz)
            if(a[i] % (int)pow(2, order[j]) == 0)
                a[i] += pow(2, order[j] - 1);

    FOR(i, 1, n)
        cout << a[i] << ' ';
    cout << '\n';
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
