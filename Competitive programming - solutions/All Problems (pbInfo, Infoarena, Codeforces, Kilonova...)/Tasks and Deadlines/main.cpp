#include <bits/stdc++.h>
#include <bits/extc++.h>
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

const int N = 2* 1e5 + 9;
int n,a, d;
int dur[N];

int main()
{
    cin >> n;
    ll scor = 0;
    REP(i, 1, n)
    {
        cin >> a >> d;
        scor += d;
        dur[i] = a;
    }

    sort(dur + 1, dur + n+ 1);

    ll t = 0;
    REP(i, 1, n)
    {
        t += dur[i];
        scor -= t;
    }

    cout << scor;
    return 0;
}
