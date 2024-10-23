#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("ross.in");
ofstream cout("ross.out");
const int N = 2009;
using ll = long long;
ll n,m,q,v,val;
ll dp[N][N];
///dp[i][k] = costul maxim de a alege k puncte din intervalul 1 ... i
struct pct
{
    int x,y;
}point[N];

ll dist(pct a,pct b)
{
    return 1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y);
}

int cb(ll x)
{
    int st = 0,dr = n,poz = -1,mj;
    while(st <= dr)
    {
        mj = (st + dr)>>1;
        if(dp[n][mj] > x)
            dr = mj-1;
        else
        {
            poz = mj;
            st = mj + 1;
        }
    }
    return poz;
}

int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>point[i].x>>point[i].y;

    for(int i = 1; i <= n; ++i)
        for(int k = 1; k <= i; ++k)
    {
        dp[i][k] = dp[i-1][k];
        if(i == 1)
            dp[i][k] = max(dp[i][k],dist(point[i],point[i+1]));
        else if(i == n)
            dp[i][k] = max(dp[i][k],dp[i-2][k-1] + dist(point[i-1],point[i]));
        else
            dp[i][k] = max(dp[i][k],dp[i-2][k-1] + dist(point[i-1],point[i]) + dist(point[i],point[i+1]));
    }

    cin>>q;
    while(q--)
    {
        cin>>val;
        cout<<cb(val)<<'\n';
    }
    return 0;
}
