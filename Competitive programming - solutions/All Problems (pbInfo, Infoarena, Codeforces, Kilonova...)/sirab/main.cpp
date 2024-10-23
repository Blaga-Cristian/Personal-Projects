#include <fstream>

using namespace std;
ifstream cin("sirab.in");
ofstream cout("sirab.out");
int s,n,b[10],ok;
void afisare()
{
    for(int i=1;i<=n;++i)cout<<b[i]<<" ";
    cout<<'\n';
    ok=1;
}
bool verificare(int val,int x)
{
    for(int i=1;i<x;++i)if((val+b[i])%(val-b[i])!=0)return false;
    return true;
}
void backtracking(int x,int ist)
{
    for(int i=ist;i<=s;++i)
    {
        if(verificare(i,x))
        {
            b[x]=i;
            if(x==n)afisare();
            else backtracking(x+1,i+1);
        }
    }
}
int main()
{
    cin>>s>>n;
    backtracking(1,1);
    if(ok==0)cout<<0;
    return 0;
}
