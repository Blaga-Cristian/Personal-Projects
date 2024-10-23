#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a;
    while(a!=0)
    {
        c=a%10;
        if(a<=99&&a>=10)b=c;
        a=a/10;
    }
    cout<<c<<" "<<b;
    return 0;
}
