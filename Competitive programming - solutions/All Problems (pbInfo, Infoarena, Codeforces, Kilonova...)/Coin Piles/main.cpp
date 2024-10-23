#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int,int>
#define F first
#define S second
#define PB push_back
#define ll long long
#define ull unsigned ll
using namespace std;

void solve()
{
    int a,b;
    cin>>a>>b;
    if(a > b)
        swap(a,b);
    int dif = b - a;
    if(a >= dif && (a - dif) % 3 == 0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
