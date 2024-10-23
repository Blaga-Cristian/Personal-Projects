#include <iostream>

using namespace std;
int NrDiv(int n)
{
    int m=n,pow=0,i=3,s=1;
    while(m%2==0)
    {
        m=m/2;
        pow++;
    }
    if(pow>0)s=s*pow;
    pow=0;
    while(m!=1)
    {
        while(m%i==0)
        {
            m=m/i;
            pow++;
        }
        s=s*(pow+1);
        pow=0;
        i=i+2;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    cout<<NrDiv(n);
    return 0;
}
