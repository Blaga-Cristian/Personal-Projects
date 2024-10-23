#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#include <bits/extc++.h>
#define mp make_pair
///DISTANCE FOR SETS IS LINIAR
using namespace std;
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 9;

int n, l[N], r[N], k[N], ans[N], len_order[N], k_order[N];

int main()
{
    cin >> n;

    FOR(i, 1, n)
    {
        cin >> l[i] >> r[i] >> k[i];
        len_order[i] = k_order[i] = i;
    }

    sort(len_order + 1, len_order + n + 1, [](int a, int b){return mp(r[a] - l[a], a) > mp(r[b] - l[b], b);});
    sort(k_order + 1, k_order + n + 1, [](int a, int b){return mp(k[a], a) > mp(k[b], b);});

    oset<array<int, 2>> l_e, r_e;
    for(int i = 1, j = 1; i <= n; ++i)
    {
        for(; j <= n && r[len_order[j]] - l[len_order[j]] >= k[k_order[i]]; ++j)
        {
            l_e.insert({l[len_order[j]], j});
            r_e.insert({r[len_order[j]], j});
        }

        ans[k_order[i]] = j - 1;
        ans[k_order[i]] -= j - l_e.order_of_key({r[k_order[i]] - k[k_order[i]] + 1, -1});
        ans[k_order[i]] -= r_e.order_of_key({l[k_order[i]] + k[k_order[i]], -1});
    }

    FOR(i, 1, n)cout << ans[i] << '\n';
    return 0;
}
