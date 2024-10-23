#include <fstream>

using namespace std;
ifstream fin("sumagauss1.in");
ofstream fout("sumagauss1.out");
typedef int NrMare[1010];
NrMare s;
void inmultire(int *a,int *b)
{
    int z[a[0]+b[0]],i,j,t=0;
    z[0]=z[0]+b[0]-1;
    for(i=1;i<=z[0]+1;i++)z[i]=0;
    for(i=1;i<=a[0];i++)
    {
        for(j=1;j<=b[0];j++)
        {
            z[i+j-1]+=a[i]*b[j];
        }
    }
    for(i=1;i<=z[0];i++)
    {
        t=t+z[i];
        z[i]=t%10;
        t=t/10;
    }
    while(t)
    {
        z[++z[0]]=t%10;
        t=t/10;
    }
    for(i=0;i<=z[0];i++)a[i]=z[i];
    fout<<z[0]<<endl;
}
void impartire(NrMare n,int b)
{

}
void calcul(int a)
{
    NrMare n,n1,n2;
    int i,t=0,q=0,j;
    for(i=0;i<=1000;i++)
    {
        n[i]=0;
        n1[i]=0;
        n2[i]=0;
    }
    while(a!=0)
    {
        n[++n[0]]=a%10;
        n1[++n1[0]]=a%10;
        n2[++n2[0]]=a%10;
        a=a/10;
    }
    n1[1]+=1;
    n2[1]+=2;
    for(i=1;i<=n[0];i++)
    {
        t=t+n1[i];
        n1[i]=t%10;
        t=t/10;
        q=q+n2[i];
        n2[i]=q%10;
        q=q/10;
    }
    if(t)n1[++n1[0]]=t;
    if(q)n2[++n2[0]]=q;
    t=0;
    q=0;
    int np[2*n[0]];
    np[0]=2*n[0]-1;
    for(i=1;i<=np[0];i++)np[i]=0;
    for(i=1;i<=n[0];i++)
    {
        for(j=1;j<=n[0];j++)
        {
            np[i+j-1]+=n[i]*n[j];
        }
    }
    for(i=1;i<=np[0];i++)
    {
        t=t+np[i];
        np[i]=t%10;
        t=t/10;
    }
    if(t)np[++np[0]]=t;
    t=0;
    for(i=1;i<=np[0];i++)
    {
        if(i<=n[0])t=t+np[i]*3+6*n[i];
        else t=t+np[i]*3;
        np[i]=t%10;
        t=t/10;
    }
    while(t)
    {
        np[++np[0]]=t%10;
        t=t/10;
    }
    t=0;
    np[1]++;
    for(i=1;i<=np[0];i++)
    {
        t=t+np[i];
        np[i]=t%10;
        t=t/10;
    }
    while(t)np[++np[0]]=t;
    t=0;
    inmultire(n,n1);
    for(i=n[0];i>=1;i--)fout<<n[i];
    inmultire(n,n2);
    inmultire(n,np);
    //impartire(n,60);
    //for(i=n[0];i>=1;i--)fout<<n[i];
}
int main()
{
    int n,i;
    s[0]=1;
    fin>>n;
    calcul(n);
    //for(i=s[0];i>=1;i--)fout<<s[i];
    return 0;
}
