#include <iostream>
#include <cstring>
using namespace std;
int v[10];
int main()
{
    char s[53],*p;
    int n,nr=0,nr1=0,i,max=0,x=0;
    cin.get(s,52);
    for(i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))v[s[i]-'0']++;
    }
    for(i=0;i<10;i++)
    {
        if(v[i]>max)
        {
            max=v[i];
            x=i;
        }
    }
    cout<<x;
    return 0;
}
