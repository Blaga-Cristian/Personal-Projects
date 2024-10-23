#include <iostream>

using namespace std;
int s[10000];
unsigned long long p;
void inmultire(int a)
{
    int i,t=0;
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
void sumcif()
{
    for(int i=1;i<=s[0];i++)
    {
        p+=s[i];
    }
}
int main()
{
    int n,i;
    cin>>n;
    s[0]=1;
    s[1]=1;
    for(i=9;i<n;i+=10)inmultire(1024);
    n=n%10;
    while(n)
    {
        inmultire(2);
        n--;
    }
    sumcif();
    cout<<p;
    return 0;
}
