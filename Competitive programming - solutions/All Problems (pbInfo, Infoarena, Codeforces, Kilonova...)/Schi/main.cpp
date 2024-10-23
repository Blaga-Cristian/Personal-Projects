#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("schi.in");
ofstream cout("schi.out");
const int N = 30009;
int aib[N],v[N],n,sol[N];
void update(int x,int val)
{
    for(int i = x ;i<=n ; i+=i&-i)
        aib[i] += val;
}
int query(int x)
{

    int sum = 0;
    for(int i=x ; i>0; i-=i&-i)
        sum += aib[i];
    return sum;
}
int cblower(int val)
{
    int st = 1,dr = n, poz;
    while(st<=dr)
    {
        int mij = (st+dr)>>1;
        if(query(mij)>=val)
        {
            poz = mij;
            dr = mij -1;
        }
        else
            st = mij +1;
    }
    return poz;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    for(int i=1;i<=n;++i)
        update(i,1);
    for(int i=n;i>0; --i)
    {
        int poz = cblower(v[i]);
        sol[poz] = i;
        update(poz,-1);
    }
    for(int i=1;i<=n;++i)
        cout<<sol[i]<<'\n';
    return 0;
}
