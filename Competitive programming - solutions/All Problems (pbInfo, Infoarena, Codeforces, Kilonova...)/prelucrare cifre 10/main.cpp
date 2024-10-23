#include <iostream>

using namespace std;

int main()
{
    int n,x,a,b,c,d,e,f,g,h,i,j;
    cin>>n;
    if(n<1000000000)while(n!=0)
    {
        x=n%10;
        if(c==0)a=a+1;
        else if(c==1)b=b+1;
        else if(c==2)c=c+1;
        else if(c==3)d=d+1;
        else if(c==4)e=e+1;
        else if(c==5)f=f+1;
        else if(c==6)g=g+1;
        else if(c==7)h=h+1;
        else if(c==8)i=i+1;
        else if(c==9)j=j+1;
        n=n/10;
    }
    cout<<a<<"cifre de 0"<<endl<<b<<"cifre de 1"<<endl<<c<<"cifre de 2"<<endl<<d<<"cifre de 3"<<endl<<e<<"cifre de 4"<<endl<<f<<"cifre de 5"<<endl<<g<<"cifre de 6"<<endl<<h<<"cifre de 7"<<endl<<i<<"cifre de 8"<<endl<<j<<"cifre de 9";
    return 0;
}
