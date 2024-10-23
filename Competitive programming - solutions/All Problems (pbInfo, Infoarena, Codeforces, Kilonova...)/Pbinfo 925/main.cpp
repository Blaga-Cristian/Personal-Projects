#include <iostream>

using namespace std;
void P(int x[],int n,int& mini,int& maxi,int& sum)
{
    if(n>0)
    {
        mini=99999999,maxi=-99999999,sum=0;
        P(x,n-1,mini,maxi,sum);
        sum=sum+x[n-1];
        if(x[n-1]<mini)mini=x[n-1];
        if(x[n-1]>maxi)maxi=x[n-1];
    }
}
int main()
{
    int x[101],n,mini,maxi,sum,i;
    cin>>n;
    for(i=0;i<n;i++)cin>>x[i];
    P(x,n,mini,maxi,sum);
    cout<<mini<<endl<<maxi<<endl<<sum;
    return 0;
}
