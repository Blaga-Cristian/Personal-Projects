#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("third.in");
ofstream cout("third.out");
const int N = 1e5 + 9;
int n,k,v[N],a,b,x,y,aux[N];
int aib[N];
void update(int x,int val)
{
    for(;x <= n; x += x&-x)
        aib[x]+=val;
}
int query(int x)
{
    int ret = 0;
    for(;x; x -= x&-x)
        ret += aib[x];
    return ret;
}
int cbaib(int s)
{
    int sum = 0;
    int pos = 0;
    int step = 1;
    for(;step < n;step<<=1);
    for(;step;step>>=1)
        if(pos + step <= n && sum + aib[pos + step] < s)
    {
        sum += aib[pos+step];
        pos += step;
    }
    return pos + 1;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>v[i],aux[i] = v[i];

    ///NORMALIZARE
    sort(aux+1,aux+n+1);
    int sf = unique(aux+1,aux+n+1) - aux;
    for(int i = 1; i <= n; ++i)
        v[i] = lower_bound(aux+1,aux+sf,v[i]) - aux;

    for(int i = 1; i <= k; ++i)
        update(v[i],1);
    long long ans = 0;
    ans += aux[cbaib(3)];
    for(int i = k+1;i <= n; ++i)
    {
        update(v[i-k],-1);
        update(v[i],1);
        ans += aux[cbaib(3)];
    }
    cout<<ans;
    return 0;
}
