#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define pb push_back
#define vvi vector<vi>
#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long

using namespace std;
const string TASK("poze");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 309, PC = 30011, PL = 30013, M1 = 1e9 + 123, M2 = 1e9 + 321;
const bool test_cases = true;

int n, m, k, a[N][N];

ll add(ll a, ll b, ll M)
{
    ll x = a + b;
    if(x >= M)x -= M;
    if(x < 0)x += M;
    return x;
}

ll mul(ll x, ll y, ll M)
{
    return (x * y) % M;
}

ll PtLg(ll base, ll exp, ll M)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base, M))
        if(exp & 1)
            ret = mul(ret, base, M);
    return ret;
}

int ptc1[N], ptl1[N], hsh1[N][N];
int ptc2[N], ptl2[N], hsh2[N][N];
void Precalc()
{
    ptc1[0] = 1;
    FOR(i, 1, n)ptc1[i] = mul(ptc1[i - 1], PC, M1);

    ptc2[0] = 1;
    FOR(i, 1, n)ptc2[i] = mul(ptc2[i - 1], PC, M2);

    ptl1[0] = 1;
    FOR(i, 1, m)ptl1[i] = mul(ptl1[i - 1], PL, M1);

    ptl2[0] = 1;
    FOR(i, 1, m)ptl2[i] = mul(ptl2[i - 1], PL, M2);

    FOR(i, 1, n)
        FOR(j, 1, m)
        {
            hsh1[i][j] = add(mul(hsh1[i - 1][j], PC, M1), a[i][j], M1);
            hsh2[i][j] = add(mul(hsh2[i - 1][j], PC, M2), a[i][j], M2);
        }
}

int find_nr(int len)
{
    map<pair<int, int>, int> mp;

    FOR(i, 1, n - len + 1)
    {
        int cur1 = 0;
        FOR(j, 1, len - 1)cur1 = add(mul(cur1, PL, M1), add(hsh1[i + len - 1][j], - mul(hsh1[i - 1][j], ptc1[len], M1), M1), M1);

        int cur2 = 0;
        FOR(j, 1, len - 1)cur2 = add(mul(cur2, PL, M2), add(hsh2[i + len - 1][j], - mul(hsh2[i - 1][j], ptc2[len], M2), M2), M2);

        FOR(j, 1, m - len + 1)
        {
            cur1 = add(mul(cur1, PL, M1), add(hsh1[i + len - 1][j + len - 1], - mul(hsh1[i - 1][j + len - 1], ptc1[len], M1), M1), M1);
            cur1 = add(cur1, - mul(add(hsh1[i + len - 1][j - 1], - mul(hsh1[i - 1][j - 1] , ptc1[len], M1), M1), ptl1[len], M1), M1);

            cur2 = add(mul(cur2, PL, M2), add(hsh2[i + len - 1][j + len - 1], - mul(hsh2[i - 1][j + len - 1], ptc2[len], M2), M2), M2);
            cur2 = add(cur2, - mul(add(hsh2[i + len - 1][j - 1], - mul(hsh2[i - 1][j - 1] , ptc2[len], M2), M2), ptl2[len], M2), M2);

            mp[{cur1, cur2}] ++;
        }
    }

    int ret = 0;
    for(auto [_, cnt] : mp)
        ret = max(ret, cnt);
    return ret;
}

void solve()
{
    cin >> n >> m >> k;

    FOR(i, 1, n)
        FOR(j, 1, m)
            cin >> a[i][j];

    Precalc();

    int st = 0, dr = min(n, m), m, pos;
    while(st <= dr)
    {
        m = (st + dr) >> 1;
        if(find_nr(m) >= k)
        {
            pos = m;
            st = m + 1;
        }
        else dr = m - 1;
    }

    cout << pos << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    if(test_cases)cin >> t;

    while(t --)
        solve();
    return 0;
}
