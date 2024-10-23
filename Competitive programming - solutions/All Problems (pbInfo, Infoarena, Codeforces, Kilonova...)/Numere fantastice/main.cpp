#include <iostream>

using namespace std;
bool v[1000001];
int main()
{
    v[0]=1;
    v[1]=1;
    for(int i=2;i<=1000;i++)
    {
        if(v[i]==0)
        {
            for(int j=2;j<=1000000/i;j++)v[i*j]=1;
        }
    }
    int s=1,p=0,cnt=0,x,n,i,j,d=2;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        for(j=1;j*j<=x;j++)
        {
            if(x%j==0)
            {
                s++;
                if(j!=n/j)s++;
            }
        }
        if(v[s]==0)cnt++;
        s=0;
    }
    cout<<cnt;
    return 0;
}
