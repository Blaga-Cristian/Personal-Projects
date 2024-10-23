#include <fstream>
#include <cmath>
#define ull unsigned long long int
using namespace std;
ifstream cin("fibonacci3.in");
ofstream cout("fibonacci3.out");
#define maxi 2500000000000000225
int n,nrf;
ull fibonacci[500],nr,v[30];
bool verificare(ull sum)
{
    int step,i;
    for(step=1;step<nrf;step<<=1);
    for(i=0;step;step>>=1)if(i+step<nrf&&fibonacci[i+step]<=sum)i+=step;
    if(fibonacci[i]==sum)return 1;
    return 0;
}
void backtracking(int ist,ull s)
{
    ull sum=0;
    for(int i=ist;i<n;++i)
    {
        if(verificare(s+v[i]))++nr;
        backtracking(i+1,s+v[i]);
    }
}
int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;++i)cin>>v[i];
    fibonacci[0]=0;
    fibonacci[1]=1;
    i=1;
    while(fibonacci[i++]<maxi)fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
    nrf=i;
    backtracking(0,0);
    cout<<nr;
    return 0;
}
