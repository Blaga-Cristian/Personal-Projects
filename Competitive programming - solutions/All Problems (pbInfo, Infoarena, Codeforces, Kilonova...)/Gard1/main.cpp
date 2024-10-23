#include <fstream>
#include <queue>
using namespace std;
ifstream cin("gard1.in");
ofstream cout("gard1.out");
using pi = pair<int,int>;
const int N = 1e5+9;
const int Inf = 0x3f3f3f3f;
struct element
{
    int x,y,c;
};

int n,k;
int dp[N];
element v[N];
vector<int> vec[N];
priority_queue<pi,vector<pi>,greater<pi> > q;
int main()
{
    cin>>n>>k;
    for(int i = 1; i<=k;++i)
        cin>>v[i].x>>v[i].y>>v[i].c,
        vec[v[i].x].push_back(i);

    dp[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        while(!q.empty() && q.top().second < i)
            q.pop();
        for(auto j : vec[i])
            q.push({dp[i-1] + v[j].c,v[j].y});
        dp[i] = q.top().first;
    }

    cout<<dp[n];
    return 0;
}
