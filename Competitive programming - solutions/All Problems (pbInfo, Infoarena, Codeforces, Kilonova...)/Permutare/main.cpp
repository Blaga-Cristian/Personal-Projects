#include <iostream>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;
int n,b[40],v[40],ok;
bool p[40];
void afisare()
{
    for(int i=1;i<=n;i++)cout<<v[i]<<" ";
}
bool verificare(int i,int val,int x)
{
    if(p[i]==1)return 0;
    if(x>1&&x<n)
    {
        if((int)sqrt(val+i)!=sqrt(val+i))return 0;
    }
    else if(x==n)if((int)sqrt(i+v[1])!=sqrt(i+v[1])||(int)sqrt(val+i)!=sqrt(val+i))return 0;
    return 1;
}
void backtracking(int x)
{
    for(int i=1;i<=n&&ok==0;i++)
    {
        if(verificare(i,v[x-1],x))
        {
            p[i]=1;
            v[x]=i;
            if(x==n)
            {
                afisare();
                ok=1;
            }
            else if(ok==0)backtracking(x+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    backtracking(1);
    if(ok==0)cout<<"nu exista";
    return 0;
}
