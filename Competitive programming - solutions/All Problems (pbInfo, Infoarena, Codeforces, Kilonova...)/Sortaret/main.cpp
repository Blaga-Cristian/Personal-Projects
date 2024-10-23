#include <fstream>
#include <vector>
using namespace std;
ifstream cin("sortaret.in");
ofstream cout("sortaret.out");

vector<vector<int> >sirad;
int ord[50005];
bool viz[50005];
int timee;
int n,m;
void Dfs(int x)
{
    viz[x] = true;
    for(auto i : sirad[x])
        if(!viz[i])Dfs(i);
    timee++;
    ord[n-timee+1]=x;
}
int main()
{
    int a,b;
    cin>>n>>m;
    sirad = vector<vector<int>>(n+1);
    while(m--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
    }
    for(int i=1;i<=n;++i)
        if(!viz[i])Dfs(i);
    for(int i=1;i<=n;++i)
        cout<<ord[i]<<' ';
    return 0;
}
