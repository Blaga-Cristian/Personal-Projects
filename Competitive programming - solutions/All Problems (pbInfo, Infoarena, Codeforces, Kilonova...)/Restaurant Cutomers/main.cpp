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
int n,a,b;

PI v[2*N];

int main()
{
    cin>>n;
    REP(i,1,n)
    {
        int x,y;
        cin>>x>>y;
        v[2*i-1] = {x,1};
        v[2*i] = {y,-1};
    }

    sort(v + 1, v + 2 * n + 1, [](PI a,PI b){return a.F < b.F;});

    int cur = 0, maxi = -1;
    for(int i = 1; i <= 2 * n; cur += v[i].S, ++i, maxi = max(maxi, cur));

    cout<<maxi;
    return 0;
}
