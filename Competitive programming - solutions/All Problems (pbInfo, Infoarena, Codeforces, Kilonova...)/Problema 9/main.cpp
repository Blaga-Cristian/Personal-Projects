#include <iostream>
#include <cstring>
using namespace std;
int v[60];
int main()
{
    char s[255],*p,x,t[255];
    int n,nr=0,nr1=0,i,max=0,cnt=0;
    cin.get(s,200);
    for(i=0;i<strlen(s);i++)
    {
        if(isalpha(s[i])&&(s[i-1]==' '||i==0)&&strchr("AEIOUaeiou",s[i])!=NULL)cnt++;
    }
    cout<<cnt;
    return 0;
}
