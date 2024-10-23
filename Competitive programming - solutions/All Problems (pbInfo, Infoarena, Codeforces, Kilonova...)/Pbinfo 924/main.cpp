#include <iostream>

using namespace std;
int multiplu(int a[],int n,int k)
{
    int cnt=0;
    if(n>=0)
    {
      cnt=multiplu(a,n-1,k);
      if(a[n]%k==0&&a[n]%10==k)cnt++;
    }
    return cnt;
}
int main()
{
    int a[101],n,i,k;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    cin>>k;
    cout<<multiplu(a,n,k);
    return 0;
}
