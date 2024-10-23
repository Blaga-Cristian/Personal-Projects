#include <fstream>

using namespace std;
ifstream cin("mere.in");
ofstream cout("mere.out");
bool matad[1000][1000];
int v[1000];
int n,sum;
void Dfs(int x,int parent)
{
    sum+=v[x];
    int poz = 0;
    for(int i=1;i<=n;++i)
        if(matad[x][i]==1&&v[i]>v[poz]&&i!=parent)poz=i;
    if(poz)Dfs(poz,x);
}
int main()
{
    int a,b;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>v[i];
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        matad[a][b] = matad[b][a] = 1;
    }
    Dfs(1,-1);
    cout<<sum;
    return 0;
}
