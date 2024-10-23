#include <iostream>

using namespace std;

int main()
{
    int a,k,P=1;
    cin>>a>>k;
    if(k>=0&&k<=9)
        while(a!=0)
    {
        c=a%10;
        if(c!=k)P=P*c;
        a=a/10;
    }
    cout<<P;
    else cout<<" nr gresit";
    return 0;
}
