#include <iostream>

using namespace std;

int main()
{
    int a,b,i,j,c,s=0;
    cin>>a>>b;
    for(i=a;i<=b;i++)
    {
        s=0;
        j=i;
        while(j!=0)
        {
            c=j%10;
            s=s*10+c;
            j=j/10;
        }
        if(s>=a&&s<=b)cout<<"("<<i<<","<<s<<")"<<endl;
    }
    return 0;
}
