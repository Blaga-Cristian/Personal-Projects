#include <iostream>

using namespace std;
void ordonare(int a[],int n)
{
    if(n>0)
    {
    int i,max=-999999,poz;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            poz=i;
        }
    }
    a[poz]=a[n-1];
    a[n-1]=max;
    ordonare(a,n-1);
    }
}
int main()
{
    int n,i,a[101];
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    ordonare(a,n);
    for(i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
