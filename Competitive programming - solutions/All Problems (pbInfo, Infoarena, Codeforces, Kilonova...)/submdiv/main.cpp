#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("submdiv.in");
ofstream cout("submdiv.out");
int v[200],k,x,m,b[200],ok;
int p[200];
void afisare()
{
    for(int i=0;i<m;++i)cout<<b[i]<<" ";
    cout<<'\n';
    ok=1;
}
void backtrack(int x,int ist)
{
    for(int i=ist;i<k;++i)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=v[i];
            if(x==m-1)afisare();
            else backtrack(x+1,i+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>x>>m;
    for(int i=1;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v[k++]=i;
            if(i*i!=x)v[k++]=x/i;
        }
    }
    sort(v,v+k);
    backtrack(0,0);
    if(ok==0)cout<<"fara solutie";
    return 0;
}
