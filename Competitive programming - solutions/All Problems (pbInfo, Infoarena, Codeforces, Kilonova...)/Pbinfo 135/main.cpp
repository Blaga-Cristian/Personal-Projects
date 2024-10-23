#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255],*p;
    int i;
    cin.get(s,255);
    p=strtok(s," ");
    p=strtok(NULL," ");
    for(i=0;i<strlen(p);i++)
    {
        if(strchr("aeiou",s[i])==0&&strchr("aeiou",p[i])==0)cout<<"#";
        else if(strchr("aeiou",s[i])!=0&&strchr("aeiou",p[i])!=0)cout<<"*";
        else cout<<"?";
    }
    return 0;
}
