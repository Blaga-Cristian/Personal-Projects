#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int i,ok=1;
    char s[101],t[101];
    cin.get(s,101);
    for(i=0;i<strlen(s);i++)
    {
        if(strchr("aeiou",s[i])!=0)
        {
            strcpy(t,s+i);
            strcpy(s+i+1,t);
            s[i+1]='*';
            i++;
            ok=0;
        }
    }
    if(ok==0)cout<<s;
    else cout<<"FARA VOCALE";
    return 0;
}
