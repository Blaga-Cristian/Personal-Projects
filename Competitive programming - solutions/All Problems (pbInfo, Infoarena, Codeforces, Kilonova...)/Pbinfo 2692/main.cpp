#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256],v[255][255],*p,sep[]=" ";
    int i=0,j,ok=0;
    cin.get(s,255);
    p=strtok(s,sep);
    while(p)
    {
        strcpy(v[i],p);
        i++;
        p=strtok(NULL,sep);
    }
    while(ok==0)
    {
        ok=1;
        for(j=0;j<i-1;j++)
        {
            if(strlen(v[j])<strlen(v[j+1]))
            {
                char t[256]="";
                strcpy(t,v[j+1]);
                strcpy(v[j+1],v[j]);
                strcpy(v[j],t);
                ok=0;
            }
            else if(strlen(v[j])==strlen(v[j+1])&&strcmp(v[j],v[j+1])>0)
            {
                char t[256]="";
                strcpy(t,v[j+1]);
                strcpy(v[j+1],v[j]);
                strcpy(v[j],t);
                ok=0;
            }
        }
    }
    for(j=0;j<i;j++)cout<<v[j]<<endl;
    return 0;
}
