#include <iostream>

using namespace std;
int v[10],n,b[10];
bool p[10];
void afisare()
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(b[i]%2==0)cnt++;
    }
    if(cnt>n/2)
    {
        for(int i=0;i<n;i++)cout<<b[i];
        cout<<'\n';
    }
}
void backtracking(int x)
{
    int i;
    if(x==0)i=1;
    else i=0;
    for(i;i<10;i++)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=i;
            if(x==n-1)afisare();
            else backtracking(x+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    backtracking(0);
    return 0;
}
