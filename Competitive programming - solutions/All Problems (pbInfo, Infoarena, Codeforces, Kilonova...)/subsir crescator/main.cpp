#include <iostream>
#include <algorithm>
using namespace std;
const int Inf = 0x3f3f3f3f;
int n,v[100];
int c[100],len;
void solve()
{
    for(int i=1;i<=n;++i)
        c[i] = Inf;
    for(int i=1;i<=n;++i)
    {
        int pz = upper_bound(c+1,c+len+1,v[i]) - c;
        if(pz>len && v[i] != c[len])
            ++len;
        c[pz] = v[i];
    }
    cout<<len;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    solve();
    return 0;
}
