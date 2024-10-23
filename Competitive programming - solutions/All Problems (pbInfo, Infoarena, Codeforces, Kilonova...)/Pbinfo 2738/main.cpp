#include <iostream>
#include <cstring>
using namespace std;
int f[256];
int main()
{
    char s[256],*p,cuvant[256]="";
    int i,j,concluzie,ok,max=0;
    cin.get(s,255);
    p=strtok(s," ");
    while(p!=0)
    {
        ok=1;
        for(i=0;i<strlen(p);i++)
        {
            if(strcmp(strrchr(p,p[i]),p+i)!=0)
            {
                ok=0;
                break;
            }
        }
        if(ok==1&&strlen(p)>max)
        {
            max=strlen(p);
            strcpy(cuvant,p);
        }
        p=strtok(NULL," ");
    }
    if(strlen(cuvant)==0)cout<<-1;
    else cout<<cuvant;
    return 0;
}
