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

int main()
{
    int n;
    cin>>n;
    int cnt2 = 0, cnt5 = 0, d;
    for(d = 2; n / d; d *= 2)
        cnt2 += n/d;
    for(d = 5; n / d; d *= 5)
        cnt5 += n/d;
    cout<<min(cnt2,cnt5);
    return 0;
}
