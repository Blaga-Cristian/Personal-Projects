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
int v[N];

int main()
{
    int n;
    cin>>n;
    REP(i,1,n)
        cin>>v[i];

    sort(v + 1, v + n + 1);

    int med = v[(n + 1)/2];
    ll dif = 0;
    for(int i = 1; i <= n; ++i)
        dif += abs(v[i] - med);
    cout<<dif;
    return 0;
}
