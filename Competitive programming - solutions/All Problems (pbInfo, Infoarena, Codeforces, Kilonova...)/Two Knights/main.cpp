#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int,int>
#define F first
#define S second
#define PB push_back
using namespace std;

int main()
{
    int n;
    cin>>n;

    cout<<"0\n";
    for(int k = 2; k <= n; ++k)
        cout<<1LL * k*k*(k*k - 1)/2 - 1LL * 4 * (k-1) * (k-2)<<'\n';
    return 0;
}
