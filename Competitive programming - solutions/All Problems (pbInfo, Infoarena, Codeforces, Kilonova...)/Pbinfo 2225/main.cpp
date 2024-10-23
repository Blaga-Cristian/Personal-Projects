#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("baza.in");
ofstream cout("baza.out");
void adunare(int a[] , int b[])
{
    int i,t=0;
    if(a[0]<b[0])a[0]=b[0];
    for(i=1;i<=a[0];i++,t/=10)
    {
        t=a[i]+b[i]+t;
        a[i]=t%10;
    }
    if(t)
    {
        a[0]++;
        a[a[0]]=t;
    }
}
void inmultire(int a[],int b)
{
    int i,t=0;
    for(i=1;i<=a[0];i++,t/=10)
    {
        t=a[i]*b+t;
        a[i]=t%10;
    }
    for(;t;t/=10)
    {
        a[0]++;
        a[a[0]]=t%10;
    }
}
int a[51],v[1500],v1[]={1,1};
int main()
{
    char s[51],j;
    int k=1;
    int i;
    cin >> s;
    a[0]=strlen(s);
    for(i=strlen(s)-1;i>=0;i--)
    {
        a[k]=s[i]-'a';
        k++;
    }
    for(i=1;i<=a[0];i++)
    {
        for(k=1;k<=v1[0];k++)
        {
            v1[k]=0;
        }
        v1[0]=1;
        v1[1]=1;
        for(j=2;j<=i;j++)
            inmultire(v1,26);
        inmultire(v1,a[i]);
        adunare(v,v1);
    }
    for(i=v[0];i>=1;i--)
    {
        if(v[i]==0)v[0]--;
        else break;
    }
    for(i=v[0];i>=1;i--)
        cout<<v[i];
    return 0;
}
