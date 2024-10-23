#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long
#define P pair<ll, ll>
#define X first
#define Y second
using namespace std;
const int N = 2e5 + 9;

int n;
P a[N];

ll d(P a, P b)
{
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

struct cmp
{
    bool operator() (P x, P y){return x.Y == y.Y ? x.X < y.X : x.Y < y.Y;};
};

int main()
{
    cin >> n;

    FOR(i, 1, n)cin >> a[i].X >> a[i].Y;

    vector<P> v;
    FOR(i, 1, n)v.pb(a[i]);
    sort(v.begin(), v.end());
    multiset<P, cmp> st;

    ll d_min = LLONG_MAX;
    for(int j = 0, i = 0; i <= n; st.insert(v[i]), ++i)
    {
        while(j < v.size() && (v[i].X - v[j].X) * (v[i].X - v[j].X) >= d_min)
        {
            st.erase(st.find(v[j]));
            ++ j;
        }

        for(auto it1 = st.lower_bound({LLONG_MIN, v[i].Y - sqrt(d_min)}),
            it2 = st.upper_bound({LLONG_MAX, v[i].Y + sqrt(d_min)}); it1 != it2; ++it1)
        {
            cout << (*it1).X << ' ' << (*it2).Y << '\n';
            d_min = min(d_min, d(*it1, v[i]));
        }
    }

    cout << d_min;
    return 0;
}
