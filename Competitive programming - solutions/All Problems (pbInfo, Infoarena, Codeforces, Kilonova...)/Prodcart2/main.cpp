#include <fstream>

using namespace std;
ifstream cin("produscartezian2.in");
ofstream cout("produscartezian2.out");
int n,v[10],b[20];
void afisare()
{
    for(int i=0;i<n;++i)cout<<b[i]<<" ";
    cout<<'\n';
}
void backtracking(int x)
{
    for(int i=0;i<v[x];++i)
    {
        b[x]=i+1;
        if(x==n-1)afisare();
        else backtracking(x+1);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)cin>>v[i];
    backtracking(0);
    return 0;
}
