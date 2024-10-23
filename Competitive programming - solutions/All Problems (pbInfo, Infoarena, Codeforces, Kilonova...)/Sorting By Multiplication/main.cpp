#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
using namespace std;
const int N = 2e5 + 9;

int n, v[N];
int cr[N], dc[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> v[i];

    memset(cr, 0, sizeof(cr));
    memset(dc, 0, sizeof(dc));

    for(int i = 2; i <= n; ++i)
    {
        cr[i] = min(cr[i - 1] + (v[i - 1] >= v[i]), dc[i - 1] + 1);
        dc[i] = dc[i - 1] + (v[i - 1] <= v[i]);
    }

    cout << cr[n] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
