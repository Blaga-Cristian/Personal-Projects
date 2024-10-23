#include <iostream>

using namespace std;

int main()
{
    int i,a,b,s=0,k=0,d,c;
    for(i=10;i<=99;i++)
    {
        a=i*i;
        b=i;
        s=0;
        while(a!=0)
        {
            c=a%10;
            s=s*10+c;
            a=a/10;
        }
        k=0;
        while(b!=0)
        {
            d=b%10;
            k=k*10+d;
            b=b/10;
        }
        if(s==(k*k))cout<<i<<" ";
    }
    return 0;
}
