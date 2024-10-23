#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pb push_back
#define ll long long

using namespace std;
const string TASK("skill-issue");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 2003, K = 5003, Mod = 1e9 + 7, B = 60;///To change

int n, m, k, q, pt2[N * N];
ll a[N][N], b[N][N];
int ara[N][N][B], arb[N][N][B];

void Build()
{
    FOR(bi, 0, B - 1)FOR(i, 1, n)FOR(j, 1, m)
        ara[i][j][bi] = ara[i - 1][j][bi] + ara[i][j - 1][bi] - ara[i - 1][j - 1][bi] + ((a[i][j] >> bi) & 1);
    FOR(bi, 0, B - 1)FOR(i, 1, n)FOR(j, 1, m)
        arb[i][j][bi] = arb[i - 1][j][bi] + arb[i][j - 1][bi] - arb[i - 1][j - 1][bi] + ((b[i][j] >> bi) & 1);

    FOR(b, 0, B - 1)FORR(i, n, 1)FORR(j, m, 1)
        ara[i][j][b] = ara[i][j][b] - ara[i & (i - 1)][j][b] - ara[i][j & (j - 1)][b] + ara[i & (i - 1)][j & (j - 1)][b];
    FOR(b, 0, B - 1)FORR(i, n, 1)FORR(j, m, 1)
        arb[i][j][b] = arb[i][j][b] - arb[i & (i - 1)][j][b] - arb[i][j & (j - 1)][b] + arb[i & (i - 1)][j & (j - 1)][b];
}

void Update(int aib[][N][B], int x, int y, ll v, int sgn = 1)
{
    FOR(b, 0, B - 1)
        for(int i = x; i <= n; i += i & -i)
            for(int j = y; j <= m; j += j & -j)
                aib[i][j][b] += sgn * ((v >> b) & 1);
}

int Query(int aib[][N][B], int b, int x, int y)
{
    int ret = 0;
    for(int i = x; i; i -= i & -i)
        for(int j = y; j; j -= j & -j)
            ret += aib[i][j][b];
    return ret;
}

int Query(int aib[][N][B], int b, int x1, int y1, int x2, int y2)
{
    return Query(aib, b, x2, y2) - Query(aib, b, x1 - 1, y2) - Query(aib, b, x2, y1 - 1) + Query(aib, b, x1 - 1, y1 - 1);
}


int sl[K], sz;

vvvi divide(int l, int r)
{
    int n = r - l + 1;
    vvvi dp(n + 3, vvi(2, vi(2)));

    if(l == r)
    {
        if(sl[l] == 1)
        {
            dp[0][0][0] = 1;
            dp[1][0][1] = 1;
        }
        else if(sl[l] == 3)
        {
            dp[1][1][1] = 1;
            dp[2][1][0] = 1;
        }

        return dp;
    }

    int m = (l + r) >> 1;
    auto r1 = divide(l, m);
    auto r2 = divide(m + 1, r);

    int l1 = (int)r1.size() - 1, l2 = (int)r2.size() - 1;
    FOR(i, 0, l1)
        FOR(j, 0, l2)
            FOR(b1, 0, 1)
                FOR(b2, 0, 1)
                    FOR(b3, 0, 1)
                        FOR(b4, 0, 1)
                        {
                            int nxt_state = i + j - (b2 == 1 && b3 == 1);
                            if(nxt_state >= 0 && nxt_state < dp.size())
                                dp[nxt_state][b1][b4] = max(dp[nxt_state][b1][b4], r1[i][b1][b2] + r2[j][b3][b4]);
                        }

    return dp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];
    FOR(i, 1, n)FOR(j, 1, m)cin >> b[i][j];

    pt2[0] = 1;
    FOR(i, 1, n * n)pt2[i] = (2 * pt2[i - 1]) % Mod;

    Build();

    cin >> q;
    int t, x1, y1, x2, y2, nr1, sA, sB;
    ll v1, v2;
    FOR(i, 1, q)
    {
        cin >> t;

        if(t == 1)
        {
            cin >> x1 >> y1 >> v1;
            cin >> x2 >> y2 >> v2;

            Update(ara, x1, y1, a[x1][y1], -1);
            Update(ara, x1, y1, a[x1][y1] = v1, 1);
            Update(arb, x2, y2, b[x2][y2], -1);
            Update(arb, x2, y2, b[x2][y2] = v2, 1);
        }
        else if(t == 2)
        {
            sA = 0;
            cin >> x1 >> y1 >> x2 >> y2;

            FOR(b, 0, B - 1)
            {
                nr1 = Query(ara, b, x1, y1, x2, y2);
                if(nr1)sA = (sA + 1LL * pt2[nr1 - 1] * pt2[(x2 - x1 + 1) * (y2 - y1 + 1) - nr1] % Mod * (1LL << b) % Mod) % Mod;
            }

            sB = 0;
            cin >> x1 >> y1 >> x2 >> y2;

            FOR(b, 0, B - 1)
            {
                nr1 = Query(arb, b, x1, y1, x2, y2);
                if(nr1)sB = (sB + 1LL * pt2[nr1 - 1] * pt2[(x2 - x1 + 1) * (y2 - y1 + 1) - nr1] % Mod * (1LL << b) % Mod) % Mod;
            }

            ///1 A, 2 Remiza, 3 B
            if(sA > sB)sl[++ sz] = 1;
            else if(sA == sB)sl[++ sz] = 2;
            else if(sA < sB)sl[++ sz] = 3;
        }
    }

    auto res = divide(1, sz);

    int ans = 0;
    FOR(i, 0, k)
        FOR(b1, 0, 1)
            FOR(b2, 0, 1)
                ans = max(ans, res[i][b1][b2]);

    cout << ans << '\n';
    return 0;
}
