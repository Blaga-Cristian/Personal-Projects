#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans;
ll n,x;
map<ll,ll> sums;
ll prefix;
int main()
{
    cin >> n;
    sums[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x;
        prefix += x;
        ans += sums[(prefix % n + n) % n];
        sums[(prefix % n + n) % n] ++;
    }

    cout << ans;
    return 0;
}
