#include <fstream>
#include <vector>
using namespace std;
ifstream cin("partitiimultime3.in");
ofstream cout("partitiimultime3.out");
int vmax[20],n,m;
vector<int> v[10];
void afisare()
{
    bool ok=0;
    for(int i=0;i<10;++i)if(v[i].size()!=0&&v[i].size()!=m)
    {
        ok=1;
        break;
    }
    if(ok==0)
    {
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<v[i].size();++j)cout<<v[i][j];
        if(v[i].size()!=0)cout<<'*';
    }
    cout<<'\n';
    }
}
void backtrack(int x)
{
    if(x==n+1)afisare();
    else
    {
        for(int i=1;i<=vmax[x]+1;++i)vmax[x+1]=max(i,vmax[x]),v[i].push_back(x),backtrack(x+1),v[i].pop_back();
    }
}
int main()
{
    cin>>n>>m;
    if(n%m!=0)cout<<"IMPOSIBIL";
    else backtrack(1);
    return 0;
}
