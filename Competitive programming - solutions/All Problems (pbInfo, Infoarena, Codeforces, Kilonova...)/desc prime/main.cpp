#include <iostream>

using namespace std;
int n,b[208],prime[208],ind,cnt,v[208],maxi;
bool mat[208],ok=0;
void ciur()
{
    mat[0]=1;
    mat[1]=1;
    for(int i=2;i<=200;++i)
    {
        if(mat[i]==0)
        {
            mat[i]=1;
            prime[ind++]=i;
            for(int j=2;i*j<=200;j++)mat[i*j]=1;
        }
    }
    ind=0;
}
void afisare(int x)
{
    if(x>ind)
    {
        ind=x;
        for(int i=0;i<x;++i)v[i]=b[i];
    }
    cnt++;
}
void backt(int x,int ist,int sum)
{
    if(sum>n);
    else if(sum==n)afisare(x);
    else
    {
        for(int i=ist+1;sum+prime[i]<=n;++i)
        {
            b[x]=prime[i];
            backt(x+1,i,sum+prime[i]);
        }
    }
}
int main()
{
    cin>>n;
    ciur();
    backt(0,-1,0);
    cout<<cnt<<'\n';
    for(int i=0;i<ind;++i)cout<<v[i]<<' ';
    return 0;
}
