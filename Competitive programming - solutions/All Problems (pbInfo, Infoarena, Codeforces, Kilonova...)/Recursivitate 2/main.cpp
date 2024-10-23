#include <iostream>

using namespace std;
int a[101];
int st=-1;
int k=0;
void F(int n, int a[], int& k)
{
    st++;
    if(a[st]%2==0&&st<n)F(n,a,k);
    else F(n,a,k);
}
int main()
{
    int n,i,k=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    F(n,a,k);
    cout<<k;
    return 0;
}
