#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x,s,n=2,a;
    while(x!=1)
    {
        s=0;
        a=pow(n,n);
        while(a!=0)
        {
            a=a/10;
            s=s+1;
        }
        if(s==n)
        {
            cout<<n<<" ";
            x=1;
        }
        n=n+1;
    }
    return 0;
}
