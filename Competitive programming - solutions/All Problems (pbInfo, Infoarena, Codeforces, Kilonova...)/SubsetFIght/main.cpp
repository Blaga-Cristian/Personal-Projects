#include <bits/stdc++.h>

using namespace std;
const int N = 109, Mod = 1000000007;

int n;
int kp[2][N], prv = 0, cur = 1;

void add(int val, int pond)
{
    swap(cur, prv);

    for(int i = 0; i < n; ++i)
        kp[cur][i] = 0;
    for(int i = 0; i < n; ++i)
    {
        kp[cur][i] = (kp[cur][i] + kp[prv][i]) % Mod;
        if(kp[prv][i])kp[cur][(i + val) % n] = (1LL * kp[cur][(i + val) % n] + 1LL * kp[prv][i] * pond) % Mod;
    }
}

int main()
{
    kp[cur][0] = 1;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;

        for(int j = 0; (1 << j) <= x; ++j)
            add(i * (1 << j), 1 << j);
    }

    cout << kp[cur][0];
    return 0;
}
