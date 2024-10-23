#include <fstream>

using namespace std;
ifstream cin("prim023.in");
ofstream cout("prim023.out");
int E[35005],prime[6001],nrp;
bool Prim(int n)
{
    if(n==0||n==1)return 0;
    else if(n==2)return 1;
    else if(n%2==0)return 0;
    else for(int i=1;prime[i]*prime[i]<=n&&i<=nrp;i++)if(n%prime[i]==0)return 0;
    return 1;
}
int main()
{
    int n , cnt = 0 , p = 0 , x , c = 1 , a[10001],i;
    cin>>n;
    for(i=2;i<35000;i++)E[i]=1;
    for(i=2;i<35000;i++)
        if(E[i]==1)
        {
            prime[++nrp]=i;
            for(int j=i*i;j<35000;j=j+i)E[j]=0;
        }
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(Prim(x))cnt++;
        if(x==1)p++;
    }
    while(cnt!=0)
    {
        a[c]=cnt%10;
        cnt=cnt/10;
        c++;
    }
    c--;
    for(i=1;i<=p;i++)
    {
        int t=0;
        for(int j=1;j<=c;j++,t/=10)
        {
            t=2*a[j]+t;
            a[j]=t%10;
        }
        while(t)
        {
            a[++c]=t%10;
            t=t/10;
        }
    }
    for(i=c;i>=1;i--)cout<<a[i];
    if(c==0)cout<<c;
    return 0;
}
