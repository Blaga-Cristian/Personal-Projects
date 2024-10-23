#include <bits/stdc++.h>
#define ll long long

using namespace std;

map<int,int> first;
map<int,int> last;
int a[200005];
map<ll,ll> cnt;
ll ans, n, k;

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    int l = 1, r = 1, c = 0;
    while(l <= n)
    {
        while(r <= n && c + (cnt[a[r]] == 0) <= k)
        {
            c += (cnt[a[r]] == 0);
            cnt[a[r]]++;
            r++;
        }
        ans += r - l;
        c -= (cnt[a[l]] == 1);
        cnt[a[l]]--;
        l++;
    }

    cout << ans;
    return 0;
}
