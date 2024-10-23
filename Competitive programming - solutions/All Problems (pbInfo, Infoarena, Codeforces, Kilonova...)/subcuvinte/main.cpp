#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,l;
char s[20],b[20];
bool p[20];
void afisare()
{
    for(int i=0;i<l-n;++i)cout<<b[i];
    cout<<'\n';
}
void backtracking(int x,int ist)
{
    for(int i=ist;i<l;++i)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=s[i];
            if(x==l-n-1)afisare();
            else backtracking(x+1,i+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>s>>n;
    l=strlen(s);
    //sort(s,s+l);
    //cout<<s<<'\n';
    backtracking(0,0);
    return 0;
}
