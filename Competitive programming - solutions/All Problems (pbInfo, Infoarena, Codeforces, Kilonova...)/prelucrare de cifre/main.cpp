#include <iostream>

using namespace std;

int main()
{
    int n,s=0,x,y,a,b,c,d,e,f,g,h,i,j;
    cin>>n;
    while(n!=0)
    {
        x=n%10;
        s=s*10+x;
        n=n/10;
    }
    while(s!=0)
    {
        y=s%10;
        if(y==0)cout<<"a";
        else if(y==1)cout<<"b";
        else if(y==2)cout<<"c";
        else if(y==3)cout<<"d";
        else if(y==4)cout<<"e";
        else if(y==5)cout<<"f";
        else if(y==6)cout<<"g";
        else if(y==7)cout<<"h";
        else if(y==8)cout<<"i";
        else if(y==9)cout<<"j";
        s=s/10;
    }
    return 0;
}
