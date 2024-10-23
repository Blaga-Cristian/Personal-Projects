#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[12],*p;
    int n,nr=0,nr1=0,i;
    cin.get(s,11);
    p=strtok(s,".");
    for(i=0;i<strlen(p);i++)
    {
        nr=nr*10+p[i]-'0';
    }
    p=strtok(NULL,".");
    for(i=0;i<strlen(p);i++)
    {
        nr1=nr1*10+p[i]-'0';
    }
    while(nr1%10==0)nr1=nr1/10;
    cout<<nr+nr1;
    return 0;
}
