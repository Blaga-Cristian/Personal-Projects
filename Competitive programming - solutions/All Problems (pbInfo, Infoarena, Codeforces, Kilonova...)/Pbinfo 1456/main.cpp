#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255];
    int i,ok=1,nr=0;
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        if(strchr("aeou",s[i])!=0)ok=0;
        if(s[i]=='i')nr++;
    }
    if(ok==1&&nr!=strlen(s))cout<<"DA";
    else cout<<"NU";
    return 0;
}
