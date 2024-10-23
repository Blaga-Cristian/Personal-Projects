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

const int N = 5009;

int n,x;
ll v[N];
int p[N];

tuple<bool, int, int> sum2(int val,int st,int dr)
{
    int p1 = st, p2 = dr;
    while(p1 < p2)
    {
        if(v[p1] + v[p2] == val)
            return MT(true, p1, p2);
        else if(v[p1] + v[p2] < val)
            ++ p1;
        else
            -- p2;
    }
    return MT(false, 0, 0);
}

tuple<bool, int, int, int> sum3(int val, int st, int dr)
{
    for(int i = st; i + 2 <= dr; ++i)
    {
        auto ans = sum2(val - v[i], i + 1, dr);
        bool ok;
        int p1, p2;
        tie(ok, p1, p2) = ans;
        if(ok)
            return MT(true, i, p1, p2);
    }
    return MT(false, 0, 0, 0);
}

int main()
{
    cin >> n >> x;
    REP(i, 1, n)
        cin >> v[i],p[i] = i;

    sort(p + 1, p + n + 1, [](int a,int b){return v[a] < v[b];});
    sort(v + 1, v + n + 1);


    auto ans = sum3(x, 1, n);
    bool ok;
    int p1, p2, p3;
    tie(ok, p1, p2, p3) = ans;

    if(ok)
        cout << p[p1] << ' ' << p[p2] << ' ' << p[p3];
    else
        cout << "IMPOSSIBLE";
    return 0;
}
