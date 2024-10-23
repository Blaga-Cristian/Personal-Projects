#include <bits/stdc++.h>

using namespace std;

const int Nmax = 2;
const int Smax = 13;
const int Kmax = 1009;
const int Inf = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
int v[Nmax];

int dp[2][Nmax][Kmax][Smax];
int cnt[2][Nmax][Kmax][Smax];

int prv = 0, cur = 1;

void solve()
{
    int N, K, S;

    cin >> N >> K >> S;
    for(int i = 1; i <= N; ++i)
        cin >> v[i];

    for(int s = 0; s <= S; ++s)
        for(int k = 0; k <= K; ++k)
            for(int n = 0; n < Nmax; ++n)
                dp[0][n][k][s] = dp[1][n][k][s] = Inf;
    for(int n = 0; n < Nmax; ++n)
    {
        dp[0][n][0][0] = dp[1][n][0][0] = 0;
        cnt[0][n][0][0] = cnt[1][n][0][0] = 1;
    }

    for(int n = 1; n <= N; ++n, swap(prv, cur))
        for(int s = 1; s <= S; ++s)
            for(int k = 0; k <= K; ++k)
    {
        if(k >= v[n])
        {
            if(dp[1][prv][k - v[n]][s - 1] + 1 == dp[0][prv][k - v[n]][s] + 1)
                cnt[0][cur][k][s] = cnt[1][prv][k - v[n]][s - 1] + cnt[0][prv][k - v[n]][s];
            else if(dp[1][prv][k - v[n]][s - 1] + 1 < dp[0][prv][k - v[n]][s] + 1)
                cnt[0][cur][k][s] = cnt[1][prv][k - v[n]][s - 1];
            else
                cnt[0][cur][k][s] = cnt[0][prv][k - v[n]][s];

            if(cnt[0][cur][k][s] >= Mod)cnt[0][cur][k][s] -= Mod;


            dp[0][cur][k][s] = min(dp[1][prv][k - v[n]][s - 1] + 1, dp[0][prv][k - v[n]][s] + 1);
        }


        if(dp[1][prv][k][s] == dp[0][cur][k][s])
            cnt[1][cur][k][s] = cnt[1][prv][k][s] + cnt[0][cur][k][s];
        else if(dp[1][prv][k][s] < dp[0][cur][k][s])
            cnt[1][cur][k][s] = cnt[1][prv][k][s];
        else
            cnt[1][cur][k][s] = cnt[0][cur][k][s];

        if(cnt[1][cur][k][s] >= Mod)cnt[1][cur][k][s] -= Mod;

        dp[1][cur][k][s] = min(dp[1][prv][k][s], dp[0][cur][k][s]);
    }



    int ans = Inf, cntans = 0;
    for(int s = 1; s <= S; ++s)
        if(dp[1][prv][K][s] < ans)
        {
            ans = dp[1][prv][K][s];
            cntans = cnt[1][prv][K][s];
        }
        else if(dp[1][prv][K][s] == ans)
        {
            cntans += cnt[1][prv][K][s];
            if(cntans >= Mod)cntans -= Mod;
        }

    if(ans == Inf)
    {
        cout << 0 << ' ' << 0 << '\n';
        return;
    }
    cout << ans << ' ' << cntans << '\n';

}

int main()
{
    freopen("dragonfruit.in", "r", stdin);
    freopen("dragonfruit.out", "w", stdout);

    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
