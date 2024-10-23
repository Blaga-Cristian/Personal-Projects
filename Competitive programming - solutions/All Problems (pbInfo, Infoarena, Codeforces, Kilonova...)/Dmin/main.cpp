#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
//ifstream cin("lant1.in");
//ofstream cout("lant1.out");
int n,p,q,m,r,k;
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
                t[i] = t[x]+1;
                q.emplace(i);
            }
    }
}
int afisare(int x)
{
    if(t[x]==0)return 0;
    else return 1 + afisare(t[x]);
}
int main()
{
    int a,b;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        matad[a][b] = matad[b][a] = 1;
    }
    cin>>k;
    while(k--)
    {
        cin>>a>>b;
        Bfs(a);
        cout<<t[b]<<'\n';
        for(int j=1;j<=n;++j)
        {
            t[j] = viz[j] = 0;
        }
    }
    return 0;
}
