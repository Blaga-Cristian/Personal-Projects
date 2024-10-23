#include <fstream>
#include <queue>
using namespace std;
ifstream cin("taxe.in");
ofstream cout("taxe.out");
const int Inf = 0x3f3f3f3f,mod = 10007,di[] = {-1,0,1,0},dj[] = {0,1,0,-1};
int n,m,x1,y1,x2,y2,c,dp[100005];

int main()
{
    int x;
    cin>>n;
    dp[0] = 0;
    dp[1] = 1;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        dp[i]=max(dp[i-1],dp[i-2]+x);
    }
    cout<<dp[n];
    return 0;
}
