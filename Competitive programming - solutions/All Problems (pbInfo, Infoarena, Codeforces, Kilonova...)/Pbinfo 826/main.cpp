#include <iostream>

using namespace std;
int cifminpar(int n)
{
    int m=-1;
    if(n>0)
    {
        m=cifminpar(n/10);
        if((n%10)%2==0&&m==-1)m=n%10;
        else if((n%10)%2==0&&n%10<m)m=n%10;
    }
    return m;
}
int main()
{
    cout<<cifminpar(11246);
    return 0;
}
