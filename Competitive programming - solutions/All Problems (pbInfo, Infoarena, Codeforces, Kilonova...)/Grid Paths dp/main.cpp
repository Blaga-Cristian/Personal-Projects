#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int,int>
#define F first
#define S second
#define PB push_back
#define ll long long
#define ull unsigned ll
#define fast_in_out ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int Mod = 1e9 + 7;
const int N = 1009;
char s[2*N];
bool valid[N][N];
ll dp[N][N];

int main()
{
    memset(valid,true,sizeof(valid));
    int n;
    cin>>n;
    cin.get();
    for(int i = 1; i <= n; ++i)
    {
        cin.get(s,N);
        cin.get();
        for(int j = 1; j <= n; ++j)
            if(s[j-1] == '*')
                valid[i][j] = false;
    }

    if(valid[1][1])
        dp[1][1] = 1;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(valid[i][j] && (i != 1 || j != 1))
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % Mod;

    cout<<dp[n][n];
    return 0;
}
