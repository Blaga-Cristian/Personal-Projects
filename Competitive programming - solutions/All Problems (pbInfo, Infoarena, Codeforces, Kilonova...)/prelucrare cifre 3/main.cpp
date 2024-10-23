#include <iostream>

using namespace std;

int main()
{
    int p,i,j,s=0,x,c,k=1;
    cin>>p;
    for(i=100;i<=999;i++)
    {
        s=0;
        k=0;
        x=i;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)s=s+1;
        }
        if(s==2)while(x!=0)
        {
            c=x%10;
            k=k*c;
            x=x/10;
        }
        if(k==p)cout<<i<<endl;
    }
    return 0;
}
