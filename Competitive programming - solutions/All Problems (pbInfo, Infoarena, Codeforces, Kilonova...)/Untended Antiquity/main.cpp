#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 2509;

mt19937 rng(69);

int n, m, q, hsh[N][N];

int aib[N][N];
void Update(int x, int y, int v)
{
    for(int i = x; i <= n; i += i & -i)
        for(int j = y; j <= m; j += j & -j)
            aib[i][j] ^= v;
}
int Query(int x, int y)
{
    int ret = 0;
    for(int i = x; i > 0; i -= i & -i)
        for(int j = y; j > 0; j -= j & -j)
            ret ^= aib[i][j];
    return ret;
}

int main()
{
    cin >> n >> m >> q;

    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            hsh[i][j] = rng();

    int op, x1, y1, x2, y2;
    for(int i = 1; i <= q; ++i)
    {
        cin >> op >> x1 >> y1 >> x2 >> y2;

        if(op != 3)
        {
            Update(x1, y1, hsh[x1][y1]);
            Update(x1, y2 + 1, hsh[x1][y1]);
            Update(x2 + 1, y1, hsh[x1][y1]);
            Update(x2 + 1, y2 + 1, hsh[x1][y1]);
        }
        else
        {
            if(Query(x1, y1) == Query(x2, y2))cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
