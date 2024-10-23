#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256];
    int i,j;
    cin.get(s,255);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]==s[i+1]||s[i]+32==s[i+1]||s[i]-32==s[i+1])
        {
            j=i;
            while(s[i]==s[j]||s[i]-32==s[j]||s[i]+32==s[j])
                j++;
            strcpy(s+i,s+j);
            i=-1;
        }
    }
    cout<<s;
    return 0;
}
