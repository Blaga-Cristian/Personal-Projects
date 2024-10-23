#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,b[21],v[21],l;
char s[20];
bool p[21];
void afisare()
{
    for(int i=0;i<k;++i)cout<<b[i];
    cout<<'\n';
}
void backtracking(int x,int ist)
{
    for(int i=ist;i<l;++i)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=v[i];
            if(x==k-1)afisare();
            else backtracking(x+1,i+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>s>>k;
    l=strlen(s);
    for(int i=0;i<strlen(s);++i)v[i]=s[i]-'0';
    backtracking(0,0);
    return 0;
}
