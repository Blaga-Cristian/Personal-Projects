#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("extraprime.in");
ofstream cout("extraprime.out");
bool v[100001];
int main()
{
    int n,k,i,a,b,j,s=0,num=10,p;
    cin>>a>>b;
    v[0]=1;
    v[1]=1;
    for(i=1;i<=sqrt(b);i++)
        if(v[i]==0)
        for(j=2;j<=n/i;j++)v[i*j]=1;
    for(i=a;i<=b;i++)
    {
        s=i;
        k=0;
        while(s!=0)
        {
            k++;
            s=s/10;
        }
        s=i;
        if(v[s]==0)
        {
        p=10;
        for(j=1;j<=k;j++)
        {
            s=s-i%p;
            s=s/10;
            s=s+i%(p/10);
            p=p*10;
            cout<<s<<endl;
        }
        }
    }
    return 0;
}
