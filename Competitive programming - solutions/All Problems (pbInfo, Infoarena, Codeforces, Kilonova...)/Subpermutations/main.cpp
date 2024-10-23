#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
//#define int long long
using namespace std;

const int N = 3e5 + 9;

int n, a[N];
vvi pos(N);

///Exista O(n) subpermutari
int hsh[N], rnd[N], perm[N];
mt19937 mt;
uniform_int_distribution<int> rng(0, INT_MAX);

int t[N], l[N], r[N], mn[N], mx[N], sz[N];
int find(int x){return t[x] == x ? x : t[x] = find(t[x]);}
void unite(int x, int y)
{
    x = find(x), y = find(y);

    if(sz[x] > sz[y])swap(x, y);
    ///sz[x] < sz[y]

    t[x] = y;
    sz[y] += sz[x];
    l[y] = min(l[y], l[x]);
    mn[y] = min(mn[y], mn[x]);
    r[y] = max(r[y], r[x]);
    mx[y] = max(mx[y], mx[x]);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;

    for(int i = 1; i <= n; ++i)rnd[i] = rng(mt);
    for(int i = 1; i <= n; ++i)
    {
        hsh[i] = hsh[i - 1] ^ rnd[a[i]];
        perm[i] = perm[i - 1] ^ rnd[i];
    }

    for(int i = 1; i <= n; ++i)pos[a[i]].pb(i);

    for(int i = 1; i <= n; ++i)
    {
        for(auto p : pos[i])
        {
            int st = p, dr = p;
            if(t[p - 1])st = l[find(p - 1)];
            if(t[p + 1])dr = r[find(p + 1)];

            if(p - st < dr - p)
            {
                for(int j = max(st, p - i + 1); j <= min(p, dr - i + 1); ++j)
                    if((hsh[j + i - 1] ^ hsh[j - 1]) == perm[i])
                        ans ++;
            }
            else
            {
                for(int j = max(p, st + i - 1); j <= min(p + i - 1, dr); ++j)
                    if((hsh[j] ^ hsh[j - i]) == perm[i])
                        ans ++;
            }
        }

        for(auto p : pos[i])
        {
            t[p] = p;
            sz[p] = 1;
            l[p] = r[p] = p;
            mn[p] = mx[p] = i;

            if(t[p - 1])unite(p, p - 1);
            if(t[p + 1])unite(p, p + 1);
        }
    }

    cout << ans << '\n';
    return 0;
}
