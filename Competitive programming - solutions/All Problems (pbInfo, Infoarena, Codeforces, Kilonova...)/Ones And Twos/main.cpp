#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 9;

int n, a[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> a[i];

    if(a[1] != 1)cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
