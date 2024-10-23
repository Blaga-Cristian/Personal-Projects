#include <iostream>

using namespace std;
int n,b[100];
void afisare(int x)
{
    for(int i=0;i<=x;++i)cout<<b[i]<<" ";
    cout<<'\n';
}
void backtrack(int x,int ist,int sum)
{
    if(sum>n);
    else if(sum==n)afisare(x-1);
    else
    {
        for(int i=ist+1;i<=ist+2;++i)b[x]=i,backtrack(x+1,i,sum+i);
    }
}
void backtrack1()
{
    for(int i=1;i<=n;++i)
        b[0]=i,backtrack(1,i,i);
}
int main()
{
    cin>>n;
    backtrack1();
    return 0;
}
