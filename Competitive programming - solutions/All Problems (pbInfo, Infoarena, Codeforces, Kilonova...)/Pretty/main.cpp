#include <bits/stdc++.h>
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
using namespace std;
//ifstream fin("bombs.in");
//ofstream fout("bombs.out");
const int N = 1009;

int dp[3][N], fact[N], n;


int main()
{
    cin >> n;

    dp[0][1] = 1;
    dp[0][2] = 1;
    //dp[0][3] = 3;

    dp[1][1] = 0;
    dp[1][2] = 1;
    //dp[1][3] = 2;

    dp[2][1] = 0;
    dp[2][2] = 0;
    //dp[2][3] = 1;

    for(int i = 3; i <= n; ++i)
    {
        dp[0][i] = dp[0][i - 1] * (i - 1) + dp[1][i - 1];
        dp[1][i] = dp[1][i - 1] * (i - 2) + dp[0][i - 1];
        dp[2][i] = dp[2][i - 1] * (i - 1) + dp[1][i - 1];
    }


    cout << dp[1][n] << '\n';
    cout << dp[2][n];
    return 0;
}
