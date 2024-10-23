#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;
ifstream cin("pqstr.in");
ofstream cout("pqstr.out");
using ll = long long;
using pi = pair<int,int>;
const int N = 1e5 + 9;
ll n,p,q,v[N];
ll dp[N],dminus[N],dplus[N];
deque<ll> mindq,plsdq;
void pushmin(int ind)
{
    while(!mindq.empty() && dminus[mindq.back()] < dminus[ind])
        mindq.pop_back();
    mindq.push_back(ind);
}
int querymin(int ind)
{
    while(!mindq.empty() && mindq.front() < ind)
        mindq.pop_front();
    return mindq.front();
}
void pushpls(int ind)
{
    while(!plsdq.empty() && dplus[plsdq.back()] < dplus[ind])
        plsdq.pop_back();
    plsdq.push_back(ind);
}
int querypls(int ind)
{
    while(!plsdq.empty() && plsdq.front() < ind)
        plsdq.pop_front();
    return plsdq.front();
}

int main()
{
    cin>>n>>p>>q;
    for(int i = 1; i <= n; ++i)
        cin>>v[i];

    for(int i = 1; i <= p; ++i)
        dminus[i] -= v[i],
        dplus[i] += v[i];

    pushmin(1);
    pushpls(1);
    for(int i = p + 1; i <= n; ++i)
    {
        int imin = querymin(i-q);
        int ipls = querypls(i-q);

        dp[i] = max(dminus[imin] + v[i],dplus[ipls] - v[i]);

        dminus[i] = dp[i] - v[i];
        dplus[i] = dp[i] + v[i];

        pushmin(i-p+1);
        pushpls(i-p+1);
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = max(ans,dp[i]);
    cout<<ans;
    return 0;
}
