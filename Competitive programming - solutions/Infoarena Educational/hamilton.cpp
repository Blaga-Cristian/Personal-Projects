#include <fstream>
#include <vector>
using namespace std;
ifstream cin("hamilton.in");
ofstream cout("hamilton.out");
const int Smax = 1<<18,MaxN = 19,Inf  = 0x3f3f3f3f;
int n,m,dp[Smax][MaxN],cost[MaxN][MaxN];
vector<vector<int> >sirad;
int main()
{
    int a,b,c;
    cin>>n>>m;
    sirad = vector<vector<int>>(n+1);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cost[i][j] = Inf;
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>c;
        sirad[a].push_back(b);
        cost[a][b] = c;
    }

    for(int i=0;i<n;++i)
        for(int j=0; j< 1<<n ; ++j)
            dp[j][i] = Inf;
    dp[1][0] = 0;

    for(int i=0;i< 1<<n; ++i)
        for(int j=0;j<n;++j)
            if(i&(1<<j))
            {
                for(auto nod : sirad[j])
                    if(!(i&(1<<nod)))
                        dp[i|(1<<nod)][nod] = min(dp[i|(1<<nod)][nod],dp[i][j] + cost[j][nod]);
            }
    int res = Inf;
    for(int i=0;i<n;++i)
        res = min(res,dp[(1<<n)-1][i] + cost[i][0]);
    if(res==Inf)
    {
        cout<<"Nu exista solutie";
        return 0;
    }
    cout<<res;
    return 0;
}