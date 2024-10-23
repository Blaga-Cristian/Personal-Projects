#include <fstream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;
ifstream cin("reteta1.in");
ofstream cout("reteta1.out");
int n,m,medicamente[20],mask[22],b[22];
double sumret[22];
double suma=999999;
vector<int>v[16];
char str[255];
bool p[21];
void calcs(int x)
{
    double sum=0;
    for(int i=1;i<x;++i)
    {
        sum+=sumret[b[i]];
    }
    suma=min(sum,suma);
}
void backt(int x,int sum)
{
    if(sum==(1<<n)-1)calcs(x);
    else if(sum<(1<<n)-1)
    {
    for(int i=1;i<=m;++i)
    {
        if(p[i]==0)
        {
            if((sum&mask[i])==0)
            {
                p[i]=1;
                b[x]=i;
                backt(x+1,sum+mask[i]);
                p[i]=0;
            }
        }
    }
    }
}
int main()
{
    int x,q,nr;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        nr=0;
        cin>>x;
        v[i].push_back(x);
        cin>>q;
        for(int j=1;j<=q;++j)
        {
            cin>>x;
            v[i].push_back(x);
            nr+=1<<(x-1);
        }
        mask[i]=nr;
    }
    for(int i=1;i<=n;++i)cin>>medicamente[i];
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<v[i].size();++j)sumret[i]+=medicamente[v[i][j]];
        if(v[i][0]==2)sumret[i]/=2;
    }
    backt(1,0);
    cout<<fixed<<setprecision(1)<<suma;
    return 0;
}
