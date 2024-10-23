#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256],*p;
    int i;
    cin.get(s,255);
    p=strtok(s," ");
    p=strtok(NULL," ");
    for(i=0;i<strlen(p);i++)
    {
        if(strchr("aeiouAEIOU",p[i])==0)cout<<p[i];
    }
    cout<<" "<<s;
    return 0;
}
