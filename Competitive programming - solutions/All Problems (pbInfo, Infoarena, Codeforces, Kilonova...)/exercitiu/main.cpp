#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a!=0&&b!=0)
    while(b!=0)
    {
        if(a%10==b%10)cout<<a<<" "<<b<<"  ";
        a=b;
        cin>>b;
    }
    else cout<<"nr sunt gresite";
    return 0;
}
