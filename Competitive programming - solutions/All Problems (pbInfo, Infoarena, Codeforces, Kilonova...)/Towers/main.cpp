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
const int N = 2 * 1e5 + 8;

int n,x;
int v[N];
vector<int> towers;

int main()
{
    cin >> n;
    REP(i,1,n)
    {
        cin >> x;
        auto poz = upper_bound(towers.begin(), towers.end(), x);
        if(poz == towers.end())
            towers.PB(x);
        else
            *poz = x;
    }

    cout<<towers.size();
    return 0;
}
