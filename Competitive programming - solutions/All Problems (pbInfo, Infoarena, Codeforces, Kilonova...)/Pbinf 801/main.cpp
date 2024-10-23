#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256],t[256]="",*p;
    cin.get(s,255);
    p=strtok(s," ");
    while(p!=0)
    {
        strcat(t," ");
        strcat(t,p);
        p=strtok(NULL," ");
    }
    cout<<t+1;
    return 0;
}
