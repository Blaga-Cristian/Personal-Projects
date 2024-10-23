#include <iostream>
#include <algorithm>
using namespace std;
int n,a,b,v[101],cnt;

int main()
{
    cin>>n>>b>>a;
    int nr1=0,nr2=0;
    nr1=n/a;
    while((n-nr1*a)%b!=0)nr1--,nr2=(n-nr1*a)/b;
    for(int i=0;i<nr2;++i)cout<<b<<' ';
    for(int i=0;i<nr1;++i)cout<<a<<' ';
    return 0;
}
