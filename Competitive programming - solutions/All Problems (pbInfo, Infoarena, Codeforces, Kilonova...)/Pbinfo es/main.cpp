#include <iostream>
#include <cmath>
using namespace std;
int p,k=1,nr=1;
void gen(int p)
{
    if(k<p)
    {
        int x=nr;
        if(k==1)
        {
            cout<<x<<" ";
            k=k*2;
            nr=nr+2;
            gen(p);
            cout<<x+1<<" ";
        }
        else
        {
                for(int i=1;i<=k/2;i++)
                {
                    cout<<x<<" ";
                    x++;
                }
                nr=x+k/2;
                k=k*2;
                int z=k;
                gen(p);
                for(int i=1;i<=z/4;i++)
                {
                    cout<<x<<" ";
                    x++;
                }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    p=pow(2,n);
    gen(p);
    return 0;
}
