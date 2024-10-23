#include <iostream>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;
int n,b[15],v[15],ok;
bool p[15],prim[10005];
void ciur()
{
    prim[0]=prim[1]=1;
    for(int i=2;i*i<=10000;i++)
    {
        if(prim[i]==0)
        {
            for(int j=2;j<=10000/i;j++)prim[j*i]=1;
        }
    }
}
void afisare()
{
    for(int i=0;i<n;i++)cout<<b[i]<<" ";
    cout<<'\n';
}
bool verificare(int i,int val,int x)
{
    if(p[i]==1)return 0;
    if(x>0)if(prim[v[i]]==0&&prim[val]==0)return 0;
    return 1;
}
void backtracking(int x)
{
    for(int i=0;i<n;i++)
    {
        if(verificare(i,b[x-1],x))
        {
            p[i]=1;
            b[x]=v[i];
            if(x==n-1)afisare();
            else backtracking(x+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    ciur();
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v,v+n);
    backtracking(0);
    return 0;
}
