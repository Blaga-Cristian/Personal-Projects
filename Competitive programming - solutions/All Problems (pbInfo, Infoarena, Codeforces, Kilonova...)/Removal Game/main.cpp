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
const int L = 5009;

int v[L];
ll dp[L][L];
ll sum;
int n;
ll difmin = 99999;
ll ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> v[i], sum += v[i];

    for(int i = 1; i <= n; ++i)
        for(int j = n; i - 1 + n - j <= n; --j)
        {
            if((i - 1 + n - j) % 2 == 1)
            {
                if(i > 1)dp[i][j] = max(dp[i][j], dp[i - 1][j] + v[i - 1]);
                if(j < n)dp[i][j] = max(dp[i][j], dp[i][j + 1] + v[j + 1]);
            }
            else
            {
                if(i > 1)dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j < n)dp[i][j] = max(dp[i][j], dp[i][j + 1]);
            }
        }

    for(int i = 0; i <= n + 1; ++i)
        for(int j = 0; j <= n + 1; ++j)
            if((i - 1 + n - j) == n + 1)
            {
                if(difmin > abs(sum - dp[i][j]))
                {
                    difmin = abs(sum - dp[i][j]);
                    ans = dp[i][j];
                }
                else if(difmin == abs(sum - dp[i][j]) && ans < dp[i][j])
                    ans = dp[i][j];
            }

    cout << ans;
    return 0;
}
