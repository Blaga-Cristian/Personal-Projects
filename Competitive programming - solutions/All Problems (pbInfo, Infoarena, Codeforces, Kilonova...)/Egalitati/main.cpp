#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("egalitati.in");
ofstream cout("egalitati.out");
char a[26][255];
int n;
void sortare(char s[26][255])
{
    int ok=0,i;
    while(ok==0)
    {
        ok=1;
        for(i=0;i<n-1;i++)
        {
            char a=s[i][0],b=s[i+1][0];
            if(a>b)
            {
                char t[255]="";
                strcpy(t,s[i+1]);
                strcpy(s[i+1],s[i]);
                strcpy(s[i],t);
                ok=0;
            }
        }
    }
}
void punenrinstring(char s[],int z)
{
    int i=0;
    while(z!=0)
    {
        s[i]=z%10+'0';
        i++;
        z=z/10;
    }
    s[i]=0;
    reverse(s,s+strlen(s));
}
void convertire(int i)
{
    if(strchr(a[i],'*')!=NULL&&isdigit((strchr(a[i],'*')-1)[0])&&isdigit((strchr(a[i],'*')+1)[0]))
    {
        int x=atoi(a[i]+2),y=atoi(strchr(a[i],'*')+1);
        long long z=x*y;
        char k[255]="";
        punenrinstring(k,z);
        strcpy(a[i]+2,k);
    }
    else if(strchr(a[i],'+')!=NULL&&isdigit((strchr(a[i],'+')-1)[0])&&isdigit((strchr(a[i],'+')+1)[0]))
    {
        int x=atoi(a[i]+2),y=atoi(strchr(a[i],'+')+1);
        long long z=x+y;
        char k[255]="";
        punenrinstring(k,z);
        strcpy(a[i]+2,k);
    }
}
bool verificare(int i)
{
    if(isdigit(a[i][2])&&strchr(a[i],'*')==NULL&&strchr(a[i],'+')==NULL)return 1;
    return 0;
}
int main()
{
    int i,j;
    bool ok;
    char t[255]="";
    cin>>n;
    cin.get();
    for(i=0;i<n;i++)
    {
        cin.get(a[i],255);
        while(strchr(a[i],' '))
        {
            strcpy(t,strchr(a[i],' ')+1);
            strcpy(strchr(a[i],' '),t);
        }
        cin.get();
    }
    sortare(a);
    for(i=0;i<n;i++)
    {
        convertire(i);
        if(verificare(i))
        {
            ok=0;
            for(j=0;j<n;j++)
            {
                if(j!=i)
                {
                    if(strchr(a[j],a[i][0])!=NULL)
                    {
                        ok=1;
                        strcpy(t,strchr(a[j],a[i][0])+1);
                        strcpy(strchr(a[j],a[i][0])+strlen(a[i])-2,t);
                        strncpy(strchr(a[j],a[i][0]),a[i]+2,strlen(a[i])-2);
                    }
                }
            }
            if(ok==1)i=-1;
        }
    }
    for(i=0;i<n;i++)cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i]+2<<endl;
    return 0;
}
