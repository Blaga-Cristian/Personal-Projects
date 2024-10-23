#include <fstream>
#include <vector>
#include <set>
using namespace std;
ifstream cin("detdrum3.in");
ofstream cout("detdrum3.out");

int n,m,a,b,c,x,y,z,node,cnt,nod,rad;
vector<set<int>>sirad;
vector<int> cost;
vector<int> dp;

void Dfs(int x,int parent)
{
    dp[x] = cost[x];

    for(auto i : sirad[x])
    {
        if(i==parent)continue;
        Dfs(i,x);
        dp[x] = max(dp[x],cost[x] + dp[i]);
    }
}
void Afis(int x,int parent,int scor)
{
    cout<<x<<' ';
    for(auto i : sirad[x])
        if(dp[x] == dp[i] + cost[x])
        {
            Afis(i,x,scor - cost[x]);
            break;
        }
}
int main()
{
    cin>>n;
    sirad = vector<set<int>>(n+1);
    cost = vector<int>(n+1);
    dp = vector<int>(n+1);

    for(int i=1;i<=n;++i)
    {
        cin>>x;
        if(x == 0)
            rad = i;
        else
            sirad[x].insert(i);
    }
    for(int i=1;i<=n;++i)
        cin>>cost[i];

    Dfs(rad,0);

    cout<<dp[rad]<<'\n';
    Afis(rad,0,dp[rad]);
}
