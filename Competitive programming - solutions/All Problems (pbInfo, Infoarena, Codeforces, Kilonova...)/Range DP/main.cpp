#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORR(i, a, b) for(int i = (a); i >= (b); --i)
#define int long long
using namespace std;
const int N = 309;

const string TASK("pieaters");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

int n, m, w[N][N];
int best[N][N][N];
int dp[N][N];

signed main()
{
    cin >> n >> m;

    int v, l, r;
    FOR(i, 1, m)
    {
        cin >> v >> l >> r;
        FOR(p, l, r)best[p][l][r] = max(best[p][l][r], v);
    }

    FOR(i, 1, n)
        FORR(l, i, 1)
            FOR(r, i, n)
            {
                if(l < i)best[i][l][r] = max(best[i][l][r], best[i][l + 1][r]);
                if(r > i) best[i][l][r] = max(best[i][l][r], best[i][l][r - 1]);
            }

    for(int sz = 1; sz <= n; ++sz)
        for(int i = 1, j = i + sz - 1; j <= n; ++i, ++j)
        {
            for(int p = i; p < j; ++p)
                dp[i][j] = max(dp[i][j], dp[i][p] + dp[p + 1][j]);

            for(int p = i; p <= j; ++p)
                dp[i][j] = max(dp[i][j], best[p][i][j] + ((p == i) ? 0 : dp[i][p - 1]) + ((p == j) ? 0 : dp[p + 1][j]));
        }

    cout << dp[1][n] << '\n';
    return 0;
}
