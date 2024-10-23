#include <iostream>

using namespace std;

int main()
{
    int a,k=0;
    while(a!=0)
    {
        cin>>a;
        if(a>=10&&a<=99)k=a;
    }
    if(k==0)cout<<"nu exista";
    else cout<<k;
    return 0;
}
