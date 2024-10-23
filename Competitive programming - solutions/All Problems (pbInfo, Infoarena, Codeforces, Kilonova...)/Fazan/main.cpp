#include <iostream>
#include <cstring>
using namespace std;
char s[31][21],ans[31][21],mem[31][21];
int n;
int scris,len;
bool p[40];
void afisare(int len)
{
    if(len>scris)
    {
        for(int i=0;i<len;++i)strcpy(mem[i],ans[i]);
        scris=len;
    }
}
bool verificare(int i,int x)
{
    if(p[i]==1)return false;
    if(x>0)
    {
        int l=strlen(ans[x-1]);
    if(ans[x-1][l-1]!=s[i][1])return false;
    if(ans[x-1][l-2]!=s[i][0])return false;
    }
    return true;
}
void backt(int x)
{
    int ok=0;
    for(int i=0;i<n;++i)
    {
        if(verificare(i,x))
        {
            ok=1;
            p[i]=1;
            strcpy(ans[x],s[i]);
            backt(x+1);
            p[i]=0;
        }
    }
    if(ok==0)afisare(x);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>s[i];
    int ok=0;
    while(ok==0)
    {
        ok=1;
        for(int i=0;i<n-1;++i)
        {
            if(strcmp(s[i],s[i+1])>0)
            {
                ok=0;
                char t[30]="";
                strcpy(t,s[i]);
                strcpy(s[i],s[i+1]);
                strcpy(s[i+1],t);
            }
        }
    }
    backt(0);
    for(int i=0;i<scris;++i)cout<<mem[i]<<' ';
    return 0;
}
