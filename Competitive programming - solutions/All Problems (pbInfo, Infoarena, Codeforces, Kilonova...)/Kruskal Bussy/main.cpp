#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9, M = 2 * 1e5 + 9;
int n, m, a, b, t[N], cnt[N];

int Find(int x){return !t[x] ? x : t[x] = Find(t[x]);}

int main()
{

    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cnt[i] = 1;
    int trees = n, maximum = 1;
    for(int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        int ra = Find(a), rb = Find(b);

        if(Find(a) != Find(b))
        {
            t[ra] = rb;
            cnt[rb] += cnt[ra];
            trees --;
            maximum = max(maximum, cnt[rb]);
        }

        cout << trees << ' ' << maximum << '\n';
    }
    return 0;
}
