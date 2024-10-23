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
map<int,int> last;
int cnt,ans;
int bck;

int main()
{
    cin>>n;
    bck = 1;
    REP(i,1,n)
    {
        cin >> x;

        if(last[x])
            bck = max(bck, last[x] + 1);

        last[x] = i;

        ans = max(ans, i - bck + 1);
    }
    cout<<ans;
    return 0;
}
