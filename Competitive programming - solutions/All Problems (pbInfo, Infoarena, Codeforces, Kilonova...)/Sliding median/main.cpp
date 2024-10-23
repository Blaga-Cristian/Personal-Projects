#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define PI pair<int,int>
typedef tree <PI, null_type, less<PI>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int N = 2 * 1e5 + 9;
int n, k, x;
int v[N];
ll sum;
int t;


int aib[N];
int aibsum[N];


int main()
{
    cin >> n >> k;

    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    indexed_set myset;

    for(int i = 1; i <= n; ++i)
    {
        sum += v[i];
        myset.insert({v[i], ++t});
        if(i >= k)
        {
            cout << sum - k * (*myset.find_by_order((k + 1) / 2 - 1)).first << ' ';
            myset.erase(myset.lower_bound({v[i - k + 1], 0}));
            sum -= v[i-k+1];
        }
    }

    return 0;
}
