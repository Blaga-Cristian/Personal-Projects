#include <iostream>

using namespace std;
int a_prim(int n)
{
    int i,j,ok;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            ok=1;
            for(j=2;j<=i/2;j++)
            {
                if(i%j==0)ok=0;
            }
            if(ok==1)n=n/i;
            break;
        }
    }
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            ok=1;
            for(j=2;j<=i/2;j++)
            {
                if(i%j==0)ok=0;
            }
            if(ok==1&&n/i==1)
            {
                return 1;
                break;
            }
            else
            {
                return 0;
                break;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<a_prim(n);
    return 0;
}
