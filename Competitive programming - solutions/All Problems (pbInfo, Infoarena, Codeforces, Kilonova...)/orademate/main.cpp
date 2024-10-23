#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("orademate.in");
ofstream cout("orademate.out");
int n,m,b[20],C;
void afisare()
{
    if(b[1]!=0)
    {
    for(int i=1;i<=n;++i)cout<<b[i];
    cout<<'\n';
    }
    else
    {
        int ok=0;
        for(int i=1;i<=n;++i)
        {
            if(b[i]!=0)
            {
                ok=1;
                break;
            }
        }
        if(ok==0&&n==1)cout<<0<<'\n';
    }
}
void backtracking1(int x,int val)
{
    for(int i=0;i<10;++i)
    {
        if(i!=x&&i>=val)
        {
            b[x]=i;
            if(x==n)afisare();
            else backtracking1(x+1,i);
        }
    }
}
void backtracking(int x)
{
    for(int i=0;i<10;++i)
    {
        if(i%2!=x%2)
        {
            b[x]=i;
            if(x==n)afisare();
            else backtracking(x+1);
        }
    }
}
int main()
{
    cin>>C>>n;
    if(C==1)
    {
        backtracking(1);
    }
    else
    {
        backtracking1(1,0);
    }
    return 0;
}
