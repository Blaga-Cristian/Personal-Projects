#include <bits/stdc++.h>
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
multiset<int> myset;

int main()
{
    fast_in_out

    cin>>n>>m;
    REP(i,0,n - 1)
    {
        cin>>x;
        myset.insert(x);
    }

    while(m --)
    {
        cin>>x;
        auto itr = myset.upper_bound(x);
        if(itr == myset.begin())cout<<"-1\n";
        else
        {
            itr--;
            cout<<*(itr)<<'\n';
            myset.erase(itr);
        }
    }
    return 0;
}
