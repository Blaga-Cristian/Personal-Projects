#include <iostream>

using namespace std;
double cautare(int n,double x[],double v)
{
    if(n>0)
    {
        if(x[n-1]==v)
        {
            return n-1;
        }
        else return cautare(x,n-1,v);
    }
    return -1;
}
int main()
{
    int n,i;
    double x[101],v;
    cin>>n;
    for(i=0;i<n;i++)cin>>x[i];
    cin>>v;
    cout<<cautare(n,x,v);
    return 0;
}
