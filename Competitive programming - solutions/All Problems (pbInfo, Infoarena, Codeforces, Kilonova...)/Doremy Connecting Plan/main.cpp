#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define all(v) (v).begin(), (v).end()
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define ll long long
#define ull unsigned ll
#define PLL pair<ll, ll>
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
using namespace std;
const int N = 2e5 + 9;

int n, m, k, dp[N], mars[N], cnt1[N], cnt2[N];

struct info
{
    int l, r;
};
vector<info> v;

///dp[i] = best interval from i ... n

int get_1(int l, int r)
{
    return cnt1[l] - cnt1[r + 1];
}
int get_2(int l, int r)
{
    return cnt2[l] - cnt2[r + 1];
}

struct event
{
    int x, ind;
    bool tip; ///tip == 0, adaug, tip == 1, sterg

    bool operator < (event const& oth)
    {
        return x < oth.x;
    }
};

struct comp1
{
    bool operator() (int a, int b)
    {
        return (v[a].l == v[b].l) ? a < b : v[a].l < v[b].l;
    }
};
struct compr
{
    bool operator() (int a, int b)
    {
        return (v[a].r == v[b].r) ? a < b : v[a].r > v[b].r;
    }
};

void solve()
{
    cin >> n >> m >> k;

    FOR(i, 0, n + 1)mars[i] = cnt1[i] = cnt2[i] = dp[i] = 0;
    v.resize(m + 1);

    FOR(i, 1, m)cin >> v[i].l >> v[i].r;

    FOR(i, 1, m)
    {
        mars[v[i].l] ++;
        mars[v[i].r + 1] --;
    }

    FOR(i, 1, n)mars[i] += mars[i - 1];

    int cnt0 = 0;
    FOR(i, 1, n)cnt0 += (mars[i] == 0);
    FORR(i, n, 0)cnt1[i] = cnt1[i + 1] + (mars[i] == 1);
    FORR(i, n, 0)cnt2[i] = cnt2[i + 1] + (mars[i] == 2);

    FOR(i, 1, m)dp[v[i].l] = max(dp[v[i].l], get_1(v[i].l, v[i].r));
    FORR(i, n, 1)dp[i] = max(dp[i], dp[i + 1]);

    int ans = INT_MIN;
    FOR(i, 1, m)ans = max(ans, cnt0 + get_1(v[i].l, v[i].r) + dp[v[i].r + 1]);///no intersection case


    sort(v.begin() + 1, v.end(), [](info a, info b){return a.l < b.l;});

    vector<event> events;
    FOR(i, 1, m)events.pb({v[i].l, i, 0}), events.pb({v[i].r + 1, i, 1});
    sort(all(events));

    multiset<int> ms;
    multiset<int, comp1> msl;
    multiset<int, compr> msr;

    for(int i = 1, j = 0; i <= n; ++i)
    {
        for(; j < events.size() && events[j].x <= i; ++j)
        {
            if(events[j].tip == 0)
            {
                ms.insert(events[j].ind);
                msl.insert(events[j].ind);
                msr.insert(events[j].ind);
            }
            else
            {
                ms.erase(ms.find(events[j].ind));
                msl.erase(msl.find(events[j].ind));
                msr.erase(msr.find(events[j].ind));
            }
        }

        if(ms.size() >= 2)
        {
            int ind1 = *msl.begin(), ind2 = *msr.begin();
            if(ind1 == ind2)ind2 = *(++msr.begin());

            auto i1 = v[ind1], i2 = v[ind2];

//            cout << "At " << i << "  " << i1.l << ' ' << i1.r << "    " << i2.l << ' ' << i2.r << '\n';

            ans = max(ans, cnt0 + get_1(i1.l, i1.r) + get_1(i2.l, i2.r) - get_1(max(i1.l, i2.l), min(i1.r, i2.r)) + get_2(max(i1.l, i2.l), min(i1.r, i2.r)));
        }
    }

    cout << ans << '\n';
}

int main()
{
    FAST_IN_OUT
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
