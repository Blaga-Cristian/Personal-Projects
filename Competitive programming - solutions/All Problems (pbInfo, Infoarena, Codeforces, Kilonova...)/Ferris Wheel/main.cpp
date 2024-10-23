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

const int N = 2 * 1e5 + 9;
int v[N];
int cnt;

int main()
{
    int n,x;
    cin>>n>>x;
    for(int i = 1; i <= n; ++i)
        cin>>v[i];

    sort(v + 1, v + n + 1);

    int st = 1, dr = n;
    while(st <= dr)
    {
        if(1LL * v[st] + v[dr] <= x)
        {
            st ++;
            dr --;
        }
        else
            dr --;

        cnt++;
    }

    cout<<cnt;
    return 0;
}
