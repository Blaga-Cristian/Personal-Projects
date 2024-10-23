#include <iostream>

using namespace std;
int n,m,b[20];
void afisare()
{
    if(b[0]==b[n-1]&&b[0]!=0)
    {
    for(int i=0;i<n;++i)cout<<b[i];
    cout<<'\n';
    }
}
void backtracking(int x)
{
    for(int i=0;i<m;++i)
    {
        b[x]=i;
        if(x==n-1)afisare();
        else backtracking(x+1);
    }
}
int main()
{
    cin>>n>>m;
    backtracking(0);
    return 0;
}
