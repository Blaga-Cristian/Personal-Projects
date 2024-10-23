#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 9, LG = 30, K = 1e9;
int t[N][LG];
int tata[N];
int n, q, x, k;

void Preprocess()
{
    for(int i = 1; i <= n; ++i)
        t[i][0] = tata[i];

    for(int k = 1; k < LG; ++k)
        for(int i = 1; i <= n; ++i)
            t[i][k] = t[t[i][k-1]][k-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for(int i = 1; i <= n; ++i)
        cin >> tata[i];

    Preprocess();

    while(q --)
    {
        cin >> x >> k;
        int ans = x;

        for(int i = 0; (1 << i) <= k; ++i)
            if(k & (1 << i))
                ans = t[ans][i];

        cout << ans << '\n';
    }
    return 0;
}
