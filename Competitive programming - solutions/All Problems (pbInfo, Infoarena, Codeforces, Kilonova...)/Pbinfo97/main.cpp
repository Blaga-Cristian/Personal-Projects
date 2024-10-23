#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int i,j,nr=0;
    char s[20],n[20];
    cin>>s>>n;
    for(i=0;i<strlen(s);i++)
    {
        for(j=0;j<strlen(n);j++)
        {
            if(s[i]==n[j])
            {
                nr++;
                strcpy(n+j,n+j+1);
                j=strlen(n);
            }
        }
    }
    if(nr==strlen(s))cout<<1;
    else cout<<0;
    return 0;
}
