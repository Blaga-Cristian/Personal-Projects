#include <bits/stdc++.h>
#define int long long
using namespace std;
const string TASK("reguli");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 5e5 + 9;
const bool test_cases = false;

int n, a[N], z[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> a[i];

    for(int i = n; i >= 2; --i)a[i] -= a[i - 1];

    int l = 2, r = 2;
    for(int i = 3; i <= n; ++i)
    {
        if(i < r)z[i] = min(r - i, z[i - l]);
        while(i + z[i] <= n && a[i + z[i]] == a[z[i] + 2])++ z[i];
        if(i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }

    int ans = n - 1;
    for(int i = n; i >= 2; --i)
        if(i + z[i] == n + 1)
            ans = i - 2;

    cout << ans << '\n';
    for(int i = 2; i < ans + 2; ++i)
        cout << a[i] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
