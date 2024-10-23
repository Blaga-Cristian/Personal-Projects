#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int i,nr=0,suma=0;
    char s[256];
    cin.get(s,256);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            while(s[i]>=48&&s[i]<=57)
            {
                nr=nr*10+s[i]-48;
                i++;
            }
            suma=suma+nr;
            nr=0;
        }
    }
    cout<<suma;
    return 0;
}
