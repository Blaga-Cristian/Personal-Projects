#include <fstream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
ifstream cin("estearbore.in");
ofstream cout("estearbore.out");
int n;
bool matad[109][109];
bool viz[109];
bool ok =1;
void Dfs(int x,int parent)
{
    viz[x] = true;
    for(int i=1; i<=n;++i)
    {
        if(matad[x][i])
        {
            if(!viz[i])Dfs(i,x);
            else if(i!=parent)ok=0;
        }
    }
}
int main()
{
    int a,b;
    cin>>n;
    while(cin>>a>>b)
    {
        matad[a][b] = matad[b][a] = true;
    }
    Dfs(1,0);
    for(int i=1;i<=n;++i)if(viz[i]==0)ok=0;
    if(ok==1)cout<<"DA";
    else cout<<"NU";
    return 0;
}
