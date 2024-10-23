#include <bits/stdc++.h>
#define pb push_back
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 2e5 + 9;

int n, m, k, mars[N], cnt1[N], cnt2[N], l[N], r[N];
vector<int> poz[N];

int dp[N]; /// best interval with y <= x

struct event
{
    bool tip;
    int x, ind;

    bool operator < (event const& a)
    {
        return x < a.x;
    }
};
vector<event> events;

int get1(int st, int dr)
{
    if(st > dr)return 0;
    return cnt1[dr] - cnt1[st - 1];
}
int get2(int st, int dr)
{
    if(st > dr)return 0;
    return cnt2[dr] - cnt2[st - 1];
}

bool intersect(int l1, int r1, int l2, int r2)
{
    return (min(r1, r2) < max(l1, l2));
}

void solve()
{
    cin >> n >> m >> k;

    FOR(i, 1, n)
    {
        mars[i] = cnt1[i] = cnt2[i] = l[i] = r[i] = 0;
        poz[i].clear();
    }
    events.clear();

    FOR(i, 1, m)
    {
        cin >> l[i] >> r[i];
        mars[l[i]] ++;
        mars[r[i] + 1] --;

        events.pb({true, l[i], i});
        events.pb({false, r[i] + 1, i});
    }

    int cnt_dry = 0;

    FOR(i, 1, n + 1)mars[i] += mars[i - 1];
    FOR(i, 1, n)
    {
        cnt_dry += (mars[i] == 0);
        cnt1[i] = cnt1[i - 1] + (mars[i] == 1);
        cnt2[i] = cnt2[i - 1] + (mars[i] == 2);
    }

    sort(events.begin(), events.end());

    set<int> st;
    for(int j = 0, i = 1; i <= n; ++i)
    {
        while(j < events.size() && events[j].x <= i)
        {
            if(events[j].tip)st.insert(events[j].ind);
            else st.erase(st.find(events[j].ind));
            ++j;
        }

        if(st.size() <= 2)
            for(auto ind : st)
                poz[i].pb(ind);
    }

    int ans = cnt_dry;

    ///Finding the two best intervals
    FOR(i, 1, m)dp[r[i]] = max(dp[r[i]], get1(l[i], r[i]));
    FOR(i, 1, n)dp[i] = max(dp[i], dp[i - 1]);
    FOR(i, 1, m)ans = max(ans, cnt_dry + get1(l[i], r[i]) + dp[l[i] - 1]);

    FOR(i, 1 ,n)cout << mars[i] << ' ';
    cout << '\n';

    FOR(i, 1, n)
    {
        if(poz[i].size() != 2)continue;

        int l1 = l[poz[i][0]], r1 = r[poz[i][0]],
        l2 = l[poz[i][1]], r2 = r[poz[i][1]];

        ans = max(ans, cnt_dry + get1(min(l1, l2), max(r1, r2)) - get1(max(l1, l2), min(r1, r2)) + get2(max(l1, l2), min(r1, r2)));
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
