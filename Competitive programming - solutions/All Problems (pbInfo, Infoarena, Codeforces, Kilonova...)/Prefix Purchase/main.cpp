#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
const int N = 2e5 + 9;

int n, c[N], mars[N], k;
void solve()
{
    cin >> n;
    fill(mars + 1, mars + n + 1, 0);
    int poz = 1;
    FOR(i, 1, n)
    {
        cin >> c[i];
        if(c[i] < c[poz])
            poz = i;
    }
    cin >> k;
    mars[poz] = k / c[poz];

    int nxt = -1;
    FOR(i, poz + 1, n)
        if(c[i] <= c[poz] + k % c[poz])
            nxt = i;

    if(nxt != -1)
    {
        mars[nxt] = 1;
        mars[poz] -= 1;
    }

    for(int i = n; i >= 1; --i)
        mars[i] = mars[i + 1] + mars[i];

    FOR(i, 1, n)
        cout << mars[i] << ' ';
    cout << '\n';
}

int main()
{
    FAST_IN_OUT

    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
