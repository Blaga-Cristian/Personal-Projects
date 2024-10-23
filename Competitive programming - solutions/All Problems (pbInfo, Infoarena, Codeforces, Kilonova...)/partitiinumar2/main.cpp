#include <fstream>

using namespace std;
ifstream cin("partitiinumar2.in");
ofstream cout("partitiinumar2.out");
int n,m,b[100];
void afisare(int x)
{
    for(int i=0;i<=x;++i)cout<<b[i]<<' ';
    cout<<'\n';
}
void backtrack(int x,int ist,int sum)
{
    if(sum>n);
    else if(sum==n&&x>=m)afisare(x-1);
    else
    {
        for(int i=ist+1;sum+i<=n;++i)
        {
            b[x]=i;
            backtrack(x+1,i,sum+i);
        }
    }
}
int main()
{
    cin>>n>>m;
    backtrack(0,0,0);
    return 0;
}
