#include <iostream>

using namespace std;
void ordonare(int a[],int n,int st,int dr)
{
    if(dr>st)
    {
    int i,max=-999999,poz;
    for(i=st;i<=dr;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            poz=i;
        }
    }
    a[poz]=a[dr];
    a[dr]=max;
    ordonare(a,n,st,dr-1);
    }
}
int main()
{
    int n,i,a[101],st,dr;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    cin>>st>>dr;
    ordonare(a,n,st,dr);
    for(i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
