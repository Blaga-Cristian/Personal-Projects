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

int v[N];
int ans[N];

int main()
{
    int n;
    cin >> n;
    REP(i, 1, n)
    {
        cin >> v[i];
        int k = i - 1;
        while(v[k] >= v[i])
            k = ans[k];
        ans[i] = k;
    }

    REP(i, 1, n)
        cout << ans[i] << ' ';
    return 0;
}
