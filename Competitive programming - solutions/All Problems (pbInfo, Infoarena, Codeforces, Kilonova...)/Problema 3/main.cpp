#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[101][31];
    int n,ok,i,j,cnt=0;
    cin>>n;
    cin.get();
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
        ok=1;
        for(j=0;j<strlen(s[i]);j++)
        {
            if(strchr("aeiou",s[i][j])==NULL)ok=0;
        }
        cnt=cnt+ok;
    }
    cout<<cnt;
    return 0;
}
