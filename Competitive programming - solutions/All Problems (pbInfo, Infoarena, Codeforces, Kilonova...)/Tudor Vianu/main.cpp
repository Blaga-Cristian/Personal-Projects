#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define pl pair<ll, ll>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

using namespace std;
const string TASK("paprika");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout

const int N = 2e5 + 9;
const ll Mod = 1e9 + 7;
const bool test_cases = false;

int n, w[N], t[N], in[N], out[N], idx;
vvi G(N);
vvi ws(N);
int ans = INT_MAX;

void Dfs(int x = 1, int p = 0)
{
    w[x] = 1;
    t[x] = p;

    in[x] = ++idx;

    for(auto y : G[x])
    {
        if(y == p)continue;

        Dfs(y, x);

        w[x] += w[y];
    }

    out[x] = ++idx;
}

bool is_ancestor(int a, int b)
{
    return (in[a] <= in[b] && out[b] <= out[a]);
}

vi anc;
void Dfs1(int x)
{
    anc.pb(w[x]);///anc e desc

    int st = 0, dr = anc.size() - 1, p = 0;
    while(st <= dr)
    {
        int m = (st + dr) >> 1;
        if(anc[m] - w[x] <= n - anc[m])
        {
            p = m;
            dr = m - 1;
        }
        else st = m + 1;
    }

    int dif = max(w[x], max(anc[p] - w[x], n - anc[p])) -
            min(w[x], min(anc[p] - w[x], n - anc[p]));

    ans = min(ans, dif);

    --p;
    if(p >= 0)
    {
        int dif = max(w[x], max(anc[p] - w[x], n - anc[p])) -
            min(w[x], min(anc[p] - w[x], n - anc[p]));

        ans = min(ans, dif);
    }

    for(auto y : G[x])
        if(y != t[x])
            Dfs1(y);


    anc.pop_back();
}

set<int> st;
void Dfs2(int x)
{
    auto it = st.lower_bound((n - w[x]) / 2);
    if(it != st.end())
    {
        int dif = max(w[x], max(*it, n - w[x] - *it)) -
                min(w[x], min(*it, n - w[x] - *it));
        ans = min(ans, dif);

        ++it;
        if(it != st.end())
        {
            int dif = max(w[x], max(*it, n - w[x] - *it)) -
                min(w[x], min(*it, n - w[x] - *it));
            ans = min(ans, dif);
        }
        --it;
    }
    if(it != st.begin())
    {
        --it;

        int dif = max(w[x], max(*it, n - w[x] - *it)) -
                min(w[x], min(*it, n - w[x] - *it));
            ans = min(ans, dif);
    }

    for(auto y : G[x])
        if(y != t[x])
            Dfs2(y);

    st.insert(w[x]);
}

void solve()
{
    cin >> n;

    int a, b;
    FOR(i, 2, n)
    {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    Dfs();

    Dfs2(1);///sunt in arbori diferiti

    Dfs1(1);///arbore in arbore

    cout << ans << '\n';
}

int main()
{
    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
