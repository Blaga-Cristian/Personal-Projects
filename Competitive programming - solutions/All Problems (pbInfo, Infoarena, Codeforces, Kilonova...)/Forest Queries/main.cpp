#include <iostream>
#include <cstring>
using namespace std;
const int N = 1009;

int n, q, x1, y1, x2, y2, dp[N][N];
char s[N];

int main()
{
    cin >> n >> q;
    cin.get();
    for(int i = 1; i <= n; ++i)
    {
        cin.get(s, N);
        cin.get();
        for(int j = 1; j <= n; ++j)
            if(s[j - 1] == '*')
                dp[i][j] = 1;
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

    while(q --)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}
