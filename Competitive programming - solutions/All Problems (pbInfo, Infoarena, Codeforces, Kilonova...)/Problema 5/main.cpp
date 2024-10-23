#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[53],*p;
    int n,nr=0,nr1=0,i;
    cin.get(s,52);
    for(i=0;i<strlen(s);i++)
    {
        if(!isalpha(s[i]))
        {
            strcpy(s+i,s+i+1);
            i--;
        }
    }
    cout<<s;
    return 0;
}
