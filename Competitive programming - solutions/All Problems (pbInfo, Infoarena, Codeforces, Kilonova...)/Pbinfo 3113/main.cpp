#include <iostream>
#include <cstring>
using namespace std;
int f[1000];
int main()
{
    char s[10001],*p,sep[]=".,!? ",v[1000][1000];
    int j,i,ok;
    cin.get(s,10000);
    p=strtok(s,sep);
    while(p)
    {
        i=0;
        ok=0;
        while(ok==0)
        {
            if(strcmp(v[i],p)==0)
            {
                f[i]++;
                ok=1;
            }
            else if(v[i][0]==0)
            {
                strcpy(v[i],p);
                f[i]++;
                ok=1;
            }
            i++;
        }
        p=strtok(NULL,sep);
    }
    ok=0;
    while(ok==0)
    {
        ok=1;
        j=0;
        while(v[j+1][0]!=0)
        {
            if(strcmp(v[j],v[j+1])>0)
            {
                char sir[10000];
                strcpy(sir,v[j]);
                strcpy(v[j],v[j+1]);
                strcpy(v[j+1],sir);
                int aux=f[j];
                f[j]=f[j+1];
                f[j+1]=aux;
                ok=0;
            }
            j++;
        }
    }
    j=0;
    while(v[j][0]!=0)
    {
        cout<<v[j]<<" "<<f[j]<<endl;
        j++;
    }
    return 0;
}
