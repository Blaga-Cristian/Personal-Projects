#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
long long nr=0,p=1;
char n[255];
int convert(char n)
{
    if(n>='A')return (n-'A'+10);
    else return n-'0';
}
long long b16(int x)
{
    if(x>=0)
    {
        nr=nr+convert(n[x])*p;
        p=p*16;
        b16(x-1);
    }
    return nr;
}
int main()
{
    int len;
    cin>>n;
    len=strlen(n);
    cout<<b16(len-1);
    return 0;
}
