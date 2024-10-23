#include <fstream>

using namespace std;
using ll = long long;
ifstream cin("datorii.in");
ofstream cout("datorii.out");
const int N = 1009;
int n;
ll dp[N];
ll v[N];
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>v[i];
    dp[1] = v[1];
    dp[2] = v[1];
    for(int i = 3; i <= n; ++i)
        dp[i] = max(dp[i-1],dp[i-2] + v[i]);
    cout<<dp[n];
    return 0;
}
