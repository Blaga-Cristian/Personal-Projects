#include <bits/stdc++.h>
#include <bits/extc++.h>
#define MT make_tuple
#define MP make_pair
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int,int>
#define F first
#define S second
#define PB push_back
#define ll long long
#define ull unsigned ll
#define fast_in_out ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define REP(i,a,b) for(int i = a; i <= b; ++i)
template <typename T>
using indexed_set = __gnu_pbds::tree <T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

using namespace std;

const int N = 2 * 1e5 + 9;
ll v[N];
ll sum;
ll n, x, ans;

int main()
{
    cin >> n >> x;
    REP(i, 1, n)
        cin >> v[i];

    ll prefix_sum = 0;
    map<ll,int> sums;
    sums[0] = 1;
    REP(i, 1, n)
    {
        prefix_sum += v[i];
        ans += sums[prefix_sum - x];
        sums[prefix_sum] ++;
    }

    cout << ans;
    return 0;
}
