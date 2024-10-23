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

const int N = 2 * 1e5 + 9;

struct event
{
    int t;
    bool fn;
    int ind;
};
vector<event> events;
int room[N];

int main()
{
    int a,b;
    int n;
    cin >> n;
    REP(i, 1, n)
    {
        cin >> a >> b;
        events.PB({a,false, i});
        events.PB({b,true, i});
    }

    sort(events.begin(), events.end(),[](event a, event b){return a.t == b.t ? a.fn < b.fn : a.t < b.t;});

    int k = 0;
    queue<int> q;

    for(auto i : events)
    {
        if(!i.fn)
        {
            if(q.empty())
                q.push(++k);
            room[i.ind] = q.front();
            q.pop();
        }
        else
            q.push(room[i.ind]);
    }

    cout << k << '\n';
    REP(i, 1, n)
        cout << room[i] << ' ';
    return 0;
}
