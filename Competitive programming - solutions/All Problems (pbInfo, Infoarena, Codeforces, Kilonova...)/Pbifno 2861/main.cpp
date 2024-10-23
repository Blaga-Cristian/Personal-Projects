#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255],*p,t[255]="";
    int ok,i,max=-999;
    cin.get(s,255);
    p=strtok(s," ");
    while(p!=0)
    {
        ok=0;
        for(i=0;i<strlen(p);i++)
        {
            if((p[i]>='a'&&p[i]<='z')||(p[i]>='A'&&p[i]<='Z'))ok=1;
        }
        if(ok==1)
        {
            if(strlen(p)>max)max=strlen(p);
        }
        strcat(t,p);
        strcat(t," ");
        p=strtok(NULL," ");
    }
    p=strtok(t," ");
    strcpy(s,"");
    while(p!=0)
    {
        ok=0;
        for(i=0;i<strlen(p);i++)
        {
            if((p[i]>='a'&&p[i]<='z')||(p[i]>='A'&&p[i]<='Z'))ok=1;
        }
        if(ok==1&&strlen(p)==max)
        {
            for(i=0;i<strlen(p)/2;i++)
            {
                char aux=p[i];
                p[i]=p[strlen(p)-i-1];
                p[strlen(p)-i-1]=aux;
            }
        }
        strcat(s,p);
        strcat(s," ");
        p=strtok(NULL," ");
    }
    cout<<s;
    return 0;
}
