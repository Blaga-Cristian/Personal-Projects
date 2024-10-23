#include <iostream>
#include <cstring>
using namespace std;
char f[60];
int main()
{
    char s[255];
    int i,max=0;
    cin.get(s,60);
    for(i=0;i<strlen(s);i++)
    {
        f[s[i]]++;
    }
    for(i='0';i<='9';i++)
    {
        if(f[i]>max)max=f[i];
    }
    if(max==0)cout<<"NU";
    else
    {
        for(i='0';i<='9';i++)
    {
        if(f[i]==max)
        {
            cout<<(char)i;
            break;
        }
    }
    }
    return 0;
}
