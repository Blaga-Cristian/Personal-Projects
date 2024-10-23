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
int cnt, n, x;

int main()
{
    int n;
    cin >> n >> x;
    REP(i, 1, n)
        cin >> v[i];

    int st = 1, dr = 0;
    ll sum = 0;
    while(dr <= n)
    {
        while(sum < x)sum += v[++dr];
        while(sum > x)sum -= v[st++];

        if(sum == x)
        {
            cnt ++;
            sum += v[++dr];
        }
    }

    cout << cnt;
    return 0;
}
