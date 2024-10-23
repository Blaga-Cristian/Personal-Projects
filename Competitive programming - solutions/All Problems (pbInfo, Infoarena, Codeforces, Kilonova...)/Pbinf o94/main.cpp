#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255],t[255]="";
    int i;
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        if(strchr("aeiou",s[i])!=0)
        {
            strcpy(t,s+i+1);
            strcpy(s+i,t);
            i--;
        }
    }
    cout<<s;
    return 0;
}
