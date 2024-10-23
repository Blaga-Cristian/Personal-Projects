#include <iostream>

using namespace std;
void num(int n,int v[])
{
    if(n>0)
    {
        num(n-1,v);
        if(v[n-1]>v[n])
        {

        }
    }
}
int main()
{
    int n,i,v[101];
    cin>>n;
    for(i=0;i<n;i++)cin>>v[i];
    num(n,v);
    for(i=0;i<n;i++)cout<<v[i]<<" ";
    return 0;
}
