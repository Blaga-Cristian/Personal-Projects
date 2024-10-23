#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9;

int n, a[N], op, l, r, g;
char s[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> a[i];
    cin.get();
    cin.get(s + 1, N);

    cin >> q;
    while(q --)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> l >> r;

        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
