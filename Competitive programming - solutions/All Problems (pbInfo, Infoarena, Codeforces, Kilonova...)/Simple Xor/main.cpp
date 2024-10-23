#include <bits/stdc++.h>

using namespace std;
const int N = 2 * 1e5 + 9;

int n, m, a, b, xorp[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        xorp[i] = x ^ xorp[i - 1];
    }

    while(m --)
    {
        cin >> a >> b;
        cout << (xorp[b] ^ xorp[a - 1]) << '\n';
    }
    return 0;
}
