#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[11];
    int i,j,ok=1;
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        if(strchr("aeiouAEIOU",s[i])!=0)
        {
            for(j=strlen(s)-1;j>=0;j--)
            {
                if(strchr("aeiouAEIOU",s[j])==0)
                {
                    int aux=s[i];
                    s[i]=s[j];
                    s[j]=aux;
                    ok=0;
                    break;
                }
            }
            if(ok==0)break;
        }
    }
    if(ok==1)cout<<"IMPOSIBIL";
    else cout<<s;
    return 0;
}
