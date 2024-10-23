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
int n;
PI v[N];

int main()
{
    cin>>n;
    REP(i,1,n)
        cin>>v[i].F>>v[i].S;

    sort(v + 1, v + n + 1, [](PI a, PI b){return a.S < b.S;});

    int curf = -1;
    int cnt = 0;
    REP(i,1,n)
        if(curf <= v[i].F)
        {
            ++cnt;
            curf = v[i].S;
        }

    cout<<cnt;
    return 0;
}
