#include <fstream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
ifstream cin("lant1.in");
ofstream cout("lant1.out");
int n,p,q,r;
bool matad[109][109];
bool viz[109];
bool ok =1;
int t[109];
void Bfs(int x)
{
    queue<int> q;
    q.emplace(x);
    while(!q.empty())
    {
        x = q.front();
        viz[x] = true;
        q.pop();

        for(int i=1;i<=n;++i)
            if(matad[x][i]&&!viz[i])
            {
                t[i] = x;
                q.emplace(i);
            }
    }
}
void afisare(int x)
{
    cout<<x<<' ';
    viz[x] = true;
    if(t[x]!=0)afisare(t[x]);
}
int main()
{
    int a,b;
    cin>>n>>p>>q>>r;
    while(cin>>a>>b)
    {
        matad[a][b] = matad[b][a] = 1;
    }
    Bfs(q);
    for(int i=1;i<=n;++i)viz[i]=0;
    afisare(p);
    for(int i=1;i<=n;++i)t[i]=0;
    Bfs(r);
    afisare(q);
    return 0;
}
