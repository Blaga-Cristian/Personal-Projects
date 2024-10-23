#include <fstream>
#include <algorithm>
#define ll long long
using namespace std;
ifstream cin("secventak.in");
ofstream cout("secventak.out");
const int N = 100009;
ll n,k,sp[N],v[N],vind[N],suma,cnt,aib[N];
void Update(int poz)
{
    for(int i=poz;i<=n;i+=i&-i)
        aib[i]++;
}
ll Query(int poz)
{
    ll sum = 0;
    for(int i=poz;i;i-=i&-i)
        sum+=aib[i];
    return sum;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    for(int i=1;i<=n;++i)
    {
        suma+=v[i];
        sp[i] = suma - k*i;
        v[i] = sp[i];
        if(sp[i]>=0)cnt++;
    }
    sort(sp+1,sp+n+1);
    for(int i=1;i<=n;++i)
        vind[i] = lower_bound(sp+1,sp+n+1,v[i]) - sp;
    for(int i=1;i<=n;++i)
    {
        cnt += Query(vind[i]);
        Update(vind[i]);
    }
    cout<<cnt;
    return 0;
}
