#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define pl pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define int long long
using namespace std;
const string TASK("scotch");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1009, M = 11;
const int Inf = 0x3f3f3f3f;
const ll Mod = 1e9 + 7;
const bool test_cases = false;

int n, m;
int dp[N][1 << M];
int aux[1 << M], aux2[1 << M];
char c[N][M];

void solve()
{
    cin >> n >> m;

    FOR(i, 1, n)cin >> c[i];


    FOR(i, 0, n)
        FOR(j, 0, (1 << m) - 1)
            dp[i][j] = Inf;

    dp[0][0] = 0;

    for(int i = 1; i <= n; ++i)
    {
        for(int s = 0; s < (1 << m); ++s)
            aux[s] = dp[i - 1][s];

        for(int s = (1 << m) - 1; s >= 0; --s)
            for(int j = 0; j < m; ++j)
                if((s & (1 << j)) == 0)
                    aux[s] = min(aux[s], aux[s | (1 << j)]);

        ///aux[s] = costul minim al unui set care are s ca SUBSET

        for(int s = 0; s < (1 << m); ++s)
            for(int j = 0; j < m; ++j)
                if((s & (1 << j)) != 0)
                    aux[s] = min(aux[s], aux[s ^ (1 << j)] + 1);


        for(int s = 0; s < (1 << m); ++s)
        {
            bool ok = true;
            for(int j = 0; j < m; ++j)
                if(c[i][j] == '.' && (s & (1 << j)) != 0)
                    ok = false;

            if(!ok)continue;

            int cnt_secv = 0;
            for(int j = 0; j < m; ++j)
            {
                if(c[i][j] == '#' && (s & (1 << j)) == 0)
                {
                    cnt_secv ++;
                    while(j + 1 < m && c[i][j + 1] == '#' && (s & (1 << (j + 1))) == 0)++j;
                }
            }

            dp[i][s] = min(dp[i][s], aux[s] + cnt_secv);
        }
    }

    int ans = Inf;
    for(int j = 0; j < (1 << m); ++j)
    {
        ans = min(ans, dp[n][j]);
//        cout << dp[n][j] << ' ';
    }

    cout << ans << '\n';
}

signed main()
{
    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
