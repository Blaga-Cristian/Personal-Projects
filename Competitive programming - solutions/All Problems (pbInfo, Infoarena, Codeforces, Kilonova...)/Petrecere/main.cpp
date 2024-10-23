#include <fstream>
#define ull unsigned long long
using namespace std;
ifstream cin("petrecere.in");
ofstream cout("petrecere.out");
const int N = 3009;
typedef int NrMare[4000];
int n;
NrMare a,b,c;
void inmultire(int x)
{
    a[0] = c[0];
    for(int i=1;i<=c[0];++i)
        a[i] = c[i];
    ull t = 0;
    for(int i=1;i<=a[0];++i,t=t/10)
        a[i] = (t+=(a[i]*x))%10;
    while(t)
        a[++a[0]]=t%10,
        t = t/10;
}
void aduna()
{
    ull t = 0;
    for(int i=1;i<=a[0];++i,t=t/10)
        a[i] = (t+=a[i]+b[i])%10;
    while(t)
        a[++a[0]] = t%10,t=t/10;
}
void atribuie(NrMare& x,NrMare& y)
{
    int nr = max(x[0],y[0]);
    for(int i=0;i<=nr;++i)
        x[i] = y[i];
}
void afiseaza()
{
    for(int i = a[0];i>=1;--i)
        cout<<a[i];
    cout<<'\n';
}
int main()
{
    cin>>n;
    c[0] = 1,c[1] = 1;
    b[0] = 1,b[1] = 2;
    if(n<=2)
    {
        if(n==1)cout<<1;
        if(n==2)cout<<2;
        return 0;
    }

    for(int i=3;i<=n;++i)
    {
        //a = b + x*c;
        inmultire(i-1);
        aduna();
        //c = b;
        atribuie(c,b);
        //b = a;
        atribuie(b,a);
        //dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }
    afiseaza();
    return 0;
}
