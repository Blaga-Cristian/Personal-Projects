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

const ll Inf = 1LL << 62;

int main()
{
    int n;
    cin>>n;
    int x;
    ll sum = -Inf, maxi = -Inf;
    for(int i = 1; i <= n; ++i)
    {
        cin>>x;
        sum = max(sum + x, 1LL * x);
        maxi = max(maxi, sum);
    }
    cout<<maxi;
    return 0;
}
