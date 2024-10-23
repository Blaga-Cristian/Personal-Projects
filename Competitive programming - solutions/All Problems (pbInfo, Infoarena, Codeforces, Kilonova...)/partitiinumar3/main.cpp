#include <fstream>

using namespace std;
ifstream cin("partitiinumar3.in");
ofstream cout("partitiinumar3.out");
int n,a,b,v[100];
void afisare(int x)
{
    for(int i=0;i<=x;++i)cout<<v[i]<<' ';
    cout<<'\n';
}
void backtrack(int x,int ist,int sum)
{
    if(sum>n);
    else if(sum==n)afisare(x-1);
    else
    {
        for(int i=ist;i<=b;++i)
        {
           v[x]=i;
            backtrack(x+1,i,sum+i);
        }
    }
}
int main()
{
    cin>>n>>a>>b;
    backtrack(0,a,0);
    return 0;
}
