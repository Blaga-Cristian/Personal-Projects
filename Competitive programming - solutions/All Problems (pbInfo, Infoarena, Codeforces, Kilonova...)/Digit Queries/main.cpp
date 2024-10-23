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


ll mypow(ll b, ll exp)
{
    ll ans = 1;
    while(exp)
    {
        if(exp & 1)
            ans *= b;
        b = b*b;
        exp/=2;
    }
    return ans;
}

ll query(ll x)
{
    ll digits = 1;
    while(x > digits * 9 * mypow(10,digits-1))
    {
        x -= digits * 9 * mypow(10,digits-1);
        digits++;
    }
    ll nr = (digits == 1) ? nr = 1 : nr = mypow(10,digits-1);
    nr += (x-1) / digits;
    x = (x-1) % digits;
    return (ll)(nr / mypow(10,digits - x - 1)) % 10;
}

int main()
{
    ll q,x;
    cin>>q;
    while(q--)
    {
        cin>>x;
        cout<<query(x)<<'\n';
    }
    return 0;
}
