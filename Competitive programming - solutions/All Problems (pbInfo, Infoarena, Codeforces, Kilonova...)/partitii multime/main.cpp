#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int vmax[16],n,m;
vector<unsigned int> v;
void baza2scriere(int x)
{
    int i=1;
    printf("{");
    for(int i=1;x;++i,x/=2)
    {
        if(x%2==1)
        {
            if(x==1)printf("%d",i);
            else printf("%d,",i);
        }
    }
    printf("}");
}
int baza2(int x)
{
    if(x>0)
    {
        int k=baza2(x/2);
        return k+x%2;
    }
}
void afisare()
{
    int ok=1;
    for(int i=1;i<=n/m;++i)if(baza2(v[i])!=m)ok=0;
    if(ok==1)
    {
        for(int i=1;i<=n/m;++i)
        {
            baza2scriere(v[i]);
            if(i!=n/m)printf("U");
        }
        printf("\n");
    }
}
void backtrack(int x)
{
    if(x==n+1)afisare();
    else
    {
        for(int i=1;i<=vmax[x]+1;++i)
        {
            int y=1<<(x-1);
            vmax[x+1]=max(i,vmax[x]);
            v[i]+=y;
            backtrack(x+1);
            v[i]-=y;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n/m;++i)v.push_back(0);
    if(n%m!=0)printf("IMPOSIBIL");
    else
        backtrack(1);
    return 0;
}
