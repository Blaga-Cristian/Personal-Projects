#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define vvpi vector<vpi>
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define vl vector<ll>
#define vpi vector<pii>
#define vpl vector<pll>
using namespace std;
const string TASK("permutare");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
const int N = 1009;
const ll Inf = 1e9 + 9;

ll c, n, p, a[N], dp[N][2 * N];
///dp[i][j] = in cate moduri al i-lea element poate fi ales intr-o permutare, fiind mai mic sau egal cu j;

void Precalc()
{
    FOR(i, 0, n + 1)FOR(j, 0, 2 * n + 1)dp[i][j] = 0;

    FOR(j, n, 2 * n - 1)dp[n][j] = dp[n][j - 1] + 1;

    FORR(i, n - 1, 1)
        FOR(j, i, 2 * i - 1)
            if(dp[i][j - 1] > Inf)dp[i][j] = Inf;
            else dp[i][j] = dp[i][j - 1] + (dp[i + 1][2 * i + 1] - dp[i + 1][j]);
}
bool viz[2 * N];

int main()
{
    while(cin >> c)
    {
    cin >> n;

    Precalc();
    if(c == 1)
    {
        cin >> p;

        ll prv = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int t = prv + 1; t <= 2 * i - 1; ++t)
                if(dp[i][t] - dp[i][prv] >= p)
                {
                    a[i] = t;
                    p -= (dp[i][t - 1] - dp[i][prv]);
                    prv = t;
                    break;
                }
        }

        FOR(i, 1, 2 * n)viz[i] = false;
        FOR(i, 1, n)viz[a[i]] = true;
        ll t = n + 1;
        FOR(i, 1, 2 * n)a[t ++] = i;


        FOR(i, 1, 2 * n)cout << a[i] << ' ';
        cout << '\n';
    }
    else
    {
        FOR(i, 1, 2 * n)cin >> a[i];

        ll ans = 1, prv = 0;
        FOR(i, 1, n)
        {
            ans += dp[i][a[i] - 1] - dp[i][prv];
            prv = a[i];
        }

        cout << ans << '\n';
    }
    }
    return 0;
}
