#include <iostream>

using namespace std;

int main()
{
    int k=1,n,x,a,b,s;
    cin>>n;
    while(n!=0)
    {
        if(n<=9)break;
        a=n%10;
        b=(n%100-n%10)/10;
        if(a!=0)x=a;
        if(n<=99)a=x;
        if(b>a)k=0;
        n=n/10;
    }
    if(k==1)cout<<"da";
    else cout<<"nu";
    return 0;
}
