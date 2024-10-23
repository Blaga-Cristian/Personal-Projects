#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 9;


int lpf[N], mob[N];
void Precalc()
{
    mob[1] = 1;
    for(int i = 2; i < N; ++i)
    {
        if(!lpf[i])
            for(int j = i; j < N; j += i)
                if(!lpf[j])
                    lpf[j] = i;

        if(i / lpf[i] % lpf[i] == 0)mob[i] = 0;
        else mob[i] = -1 * mob[i / lpf[i]];
    }
}

int n;
ll calc(int n, int k)
{
    ll ret = 0;
    for(int d = 1; d * d <= n / k; ++d)
    {
        if((n / k) % d == 0)
        {
            ret += 1LL * (n / k) * ((n / k) / d) * mob[d];
            if(d * d != n / k)ret += 1LL * (n / k) * d * mob[(n / k) / d];
        }
    }
    return ret;
}

void solve()
{
    cin >> n;

    ll ans = 0;

    for(int k = 1; k * k <= n; ++k)
        if(n % k == 0)
        {
            ans += calc(n, k);
            if(k * k != n)ans += calc(n, n / k);
        }

    cout << ans << '\n';
}

int main()
{
    Precalc();

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
