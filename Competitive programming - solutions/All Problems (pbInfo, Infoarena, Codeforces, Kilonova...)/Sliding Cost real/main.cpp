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

ll n, k;
ll v[N];
multiset<ll> l, r;


ll rsum, lsum;

void adauga(ll x)
{
    if(l.size() == 0)
    {
        l.insert(x);
        lsum += x;
        return;
    }

    ll med = *l.rbegin();

    if(x <= med) l.insert(x), lsum += x;
    else r.insert(x), rsum += x;

    if(l.size() > r.size() + 1)
    {
        med = *l.rbegin();
        l.erase(l.find(med)), lsum -= med;
        r.insert(med), rsum += med;
    }
    else if(l.size() < r.size())
    {
        med = *r.begin();
        r.erase(r.find(med)), rsum -= med;
        l.insert(med), lsum += med;
    }
}

void elimina(ll x)
{
    ll med = *l.rbegin();

    if(x <= med)l.erase(l.find(x)), lsum -= x;
    else r.erase(r.find(x)), rsum -= x;;

    if(l.size() > r.size() + 1)
    {
        med = *l.rbegin();
        l.erase(l.find(med)), lsum -= med;
        r.insert(med), rsum += med;
    }
    else if(l.size() < r.size())
    {
        med = *r.begin();
        r.erase(r.find(med)), rsum -= med;
        l.insert(med), lsum += med;
    }
}



int main()
{
    fast_in_out

    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    for(int i = 1; i < k; ++i)
        adauga(v[i]);

    for(int i = k; i <= n; ++i)
    {
        adauga(v[i]);

        ll med = *l.rbegin();
        cout << (med * l.size() - lsum) + (rsum - 1LL * med * r.size()) << ' ';

        elimina(v[i - k + 1]);
    }
    return 0;
}
