#include <iostream>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstring>
using namespace std;
int n,ok,m;
char b[30],v[30];
bool p[30];
void afisare()
{
    cout<<b<<'\n';
}
void backtracking(int x)
{
    for(int i=0;i<n;i++)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=v[i];
            if(x==m-1)afisare();
            else backtracking(x+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)v[i]='A'+i;
    backtracking(0);
    return 0;
}
