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
using namespace std;

const int N =  2 * 1e5 + 9;
int v[N];

int main()
{
    fast_in_out;

    int n,x;
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    int cnt = 0,nr = 0;
    for(int i = 1; i <= n; ++i)
        if(v[i] != nr)
        {
            cnt ++;
            nr = v[i];
        }

    cout<<cnt;
    return 0;
}
