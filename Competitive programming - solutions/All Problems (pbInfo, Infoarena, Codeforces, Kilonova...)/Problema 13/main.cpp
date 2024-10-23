#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255],*p,c[255],t[255]="",c1[255]="";
    int n,i,j,cnt=0,max=-99,ind=-3,min=999;
    cin.get(s,255);
    n=strlen(s)/2;
    for(i=0;i<=n;i++)
    {
        s[strlen(s)-1]=0;
        cout<<s+i+1<<endl;
    }
    return 0;
}
