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
int dp[L][L];
string a, b;

int main()
{
    cin >> a >> b;

    for(int i = 0; i <= a.size(); ++i)
        dp[i][0] = i;
    for(int j = 0; j <= b.size(); ++j)
        dp[0][j] = j;

    for(int i = 1; i <= a.size(); ++i)
        for(int j = 1; j <= b.size(); ++j)
    {
        dp[i][j] = min(dp[i][j-1] + 1, min(dp[i-1][j] + 1, dp[i-1][j-1] + 1));

        if(a[i-1] == b[j-1])
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
    }


    cout << dp[a.size()][b.size()];
    return 0;
}
