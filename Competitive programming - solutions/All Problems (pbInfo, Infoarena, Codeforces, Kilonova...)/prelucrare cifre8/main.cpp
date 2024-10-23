#include <iostream>

using namespace std;

int main()
{
    int s=0,i,j,c;
    for(i=10;i<=99;i++)
    {
        j=i*i*i;
        while(j!=0)
        {
            c=j%10;
            if(c!=6&&c!=7&&c!=8)s=1;
            j=j/10;
        }
        if(s==0)cout<<i;
        s=0;
    }
    return 0;
}
