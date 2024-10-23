#include <iostream>

using namespace std;
int cifmaxpar(int n)
{
    int m=-1;
    if(n>0)
    {
        m=cifmaxpar(n/10);
        if((n%10)%2==0&&n%10>m)m=n%10;
    }
    return m;
}
int main()
{
    cout<<cifmaxpar(2154);
    return 0;
}
