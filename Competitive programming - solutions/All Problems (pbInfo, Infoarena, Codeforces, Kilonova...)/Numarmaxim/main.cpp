#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char n[20],b[20];
bool p[20];
unsigned long long maxi=0;
int m,l,del=0,lg;
void afisare()
{
    //cout<<b<<'\n';
    unsigned long long j=atoll(b);
    if(j>maxi)maxi=j;
}
void backtracking(int x,int ist)
{
    for(int i=ist;i<lg;i++)
    {
        b[x]=n[i];
        if(x==l-1)afisare();
        else backtracking(x+1,i+1);
    }
}
int main()
{
    cin>>n;
    cin>>m;
    lg=strlen(n);
    l=strlen(n)-m;
    backtracking(0,0);
    cout<<maxi;
    return 0;
}
