#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,l;
char s[20],b[20];
bool p[20];
void afisare(int x)
{
    for(int i=0;i<=x;++i)cout<<b[i];
    cout<<'\n';
}
bool verificare(int i,int x)
{
    if(p[i]==1)return false;
    else if(x==0&&strchr("aeiou",s[i])==NULL)return false;
    else if(x>0&&strchr("aeiou",b[x-1])==NULL&&strchr("aeiou",s[i])==NULL)return false;
    return true;
}
void backtracking(int x,int ist)
{
    for(int i=ist;i<l;++i)
    {
        if(verificare(i,x))
        {
            p[i]=1;
            b[x]=s[i];
            if(x<=m-1)
            {
                afisare(x);
                backtracking(x+1,i+1);
            }
            p[i]=0;
        }
    }
}
int main()
{
    cin>>s>>m;
    l=strlen(s);
    sort(s,s+l);
    //cout<<s<<'\n';
    backtracking(0,0);
    return 0;
}
