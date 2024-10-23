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

const int N = 2 * 1e5;

int n, ans[2][N], ds[2 * N];
triple ranges[N];
set<int> unique_vals;
map<int,int> mp;

int main()
{
    int n;
    cin >> n;
    REP(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        ranges[i] = {x, y, i};
        unique_vals.insert(x);
        unique_vals.insert(y);
    }

    sort(ranges, ranges + n, [](triple A, triple B)
         {
             return A[0] == B[0] ? A[1] > B[1] : A[0] < B[0];
         });

    int val_id = 1;
    for(int x : unique_vals)
        mp[x] = val_id ++;

    for(int i = n - 1; i >= 0; --i)
    {
        int y = mp[ranges[i][1]];
        int id = mp[ranges[i][2];

        ans[0][id] = query(y);
        update(y, 1);
    }

    fill

    return 0;
}
