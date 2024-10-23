#include <fstream>
#include <cmath>
#include <vector>
#include <tuple>
#include <cstring>
#include <iomanip>
using namespace std;
ifstream cin("seg.in");
ofstream cout("seg.out");
const int N = 17,Inf = 0x3f3f3f3f;
int t,n;
double dp[1<<(N+1)][N][2];
///dp[S][i][0] = se termina in primele coord
///dp[S][i][0] = se termina in cealalta pereche de coordonate
struct seg
{
    double x1,y1,x2,y2;
};
vector<seg> segmente;
double getdist(int x1,int y1,int x2,int y2)
{
    return (double)sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}
void solve()
{
    int x1,y1,x2,y2;
    cin>>n;
    segmente = vector<seg>(n);
    for(int i = 0; i < n; ++i)
        cin>>segmente[i].x1>>segmente[i].y1>>segmente[i].x2>>segmente[i].y2;

    memset(dp,Inf,sizeof(dp));
    for(int i = 1; i < n; ++i)
    {
        auto sg = segmente[0];
        auto sg2 = segmente[i];
        dp[1<<i][i][0] = getdist(sg.x1,sg.y1,sg2.x2,sg2.y2);
        dp[1<<i][i][1] = getdist(sg.x1,sg.y1,sg2.x1,sg2.y1);
    }

    for(int s = 1; s < (1<<n); ++s)
        for(int i = 1; i < n; ++i)
            if(s&i)
            {
                auto sg = segmente[i];
                for(int k = 1; k < n; ++k)
                {
                    auto sg2 = segmente[k];
                    if(k != i && !(s&(1<<k)))
                    {
                        dp[s | (1<<k)][k][0] = min(dp[s | (1<<k)][k][0],min(dp[s][i][0] + getdist(sg.x1,sg.y1,sg2.x2,sg2.y2),
                                                                            dp[s][i][1] + getdist(sg.x2,sg.y2,sg2.x2,sg2.y2)));
                        dp[s | (1<<k)][k][1] = min(dp[s | (1<<k)][k][1],min(dp[s][i][0] + getdist(sg.x1,sg.y1,sg2.x1,sg2.y1),
                                                                            dp[s][i][1] + getdist(sg.x2,sg.y2,sg2.x1,sg2.y1)));
                    }
                }
            }

    double ans = Inf;
    for(int i = 1; i < n; ++i)
    {
        auto sg = segmente[i];
        auto sg2 = segmente[0];
        ans = min(ans,min(dp[(1<<n) - 1][i][0] + getdist(sg.x1,sg.y1,sg2.x2,sg2.y2),
                          dp[(1<<n) - 1][i][1] + getdist(sg.x2,sg.y2,sg2.x2,sg2.y2)));
    }

    cout<<fixed<<setprecision(6)<<ans<<'\n';
}
int main()
{
    cin>>t;
    while(t--)
        solve();
    return 0;
}
