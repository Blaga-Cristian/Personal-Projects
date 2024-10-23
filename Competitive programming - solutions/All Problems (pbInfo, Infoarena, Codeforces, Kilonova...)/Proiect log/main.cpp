#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double n=1,x;
double ln(double a,double mid,double b)
{
    if(exp(mid)>=x*0.999999999999999&&exp(mid)<=x*1.00000000000001)return mid;
    else if(exp(mid)<x)
    {
        double c=(b+mid)/2;
        return ln(mid,c,b);
    }
    else if(exp(mid)>x)
    {
        double c=(a+mid)/2;
        return ln(a,c,mid);
    }
}
int main()
{
    int i;
    cin>>x;
    if(x==exp(1))cout<<1;
    else if(x<exp(n))
    {
        while(exp(n)>x)n--;
        double mid=(n+n+1)/2;
        //cout<<n<<endl<<mid<<endl<<n+1;
        double m=ln(n,mid,n+1);
        bool ok=0;
        for(i=1;i<=6;i++)
        {
            double k=m*pow(10,i);
            cout<<k<<endl<<(int)k+1<<endl;
            if(k==(int)k+1)
            {
                cout<<fixed<<setprecision(i)<<m;
                ok=1;
                break;
            }
        }
        //if(ok==0)cout<<fixed<<setprecision(6)<<m;
    }
    else
    {
        while(exp(n)<x)n++;
        double mid=(n-1+n)/2;
        //cout<<n-1<<endl<<mid<<endl<<n;
        double m=ln(n-1,mid,n);
        bool ok=0;
        for(i=1;i<=6;i++)
        {
            double k=m*pow(10,i);
            cout<<k<<endl<<(int)k+1<<endl;
            if(k==(int)k+1)
            {
                cout<<fixed<<setprecision(i)<<m;
                ok=1;
                break;
            }
        }
        //if(ok==0)cout<<fixed<<setprecision(6)<<m;
    }
    return 0;
}
