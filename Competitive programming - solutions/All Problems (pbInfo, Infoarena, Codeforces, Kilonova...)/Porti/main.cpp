#include <fstream>
#include <queue>
using namespace std;
ifstream cin("poarta.in");
ofstream cout("poarta.out");

const int N = 105,K = 1005,dx[] = {-1,0,1,0},dy[] = {0,1,0,-1},Inf = 0x3f3f3f3f,mod = 997;
int n,m,k;
int dp[N][N],cnt[N][N]; /// cnt[i][j] = nr de moduri de a ajunge in spatiul i intr-un mod minim de timp
bool poarta[N][N];
vector<pair<int,int> > porti;
pair<int,int> start,stop;
void Lee()
{
    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    dp[start.first][start.second] = 0;
    cnt[start.first][start.second] = 1;
    while(!q.empty())
    {
        int x = q.front().first,
        y = q.front().second;
        q.pop();

        if(poarta[x][y])
        {
            for(auto i : porti)
            {
                int a = i.first,
                b = i.second;
                if(dp[x][y] + 1 < dp[a][b])
                {
                    dp[a][b] = dp[x][y] + 1;
                    cnt[a][b] = cnt[x][y];
                    q.push({a,b});
                }
                else if(dp[x][y] + 1 == dp[a][b])
                    cnt[a][b] += cnt[x][y],
                    cnt[a][b] = cnt[a][b]%mod;
            }
        }

        for(int i=0;i<4;++i)
        {
            int nx = x+dx[i],
            ny = y + dy[i];
            if(dp[x][y] + 1 < dp[nx][ny])
            {
                dp[nx][ny] = dp[x][y] + 1;
                cnt[nx][ny] = cnt[x][y];
                q.push({nx,ny});
            }
            else if(dp[x][y] + 1 == dp[nx][ny])
                cnt[nx][ny] += cnt[x][y],
                cnt[nx][ny] = cnt[nx][ny]%mod;
        }
    }
}
int main()
{
    int a,b;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            dp[i][j] = Inf;
    cin>>start.first>>start.second>>stop.first>>stop.second;
    for(int i=1;i<=k;++i)
    {
        cin>>a>>b;
        poarta[a][b] = 1;
        porti.push_back({a,b});
    }
    Lee();
    cout<<dp[stop.first][stop.second]<<'\n';
    cout<<cnt[stop.first][stop.second];
    return 0;
}
