#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b)
#define int long long
using namespace std;
const int N = 3e5 + 9;
const bool test_cases = true;

int n, m, id[N];

void solve()
{
    cin >> n >> m;

    vector<vector<char>> mat(n + 1, vector<char>(m + 1));
    FOR(i, 1, n)
        FOR(j, 1, m)
            cin >> mat[i][j];

    int idx = 0;
    FOR(i, 1, m)id[i] = 0;

    FOR(i, 1, n)
    {
        map<int, int> nid;

        FOR(j, 1, m)
        {
            if(mat[i][j] == '1')continue;
            if(nid.find(id[j]) == nid.end())nid[id[j]] = ++idx;
            id[j] = nid[id[j]];
        }

        nid.clear();

        FOR(j, 1, m)
        {
            if(mat[i][j] == '0')continue;
            if(nid.find(id[j]) == nid.end())nid[id[j]] = ++idx;
            id[j] = nid[id[j]];
        }
    }

    map<int, int> cnt;
    FOR(i, 1, m)cnt[id[i]] ++;

    int ans = 0;
    for(auto [_, nr] : cnt)
        ans = max(ans, nr);

    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
