#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[101],t[101]="";
    int i,k=0;
    cin.get(s,100);
    for(i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        {
            for(int j=1;j<=s[i]-'0';j++)
            {
                t[k]=s[i-1];
                k++;
            }
        }
    }
    cout<<t;
    return 0;
}
