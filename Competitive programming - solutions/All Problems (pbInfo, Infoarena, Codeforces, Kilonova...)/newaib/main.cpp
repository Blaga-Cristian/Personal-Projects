#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back

using namespace std;
const int N = 1e5 + 9;

int n, p[N], aib[N], ans[N];
void update(int poz, int val)
{
    for(; poz <= n; poz += poz & - poz)
        aib[poz] += val;
}
int query(int poz)
{
    int ret = 0;
    for(; poz; poz -= poz & -poz)
        ret += aib[poz];
    return ret;
}
int query(int st, int dr)
{
    return query(dr) - query(st - 1);
}

int main()
{
    cin >> n;

    int x;
    FOR(i, 1, n)
    {
        cin >> x;
        p[x] = i;
    }

    FOR(i, 1, n)
    {
        ans[p[i]] = query(p[i]);
        update(p[i], 1);
    }

    FOR(i, 1, n)cout << ans[i] << ' ';
    return 0;
}
