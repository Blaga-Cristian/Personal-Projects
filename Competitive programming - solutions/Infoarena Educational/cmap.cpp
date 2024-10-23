#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long

using namespace std;

const string TASK("cmap");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9, Inf = 0x3f3f3f3f;

struct point
{
    ll x, y;
};

struct cmp
{
    bool operator () (point const& a, point const& b) const noexcept
    {
        return a.y == b.y ? a.x < b.x : a.y < b.y;
    }
};

ll dist(point const& a, point const& b)
{
    return 1LL * (a.x - b.x) * (a.x - b.x) +
            1LL * (a.y - b.y) * (a.y - b.y);
}


int n;
point a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    FOR(i, 1, n)cin >> a[i].x >> a[i].y;

    sort(a + 1, a + n + 1, [](point a, point b)
         {
             return a.x == b.x ? a.y < b.y : a.x < b.x;
         });

    set<point, cmp> st;

    ll d = dist(a[1], a[2]);
    int p = 1;
    FOR(i, 1, n)
    {
        ll dd = ceil(sqrt(d)) + 1;

        while(p < i && a[p].x < a[i].x - dd)
        {
            st.erase(a[p]);
            p ++;
        }

        auto it1 = st.lower_bound({a[i].x - dd, a[i].y - dd});
        auto it2 = st.upper_bound({a[i].x - dd, a[i].y + dd});
        for(; it1 != it2; ++it1)
            d = min(d, dist(a[i], *it1));

        st.insert(a[i]);
    }

    cout << fixed << setprecision(12);
    cout << sqrt(d) << '\n';
    return 0;
}