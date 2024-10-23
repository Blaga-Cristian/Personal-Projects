#include <iostream>

using namespace std;

int main()
{
    int a,b;
    b=7;
    while(b<11)
    {
        a=(25340*b+7919)%11;
        b=a;
        cout<<b<<endl;
    }
    return 0;
}
