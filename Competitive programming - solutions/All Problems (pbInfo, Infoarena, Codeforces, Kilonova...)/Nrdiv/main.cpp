#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,cnt,ok,nrd[100];
unsigned long long minim=1e9*2;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
vector<int>v;
unsigned long long calcs(int ind)
{
    int aux;
    long long nr=1;
    for(int i=ind,l=1;i>=1;--i,++l)
    {
        aux=nrd[i];
        while(aux>1)
        {
            nr*=prime[l];
            aux--;
            if(nr>1e9*2)return 1e9*2;
        }
    }
    return nr;
}
void backt(int x,int ind)
{
    if(x==1)
    {
        minim=min(minim,calcs(ind));
        return;
    }
    nrd[ind+1]=x;
    backt(1,ind+1);
    for(int i=0;prime[i]<=double(x/prime[i]);++i)
    {
        if(x%prime[i]==0)
        {
            nrd[ind+1]=prime[i];
            backt(x/prime[i],ind+1);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            ++cnt;
            if(i*i<n)++cnt;
        }
    }
    cnt+=2;
    backt(cnt,0);
    cout<<minim;
    return 0;
}
