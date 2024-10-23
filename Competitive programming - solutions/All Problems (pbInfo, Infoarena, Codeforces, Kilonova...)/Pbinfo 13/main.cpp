#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255];
    int i,j;
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        for(j=0;j<strlen(s)-i;j++)
        {
            cout<<s[j];
        }
        cout<<endl;
    }
    for(i=0;i<strlen(s);i++)
    {
        for(j=i;j<strlen(s);j++)
        {
            cout<<s[j];
        }
        cout<<endl;
    }
    return 0;
}
