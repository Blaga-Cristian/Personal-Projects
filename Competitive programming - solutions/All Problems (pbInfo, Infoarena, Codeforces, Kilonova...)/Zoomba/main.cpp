#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
ifstream cin("zoomba.in");
ofstream cout("zoomba.out");
const int Inf = 0x3f3f3f3f;
int n,m,k,z;
int dp[201][1<<11],poz[20];
vector<vector<int> > sirad,dist,trs;

queue<int> q;
void Bfs(int v)
{
    int x;
    while(!q.empty())
    {
        x = q.front();
        q.pop();

        for(auto i : sirad[x])
            if(dp[i][v] > dp[x][v] + 1)
            {
                dp[i][v] = dp[x][v] + 1;
                q.push(i);
            }
    }

}
int construct(int l)
{
    int ret = 0 ,i = 0;
    while(l--)
        ret^=(1<<(i++));
    return ret;
}
int main()
{
    int a,b;
    for(int i=0;i<11;++i)
        for(int j=0;j<(1<<11);++j)
            dp[i][j] = Inf;
    cin>>n>>m>>k>>z;
    sirad = vector<vector<int>>(n+1);
    for(int i=0;i<k;++i)
        cin>>poz[i];
    while(m--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
        sirad[b].push_back(a);
    }
    for(int i=0;i<k;++i)
        dp[poz[i]][1<<i] = 0,
        q.push(poz[i]),
        Bfs(1<<i);
    for(int l=2;l<=k;++l)
        for(int j = construct(l);j<(1<<k);++j)
            if(__builtin_popcount(j) == l)
            {
                for(int i=1;i<=n;++i)
                {
                    for(int c=0 ;c<j;++c)
                        if((j|c)==j)
                        dp[i][j] = min(dp[i][j],dp[i][c] + dp[i][j^c]);
                    q.push(i);
                }
                Bfs(j);
            }
    cout<<(dp[z][(1<<k)-1] == Inf ? -1 : dp[z][(1<<k)-1])<<'\n';
    return 0;
}
