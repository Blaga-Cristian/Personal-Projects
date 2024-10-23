#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 9, Mod = 1e9 + 7;

int n, a[N];

vvi divs(N);
void PrecalcDivs()
{
    for(int i = 1; i < N; ++i)
        for(int j = i; j < N; j += i)
            divs[j].pb(i);
}

ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = base * base % Mod)
        if(exp & 1)
            ret = ret * base % Mod;
    return ret;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> a[i];

    sort(a + 1, a + n + 1);

    PrecalcDivs();

    ll ans = 1;
    for(int i = 2; i <= a[n]; ++i)
    {
        int lst = 0;
        ll add = 1;
        for(int p = 0; p + 1 < divs[i].size(); ++p)
            add = add * PtLg(p + 1,
                        distance(a + 1, upper_bound(a + 1, a + n + 1, divs[i][p + 1] - 1)) -
                        distance(a + 1, lower_bound(a + 1, a + n + 1, divs[i][p]))) % Mod;

        add = ((add * PtLg(divs[i].size(),
                         n - distance(a + 1, upper_bound(a + 1, a + n + 1, i - 1))) % Mod)
                - add * PtLg(divs[i].size() - 1,
                             n - distance(a + 1, upper_bound(a + 1, a + n + 1, i - 1))) % Mod + Mod) % Mod;
        ans = (ans + add) % Mod;
    }

    cout << ans << '\n';
    return 0;
}
