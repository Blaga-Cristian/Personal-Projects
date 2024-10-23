#include <iostream>

using namespace std;
int prime (int n)
{
    int d=2,p,min=99,divizor=999;
    while(n>1)
    {
        p=0;
        while(n%d==0)
        {
           p++;
           n=n/d;
        }

        if( p != 0 && p < min)
        {
            min=p;
            divizor=d;
        }

        d++;
    }
    return divizor;
}
int main()
{
    int n;
    cin>>n;
    cout <<prime(n)<< endl;
    return 0;
}
