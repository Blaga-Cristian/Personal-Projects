#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
using namespace std;
const int N = 21;

ll n;
ll k, v[N], dp[1 << N];

int main()
{
    cin >> n >> k;
    FOR(i, 0, k - 1)
        cin >> v[i];

    for(int s = 1; s < (1 << k); ++s)
    {
        ll nr = 1;
        for(int i = 0; i < k; ++i)
            if(s & (1 << i))
            {
                if(nr > n / v[i])
                {
                    nr = -1;
                    break;
                }
                nr *= v[i];
            }

        if(nr == -1)dp[s] = 0;
        else dp[s] = n / nr;
    }


    ll ans = 0;
    for(int s = 1; s < (1 << k); ++s)
        if(__builtin_popcount(s) % 2)
            ans += dp[s];
        else
            ans -= dp[s];

    cout << ans;
    return 0;
}
