#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

using namespace std;
const int N = 3e5 + 9;

int n, m, dp[N], aux[N];

struct edge
{
    int u, v, w;

    bool operator < (edge const& oth)
    {
        return w < oth.w;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//     cout.tie(0);

    cin >> n >> m;

    vector<edge> edges(m);
    FOR(i, 0, m - 1)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end());

    FOR(i, 0, m - 1)
    {
        for(int j = i; j < m && edges[j].w == edges[i].w; ++j)
            aux[edges[j].v] = max(aux[edges[j].v], dp[edges[j].u] + 1);

        int j;
        for(j = i; j < m && edges[j].w == edges[i].w; ++j)
        {
            dp[edges[j].v] = max(dp[edges[j].v], aux[edges[j].v]);
            aux[edges[j].v] = 0;
        }

        i = j - 1;
    }

    cout << *max_element(dp + 1, dp + n + 1) << '\n';
    return 0;
}
