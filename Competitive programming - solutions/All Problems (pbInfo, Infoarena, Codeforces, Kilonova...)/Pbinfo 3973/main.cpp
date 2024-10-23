#include <iostream>
#include <cmath>
using namespace std;
double x,p=1;
double ln(double &h)
{
        cout<<p<<endl;
        int i;
        for(i=0;i<=9;i++)
        {
            if(pow(2.71828182846,h+i*p)>x)
            {
                h=h+(i-1)*p;
                p=p/10;
                break;
            }
        }
}
int main()
{
    double h=0;
    cin>>x;
    for(int i=1;i<=6;i++)
    {

    }
    return 0;
}
