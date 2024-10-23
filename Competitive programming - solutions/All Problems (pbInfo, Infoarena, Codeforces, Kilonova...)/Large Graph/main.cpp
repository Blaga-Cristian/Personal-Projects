#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 9, NRP = 79000;
const bool test_cases = true;

int n, k, a[2 * N];

deque<int> dq[NRP];
int id[N], nr = 0;

int cnt = 0;
int dsu[2 * N], sz[2 * N];
int find(int x){return dsu[x] ? dsu[x] = find(dsu[x]) : x;}
void unite(int x, int y)
{
    x = find(x), y = find(y);

    if(x == y)return;

    if(sz[x] > sz[y])swap(x, y);

    dsu[x] = y;
    sz[y] += sz[x] + 1;
    cnt --;
}

int d[N];
void Ciur()
{
    d[1] = 1;
    for(int i = 2; i < N; ++i)
        if(!d[i])
        {
            id[i] = ++nr;
            for(int j = i; j < N; j += i)
                if(!d[j])
                    d[j] = i;
        }
}


void solve()
{
    cin >> n >> k;

    for(int i = 0; i <= 2 * n + 1; ++i)dsu[i] = sz[i] = 0;

    for(int i = 0; i < n; ++i)cin >> a[i];
    for(int i = n; i <= 2 * n - 1; ++i)a[i] = a[i - n];

    cnt = 2 * n - 1;
    for(int i = 1; i < 2 * n; ++i)
    {
        for(int x = a[i]; x != 1;)
        {
            int div = d[x];

            if(!dq[id[div]].empty())
                unite(dq[id[div]].front(), i);
            dq[id[div]].push_back(i);

            while(x % div == 0)x /= div;
        }

        if(i > k)
        {
            for(int x = a[i - k]; x != 1;)
            {
                int div = d[x];
                dq[id[div]].pop_front();

                while(x % div == 0)x /= div;
            }
        }
    }

    for(int i = max(1, 2 * n - k); i < 2 * n; ++i)
        for(int x = a[i]; x != 1;)
        {
            int div = d[x];
            dq[id[div]].pop_front();

            while(x % div == 0)x /= div;
        }

    long long ans = cnt;
    for(int i = 1; i < 2 * n; ++i)
        if(a[i] == 1)
            ans += min(i, 2 * n - i) - 1;

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Ciur();

    int t = 1;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
