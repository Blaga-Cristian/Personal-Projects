#include <iostream>
#include <cstring>
using namespace std;
int f[125];
int main()
{
    char s[256];
    int i,max=0;
    cin.get(s,255);
    for(i=0;i<strlen(s);i++)
    {
        f[(int)s[i]]++;
    }
    for(i='a';i<='z';i++)
    {
        if(f[i]>max)max=f[i];
    }
    for(i='a';i<='z';i++)
    {
        if(f[i]==max)
        {
            cout<<(char)i;
            break;
        }
    }
    return 0;
}
