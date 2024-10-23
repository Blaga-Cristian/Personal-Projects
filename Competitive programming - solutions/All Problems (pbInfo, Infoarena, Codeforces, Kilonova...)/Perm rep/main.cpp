#include <fstream>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstring>
using namespace std;
ifstream cin("permrep.in");
ofstream cout("permrep.out");
int l,ok,m;
char b[11],n[11],str[200]="";
int p[30];
void afisare()
{
    cout<<b<<'\n';
}
void backtracking(int x)
{
    for(int i=0;i<30;i++)
    {
        if(p[i]>0)
        {
            p[i]--;
            b[x]=i+'a';
            if(x==l-1)afisare();
            else backtracking(x+1);
            p[i]++;
        }
    }
}
int main()
{
    cin>>n;
    l=strlen(n);
    sort(n,n+l);
    for(int i=0;i<l;i++)p[n[i]-'a']++;
    backtracking(0);
    return 0;
}
