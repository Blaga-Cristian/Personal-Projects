#include <bits/stdc++.h>
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
using namespace std;

const int N = 2 * 1e5 + 9;

int n,m,x;

int main()
{
    fast_in_out

    cin >> n >> m;

    set<int> lights{0,n};
    multiset<int> dist{n};

    while(m--)
    {
        cin >> x;

        auto it1 = lights.upper_bound(x);
        auto it2 = it1;
        it2--;

        dist.erase(dist.find(*it1 - *it2));
        dist.insert(x - *it2);
        dist.insert(*it1 - x);
        lights.insert(x);

        auto ans = dist.end();
        ans--;
        cout<<*ans<<' ';
    }
    return 0;
}
