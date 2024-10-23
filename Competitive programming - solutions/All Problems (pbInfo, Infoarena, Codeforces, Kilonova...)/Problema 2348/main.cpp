#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256];
    int i,sum=0,nr=0;
    cin.get(s,200);
    for(i=0;i<strlen(s);i++)
    {
        if((s[i]<'A'||s[i]>'Z')&&s[i]!=' '&&strchr("aeiou",s[i])==0)
        {
            sum=sum+s[i];
            nr++;
        }
    }
    char a=sum/nr;
    cout<<a;
    return 0;
}
