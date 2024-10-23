#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    for(a=1;a<=9;a++)
    for(b=a+1;b<=9;b++)
    for(c=a+2;c<=9;c++)
    if(a+b+c==18)cout<<(100*a+10*b+c)<<" ";
    return 0;
}
