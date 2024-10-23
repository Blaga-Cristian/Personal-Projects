#include <iostream>

using namespace std;
typedef int NrMare[2010];
NrMare s;
void inmultire(NrMare s,int a)
{
    int i;
    unsigned long long t=0;
    for(i=1;i<=s[0];i++)
    {
        t=t+s[i]*a;
        s[i]=t%10;
        t=t/10;
    }
    while(t)
    {
        s[++s[0]]=t%10;
        t=t/10;
    }
}
int main()
{
    int n,i;
    cin>>n;
    s[0]=1;
    s[1]=1;
    for(i=1;i<=n;i++)
    {
        inmultire(s,i);
    }
    for(i=s[0];i>=1;i--)cout<<s[i];
    return 0;
}
