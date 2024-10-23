#include <bits/stdc++.h>
#define PI pair<int,int>
#define ll long long
#define PLL pair<ll, ll>
using namespace std;
const int N = 49;

int n, x, v[N];
map<ll,ll> s;
vector<PLL> upds;




int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; ++i)cin >> v[i];

    auto get_sums = [&](int l, int r) -> vector<ll>
    {
        int len = r - l + 1;
        vector<ll> res;

        for(int i = 0; i < (1 << len); ++i)
        {
            ll sum = 0;
            for(int j = 0; j < len; ++j)
                if(i & (1 << j))
                    sum += v[l + j];
            res.push_back(sum);
        }

        return res;
    };

    auto left = get_sums(0, n / 2 - 1);
    auto right = get_sums(n / 2, n - 1);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    ll ans = 0;
    for(ll i : left)
        ans += upper_bound(right.begin(), right.end(), x - i) - lower_bound(right.begin(), right.end(), x - i);

    cout << ans;
    return 0;
}
