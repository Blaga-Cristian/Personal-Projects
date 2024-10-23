#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;
ifstream cin("radiera.in");
ofstream cout("radiera.out");
int n,v[1005],c[1005],len,p[1005];
int ans = -1;

void cmlsc()
{
    for(int i=n;i>=1;--i)
    {
        int poz = lower_bound(c+1,c+len+1,v[i]) - c;
        if(poz>len)++len;
        c[poz] = v[i];
        //p[i] = poz;
        ans = max(ans,poz);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    cmlsc();
    cout<<n-ans<<'\n';
    return 0;
}

