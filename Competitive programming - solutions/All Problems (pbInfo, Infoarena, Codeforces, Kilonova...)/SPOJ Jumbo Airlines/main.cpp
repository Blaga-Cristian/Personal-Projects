#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
using namespace std;
const string TASK("john_jones_airlines");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout
const int Mod = 420047;

int n, m, k;

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
}

void solve()
{
    if(n < m)swap(n, m);

    vvvi dp(2, vvi((1 << m) + 1, vi(k + 1)));
    dp[0][0][0] = 1;

    ///Pot folosi sos dp
    int prv = 0, cur = 1;
    for(int i = 1; i <= n; ++i, swap(cur, prv))
        for(int sum = 0; sum <= k; ++sum)
            for(int omask = 0; omask < (1 << m); ++omask)
                if((omask & (omask << 1)) == 0)
                    for(int mask = 0; mask < (1 << m); ++mask)
                        if((mask & (mask << 1)) == 0)
                        {
                            int osum = sum - __builtin_popcount(mask);
                            if((omask & mask) == 0 && osum >= 0)
                                dp[cur][mask][sum] = add(dp[cur][mask][sum], dp[prv][omask][osum]);
                        }

    cout << "Testcase finished\n";
    int ans = 0;
    for(int s = 0; s < (1 << m); ++s)ans = add(ans, dp[prv][s][k]);
    cout << ans << '\n';
}

int main()
{
    while(cin >> n >> m >> k)
        solve();
    return 0;
}
