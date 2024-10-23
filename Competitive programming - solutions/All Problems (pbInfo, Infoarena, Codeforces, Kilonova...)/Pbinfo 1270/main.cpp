#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256];
    int i,k=1,nr=0;
    cin>>s;
    for(i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]>='A')s[i]=s[i]-55;
        else s[i]=s[i]-48;
        nr=nr+s[i]*k;
        k=k*16;
    }
    cout<<nr;
    return 0;
}
