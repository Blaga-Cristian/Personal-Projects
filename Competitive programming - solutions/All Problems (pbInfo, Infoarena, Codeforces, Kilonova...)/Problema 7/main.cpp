#include <iostream>
#include <cstring>
using namespace std;
int v[60];
int main()
{
    char s[53],*p,x;
    int n,nr=0,nr1=0,i,max=0;
    cin.get(s,52);
    for(i=0;i<strlen(s);i++)
    {
        if(islower(s[i]))v[s[i]-'a']++;
    }
    for(i=0;i<='z'-'a';i++)
    {
        if(v[i]>max)
        {
            max=v[i];
            x=i+'a';
        }
    }
    cout<<x;
    return 0;
}
