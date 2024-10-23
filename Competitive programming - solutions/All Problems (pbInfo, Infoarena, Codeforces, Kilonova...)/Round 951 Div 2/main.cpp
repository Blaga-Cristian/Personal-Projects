#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define int long long
using namespace std;
const int N = 2e5 + 9, Inf = 0x3f3f3f3f, Mod = 998244353;

int n, prv[N], nxt[N], z[N];
string s;

void solve()
{
    cin >> s;
    int n = s.size();

    for(int i = 0; i <= n + 1; ++i)
    {
        prv[i] = nxt[i] = z[i] = 0;
    }

    int p = 0;
    for(; p < n; ++p)
        if(s[p] != 'a')
            break;

    if(p == n)
    {
        cout << n - 1 << '\n';
        return;
    }

    nxt[n - 1] = n;
    for(int i = n - 1; i >= 0; --i)
    {
        if(s[i] != 'a')nxt[i] = i;
        else if(i < n - 1)nxt[i] = nxt[i + 1];
    }

    string aux = s.substr(p, (int)s.size() - p);

    z[0] = 0;
    int l = 0, r = 0;
    for(int i = 1; i < aux.size(); ++i)
    {
        if(i < r)z[i] = min(z[i - l], r - i);
        while(i + z[i] < aux.size() && aux[z[i]] == aux[i + z[i]])++ z[i];
        if(i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }

//    for(int i = 0; i < aux.size(); ++i)cout << z[i] << ' ';
//    cout << '\n';

    int ans = 0;
    for(int len = 1; p + len <= n; ++len)
    {
        int cur = p + len;
        int mn = p;

        bool ok = true;

        while(cur < n)
        {
            if(nxt[cur] == n)break;

            int bt = nxt[cur] - cur;
            mn = min(mn, bt);
            cur += bt;

            if(z[cur - p] < len)
            {
                ok = false;
                break;
            }

            cur += len;
        }

        if(ok)
        {
            ans += mn + 1;
//            cout << len << ' ' << mn << '\n';
        }
    }

    cout << ans << '\n';
}

signed main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
