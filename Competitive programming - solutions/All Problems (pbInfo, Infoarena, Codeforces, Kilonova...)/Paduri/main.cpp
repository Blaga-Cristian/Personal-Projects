#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5*2 + 9;
int n,i,x[N],y[N],auxx[N],auxy[N];
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin>>x[i]>>y[i];
        auxx[i] = x[i];
        auxy[i] = y[i];
    }

    ///NORMALIZARE
    sort(auxx+1,auxx+n+1);
    sort(auxy+1,auxy+n+1);
    for(int i=1;i<=n;++i)
    {
        x[i] = lower_bound(auxx+1,auxx+n+1,x[i]) - auxx;
        y[i] = lower_bound(auxy+1,auxy+n+1,x[i]) - auxy;
    }


    return 0;
}
