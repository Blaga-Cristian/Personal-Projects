#include <iostream>
#define ll long long
using namespace std;
const int N = 3e5 + 9, Mod = 998244353;

int n, v[N];
ll sum[2], cnt[2];
ll ans = 0;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> v[i];

    int sum0, sum1, cnt0, cnt1;
    for(int bit = 0; bit < 31; ++bit)
    {
        sum[0] = sum[1] = cnt[0] = cnt[1] = 0;
        for(int i = 1; i <= n; ++i)
        {
            bool b = (v[i] & (1 << bit));

            if(b)
            {
                swap(sum[0], sum[1]);
                swap(cnt[0], cnt[1]);
            }

            sum[0] += cnt[0];
            sum[1] += cnt[1];

            sum[b] ++;
            cnt[b] ++;

            sum[0] %= Mod;
            sum[1] %= Mod;

            ans += sum[1] * (1 << bit);
            ans %= Mod;
        }
    }

    cout << ans;
    return 0;
}
