#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
ifstream cin("partitiimultime.in");
ofstream cout("partitiimultime.out");
int n,b[20];
int maxim(int k)
{
    int z=0;
    for(int i=1;i<k;++i)z=max(z,b[i]);
    return z;
}
void afisare()
{
    for(int i=1;i<=maxim(n+1);++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(b[j]==i)cout<<j;
        }
        cout<<"*";
    }
    cout<<'\n';
}
void backtracking(int x)
{
    if(x==n+1)afisare();
    else
    {
    for(int i=1;i<=maxim(x)+1;++i)
    {
        b[x]=i;
        backtracking(x+1);
    }
    }
}
int main()
{
    cin>>n;
    b[1]=1;
    backtracking(1);
    return 0;
}
