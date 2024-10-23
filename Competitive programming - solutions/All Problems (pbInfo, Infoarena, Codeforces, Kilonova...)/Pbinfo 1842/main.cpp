#include <iostream>

using namespace std;

void F(int n,int a[],int& k)
{
    if(n>0)
    {
        k=-1;
        F(n-1,a,k);
        if(a[n-1]%2==0&&k==-1)
        {
            k=0;
            k=k*10+a[n-1];
        }
        else if(a[n-1]%2==0)k=k*10+a[n-1];
    }
}
int main()
{
    int n,a[101],i,k;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    F(n,a,k);
    cout<<k;
    return 0;
}
