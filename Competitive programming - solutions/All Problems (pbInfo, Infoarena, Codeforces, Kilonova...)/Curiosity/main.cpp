#include <fstream>
#include <queue>
#define t first
#define val second
using namespace std;
ifstream cin("curiosity2.in");
ofstream cout("curiosity2.out");

using pi = pair<int,int>;
const int N = 1e5 + 9,X = 1e9 + 9,Inf = 2000000000;
int xf,D,T,n;
pi dp[N];
int ans = 0;

int main()
{
    cin>>xf>>D>>T>>n;
    dp[1] = {0,-T};
    int st = 1, dr = 1;

    for(int i = 1; i <= n; ++i)
    {
        int x,y,l;
        cin>>x>>l;
        y = x + l;

        int nr_max = 0, dist_min = Inf;
        for(; st <= dr; ++st)
        {
            if(dp[st].second + D + T > y)break;

            int lun_seg = y - max(x,dp[st].second + T);
            int nr = lun_seg/D;

            int dist = max(x, dp[st].second + T) + nr * D;
            nr += dp[st].first;

            if(nr > nr_max || (nr == nr_max && dist < dist_min))
            {
                nr_max = nr;
                dist_min = dist;
            }
        }

        if(st > 1)--st;

        if(ans < nr_max)
        {
            ans = nr_max;
            dp[++dr] = {nr_max,dist_min};
        }
    }

    cout<<ans<<'\n';
    return 0;
}
