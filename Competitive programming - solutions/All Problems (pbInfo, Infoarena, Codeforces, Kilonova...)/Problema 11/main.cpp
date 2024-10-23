#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255],*p,i,j,c[255],t[255]="",c1[255]="";
    cin.get(s,255);
    cin.get();
    cin>>c;
    strcpy(t,s);
    strcpy(c1,c);
    for(i=0;i<strlen(c1);i++)c1[i]='*';
    while(strstr(t,c)!=NULL)
    {
        strncpy(strstr(t,c),c1,strlen(c1));
    }
    cout<<t;
    return 0;
}
