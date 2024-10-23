#include <cstdio>
using namespace std;
FILE *fin=fopen("turnuri.in","r");
FILE *fou=fopen("turnuri.out","w");
int n,a[300],r[300];
long double res=0;

void read()
{
    int i;
    n=0;
    while (1)
    {
        fscanf(fin,"%d",&i);
        if (!i) break;
        a[n++]=i;
    }
}

int modn(int x,int n)
{
    while(x<0)
        x+=n;
    return x%n;
}

void solve()
{
    int i,j,k,l;
    long double count[500],c2[500];
    for(i=0;i<500;++i)
        count[i]=0;
    if(a[0]%2==0)
        count[0]=1;
    else
        count[1]=1;
    for(l=1;l<n;++l)
    {
        for(j=0;j<n*2;++j)
            c2[j]=0;
        k=a[l];
        for(i=0;i<k;++i)
            for(j=0;j<2*l;++j)
                if(i!=0||j!=0)
        c2[modn(j+k-2*i,2*(l+1))]+=count[j];
        res=0;
        for(j=0;j<n*2;++j)
            res+=count[j]=c2[j];
    }
}

void write()
{
    fprintf(fou,"%.0lf\n",(double)res);
}

int main(int argc,char *argv[])
{
    read();
    solve();
    write();
    return 0;
}
