#include <fstream>
#include <cstdio>
#define ull unsigned long long
#define ll long long
#define BASE 10000
#define MAX 200000
#define MAXLEN 200010
#define MAXN 200010
using namespace std;
int a[MAXLEN];
int v[MAXN];
int p[MAXN],nr,desc[MAXN],n;
void inmultire(int v[],int x)
{
    int i,t=0;
    for(i=1;i<=v[0]||t;++i,t/=BASE)
        v[i]=(t+=v[i]*x)%BASE;
    v[0]=i-1;
}
void ciur(int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        if(v[i]==0)
        {
            p[++nr]=i;
            for(j=2*i;j<=n;j+=i)v[j]=1;
        }
    }
}
int main()
{
    freopen("pastile.in","r",stdin);
    freopen("pastile.out","w",stdout);
    a[0]=1;
    a[1]=1;
    int i,j,x;
    scanf("%d",&n);
    ciur(2*n);
    for(i=n+2;i<=2*n;i++)
    {
        x=i;
        for(j=1;p[j]*p[j]<=x;j++)
        {
            while(x%p[j]==0)
            {
                x=x/p[j];
                ++desc[j];
            }
        }
        if(x!=1)
        {
            x=lower_bound(p+1,p+nr+1,x)-p;
            ++desc[x];
        }
    }
    for(i=2;i<=n;i++)
    {
        x=i;
        for(j=1;p[j]*p[j]<=x;j++)
        {
            while(x%p[j]==0)
            {
                x=x/p[j];
                --desc[j];
            }
        }
        if(x!=1)
        {
            x=lower_bound(p+1,p+nr+1,x)-p;
            --desc[x];
        }
    }
    x=1;
    i=1;
    while(true)
    {
        while(i<=nr&&desc[i]==0)i++;
        if(i>nr)break;
        --desc[i];
        if(x>MAX/p[i])
        {
            inmultire(a,x);
            x=p[i];
        }
        else x*=p[i];
    }
    inmultire(a,x);
    printf("%d",a[a[0]]);
    for(i=a[0]-1;i>=1;i--)printf("%.4d",a[i]);
    return 0;
}
