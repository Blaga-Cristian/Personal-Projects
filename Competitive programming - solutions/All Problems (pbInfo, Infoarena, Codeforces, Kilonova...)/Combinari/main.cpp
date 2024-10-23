#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("combinari.in");
ofstream cout("combinari.out");
int n,k,b[20];
bool p[20];
void afisare()
{
    for(int i=0;i<k;i++)cout<<b[i]+1<<" ";
    cout<<'\n';
}
void backtracking(int x,int ist)
{
    for(int i=ist;i<n;i++)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=i;
            if(x==k-1)afisare();
            else backtracking(x+1,i+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n>>k;
    backtracking(0,0);
    return 0;
}
