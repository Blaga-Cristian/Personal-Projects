#include <iostream>

using namespace std;
typedef int NrMare[1010];
NrMare s;
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
int mic(int n)
{
    int prod = 1 , d = 2;
    while(n > 1)
    {
        int p = 0;
        while(n%d==0) p++ , n/=d;
        if(p > 0) prod*=d;
        d++;
        if(d * d > n) d = n;
    }
    return prod;
}
int main()
{
    int n,i,x,j;
    s[0]=1;
    s[1]=1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        inmultire(mic(x));
    }
    for(i=s[0];i>=1;i--)cout<<s[i];
    return 0;
}
