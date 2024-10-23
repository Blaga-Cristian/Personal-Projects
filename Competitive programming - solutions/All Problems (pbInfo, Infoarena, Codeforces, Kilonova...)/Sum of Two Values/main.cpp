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
int n,x;
PI v[N];

int main()
{
    cin >> n >> x;
    REP(i,1,n)
    {
        cin>>v[i].F;
        v[i].S = i;
    }

    sort(v + 1, v + n + 1);

    int st = 1, dr = n;
    while(st < dr)
    {
        if(0LL + v[st].F + v[dr].F == x)
        {
            cout << v[st].S << ' ' << v[dr].S;
            return 0;
        }
        else if(0LL + v[st].F + v[dr].F > x)
            dr --;
        else
            st ++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}
