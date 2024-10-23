#include <iostream>

using namespace std;

int main()
{
    int n,c,s=0,k=0,p,a=0,q,b=0;
    cin>>n;
    while(n!=0)
    {
        c=n%10;
        if(c%2==0)s=s*10+c;
        else k=k*10+c;
        n=n/10;
    }
    while(s!=0)
    {
        p=s%10;
        a=a*10+p;
        s=s/10;
    }
    while(k!=0)
    {
        q=k%10;
        b=b*10+q;
        k=k/10;
    }
    if((a-b)<0)cout<<(a-b)*(-1);
    else cout<<(a-b);
    return 0;
}
