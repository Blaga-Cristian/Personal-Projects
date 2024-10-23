#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    for(a=1;a<=9;a++)
    for(b=0;b<=9;b++)
    for(c=0;c<=9;c++)
    for(d=0;d<=9;d++)
    for(e=0;e<=9;e++)
    if(b==4*a&&e==b&&c==d*e)cout<<(10000*a+1000*b+100*c+10*d+e)<<" ";
    return 0;
}
