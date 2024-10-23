#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("numere20.in");
ofstream cout("numere20.out");
typedef int NrMare[200];
void scadere(NrMare a,NrMare b)
{
    int i,j,t=0,x;
    for(i=1;i<=a[0];i++)
    {
        if(i>b[0])x=0;
        else x=b[i];
        if(a[i]>=x)a[i]-=x;
        else
        {
            j=i+1;
            while(a[j]==0)a[j++]=9;
            a[j]--;
            a[i]=10+a[i]-x;
        }
    }
    while(a[0]>1&&a[a[0]]==0)a[0]--;
}
void adunare(NrMare a,NrMare b)
{
    int x=a[0],t=0,i;
    if(a[0]<b[0])x=b[0];
    for(i=1;i<=x;i++)
    {
        if(a[0]<i)
        {
            t=t+b[i];
            a[i]=t%10;
            t=t/10;
        }
        else if(b[0]<i)
        {
            t=t+a[i];
            a[i]=t%10;
            t=t/10;
        }
        else
        {
            t=t+a[i]+b[i];
            a[i]=t%10;
            t=t/10;
        }
    }
    if(t)a[++a[0]]=t;
}
void impartire(NrMare s,NrMare sursa,int a)
{
    int r=0,i;
    s[0]=sursa[0];
    for(i=sursa[0];i>=1;i--)
    {
        r=r*10+sursa[i];
        s[i]=r/a;
        r=r%a;
    }
    while(s[s[0]]==0&&s[0]>1)s[0]--;
}
int main()
{
    char s[101];
    int i,u,v;
    NrMare n,n1,n2;
    for(i=0;i<=200;i++)
    {
        n[i]=0;
        n1[i]=0;
        n2[i]=0;
    }
    cin>>s;
    cin.get();
    n[0]=strlen(s);
    for(i=1;i<=strlen(s);i++)
    {
        n[i]=s[strlen(s)-i]-'0';
    }
    cin>>u>>v;
    impartire(n1,n,u);
    impartire(n2,n,v);
    adunare(n1,n2);
    impartire(n2,n,u*v);
    scadere(n,n1);
    adunare(n,n2);
    for(i=n[0];i>=1;i--)cout<<n[i];
    return 0;
}
