#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
ifstream fin("gears.in");
ofstream fout("gears.out");
int n,m,g;
vector<set<int> > sirad;
vector<int> v;
vector<bool> viz;
vector<char> ans;
int cnt,sum;
void Dfs(int x,int f)
{
    int ind=0;
    sum+=v[x];
    for(auto i : sirad[x])
        if(i!=f&&v[i]>v[ind])ind = i;
    if(ind)Dfs(ind,x);
}
int main()
{
    int a,b,x,k;
    fin>>n>>x;
    sirad = vector<set<int> >(n+1);
    viz = vector<bool>(n+1);
    v = vector<int>(n+1);
    for(int i=1;i<=n;++i)fin>>v[i];
    for(int i=1;i<n;++i)
    {
        fin>>a>>b;
        sirad[a].insert(b);
        sirad[b].insert(a);
    }
    Dfs(1,-1);
    fout<<sum;
    return 0;
}
