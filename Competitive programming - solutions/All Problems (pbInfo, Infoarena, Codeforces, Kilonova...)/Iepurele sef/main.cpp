#include <fstream>
#include <vector>
using namespace std;
ifstream cin("iepuri1.in");
ofstream cout("iepuri1.out");
const int mod = 30011,N = 105;
using VI = vector<int>;
using VVI = vector<VI>;
VVI sirad;
int n,K;
int in[N],rad;
int dp[N][N]; ///dp[i][j] = nr de moduri de a ajunge in nodul i cu j morcovi
void Dfs(int x)
{
    for(auto i : sirad[x])
        Dfs(i);

    for(int k = K; k>=1; --k)
    {
        dp[x][k] = 1;
        for(auto i : sirad[x])
        {
            dp[i][k+1] += dp[i][k+2];
            dp[i][k+1] %= mod;

            dp[x][k] = (dp[x][k] * dp[i][k+1])%mod;
        }
    }
}
int main()
{
    int a,b;
    cin>>n>>K;
    sirad = VVI(n+1);
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
        in[b]++;
    }
    for(int i=1;i<=n;++i)
        if(in[i]==0)
        {
            rad = i;
        }
        else if(in[i] == 1)
        {
            for(int j=1;j<=K;++j)
                dp[i][j] = 1;
        }
    Dfs(rad);
    int ans = 0;
    for(int k = 1; k<=K;++k)
        ans += dp[rad][k];
    cout<<ans;
    return 0;
}
