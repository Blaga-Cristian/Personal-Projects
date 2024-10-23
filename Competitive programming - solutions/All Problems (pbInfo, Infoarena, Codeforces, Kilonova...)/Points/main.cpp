#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
ifstream cin("points.in");
ofstream cout("points.out");
const int N = 10009, mod = 666013;
struct point
{
    int x,y;
    inline bool operator < (const point& other) const {
    return (x == other.x) ? (y > other.y) : (x < other.x);
  }
};
point v[N];
int n,dp[N];///cel mai lung subsir care se termina in i

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i].x>>v[i].y;

    sort(v+1,v+n+1);
    dp[1] = 1;
    for(int i=2;i<=n;++i)
    {
        dp[i] = 1;
        for(int j=i-1;j>0;--j)
            if(v[j].y >= v[i].y)
                dp[i] = (dp[j] + dp[i])%mod;
    }
    int ans = 0;
    for(int i=1;i<=n;++i)
        ans = (ans + dp[i])%mod;
    cout<<ans;
    return 0;
}
