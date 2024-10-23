#include <bits/stdc++.h>

using namespace std;
const int Inf = 0x3f3f3f3f;
int dp[(int)1e6 + 9];
int n;

int main()
{
    memset(dp, Inf, sizeof(dp));

    cin >> n;
    dp[n] = 0;
    for(int i = n; i >= 0; --i)
    {
        int aux = i;
        while(aux)
        {
            int c = aux % 10;
            if(i - c >= 0)dp[i-c] = min(dp[i-c], dp[i] + 1);
            aux /= 10;
        }
    }

    cout << dp[0];
    return 0;
}
