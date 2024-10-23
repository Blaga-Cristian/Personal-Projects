#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int i,nr=0;
    char s[256];
    cin.get(s,255);
    for(i=1;i<strlen(s)-1;i++)
    {
        if(strchr("aeiou",s[i])!=0&&strchr("aeiou",s[i-1])==0&&strchr("aeiou",s[i+1])==0&&s[i]>='a'&&s[i]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]>='a'&&s[i-1]<='z')nr++;
    }
    cout<<nr;
    return 0;
}
