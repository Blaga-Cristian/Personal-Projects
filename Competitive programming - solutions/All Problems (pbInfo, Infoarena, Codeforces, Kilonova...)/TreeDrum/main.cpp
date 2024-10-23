#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream cin("14-drumarb.in");
ofstream cout("drumarb.out");
using ll = long long;
const int N = 1e5 + 9;
ll n,rem[N],t;
vector<vector<int>> G;
ll dp[N];

void Dfs(int x)
{
    rem[x]--;

    vector<pair<ll,int>> v;
    for(auto i : G[x])
    {
        Dfs(i);

        v.push_back({dp[i],i});
    }

    sort(v.begin(),v.end(),greater<pair<int,int>>());

    for(auto i : v)
        if(rem[x])
        {
            dp[x] += 2 + i.first;
            rem[x]--;
        }

    for(auto i : G[x])
        if(rem[x] && rem[i])
            if(rem[x] >= rem[i])
            {
                dp[x] += 2 * rem[i];
                rem[x] -= rem[i];
                rem[i] = 0;
            }
            else
            {
                dp[x] += 2 * rem[x];
                rem[i] -= rem[x];
                rem[x] = 0;
            }
}

int main()
{
    cin>>n;
    G = vector<vector<int>>(n+1);
    for(int i = 1; i <= n; ++i)
        cin>>rem[i];

    for(int i = 2; i <= n; ++i)
    {
        cin>>t;
        G[t].push_back(i);
    }

    Dfs(1);
    cout<<dp[1];
    return 0;
}
