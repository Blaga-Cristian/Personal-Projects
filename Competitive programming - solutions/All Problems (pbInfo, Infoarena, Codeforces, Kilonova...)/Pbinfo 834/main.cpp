#include <iostream>

using namespace std;
int elimcif(int n,int c)
{
    int s=0;
    if(n>0)
    {
        s=elimcif(n/10,c);
        if(n%10!=c)s=s*10+n%10;
    }
    return s;
}
int main()
{
    cout<<elimcif(2454 , 4);
    return 0;
}
