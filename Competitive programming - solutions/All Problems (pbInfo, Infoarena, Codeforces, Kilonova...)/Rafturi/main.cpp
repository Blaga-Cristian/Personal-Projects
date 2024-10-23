#include <fstream>

using namespace std;
ifstream cin("rafturi.in");
ofstream cout("rafturi.out");
const int C = 10009, N = 50009,Inf = 0x3f3f3f3f;
int c,n,dp[C],h[C]; /// dp[i][j] = suma minima pentru reafturile 1...i cu bibliotecare pe pozitia j
int d,x,mn;

int main()
{
    int x;
    cin>>c>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>d>>x;
        h[d] = max(h[d],x);
    }
    dp[0] = 0;
    for(int i=1;i<=c;++i)
    {
        dp[i] = Inf;
        int hl = h[i];
        dp[i] = min(dp[i],dp[i-1] + hl);

        if(i>1)
        {
            hl = max(h[i-1],hl);
            dp[i] = min(dp[i],dp[i-2] + hl);
        }
        if(i>2)
        {
            hl = max(h[i-2],max(h[i-1],hl));
            dp[i] = min(dp[i],dp[i-3] + hl);
        }
    }
    cout<<dp[c];
    return 0;
}
