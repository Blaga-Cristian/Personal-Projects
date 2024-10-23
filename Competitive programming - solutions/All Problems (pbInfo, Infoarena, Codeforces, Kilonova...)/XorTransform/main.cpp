#include <bits/stdc++.h>

using namespace std;
const int N = 25e5 + 9, M = 22;

int dp[1 << M];

void initialize(int n, int m, int mat[][100])
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            dp[i | j] ^= mat[i][j];

    for(int i = 0; i < M; ++i)
        for(int j = 0; j < (1 << M); ++j)
            if(j & (1 << i))
                dp[j] ^= dp[j ^ (1 << i)];
}

int query(int k)
{
    k = k & ((1 << M) - 1);
    return dp[k];
}

int n, m, q, mat[100][100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> mat[i][j];
    initialize(n, m, mat);

    int k;
    while(q --)
    {
        cin >> k;
        cout << query(k) << '\n';
    }
    return 0;
}
