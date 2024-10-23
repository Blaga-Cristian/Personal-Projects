#include <bits/stdc++.h>
#include <bits/extc++.h>
#define MP make_pair
#define MT make_tuple
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
typedef array<int,3> triple;

const int Inf = 0x3f3f3f3f, N = 1e5 + 9, V = 109;
const int Mod = 1e9 + 7;

int v[109];
bool dp[N];
int sum;
int n;

int main()
{

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], sum += v[i];

    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int s = sum - v[i]; s >= 0; --s)
            if(dp[s])
                dp[s + v[i]] = true;

    vector<int> ans;
    for(int i = 1; i <= sum; ++i)
        if(dp[i])
            ans.PB(i);

    cout << ans.size() << '\n';
    for(auto i : ans)
        cout << i << ' ';
    return 0;
}
