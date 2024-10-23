#include <fstream>

using namespace std;
ifstream cin("varf.in");
ofstream cout("varf.out");
int s,n,v[15],b[15],ok,ok1;
bool p[15];
void afisare(int x)
{
    for(int i=0;i<=x;++i)cout<<b[i]<<" ";
    cout<<'\n';
    ok=1;
}
bool verificare(int x)
{
    if(b[0]>b[1])return 0;
    else if(b[x]>b[x-1])return 0;
    else
    {
        int i=0,j=0;
        for(i=1;i<=x&&b[i-1]<b[i];++i);
        for(j=i;j<=x&&b[j-1]>b[j];++j);
        if(j!=x+1)return 0;
    }
    return 1;
}
void backtracking(int x,int ist)
{
    for(int i=ist;i<n;++i)
    {
        b[x]=v[i];
        if(x>=2)if(verificare(x))afisare(x);
        backtracking(x+1,i+1);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>v[i];
    backtracking(0,0);
    if(ok==0)cout<<0;
    return 0;
}
