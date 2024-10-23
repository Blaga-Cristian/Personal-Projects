#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
using namespace std;
const int N = 21, Inf = 0x3f3f3f3f;
int n, x, w[N];
PI dp[1 << N];

int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; ++i)cin >> w[i];

    for(int i = 0; i < (1 << n); ++i)dp[i] = {Inf, Inf};
    dp[0] = {0, 0};

    for(int i = 0; i < (1 << n); ++i)
        for(int j = 0; j < n; ++j)
            if(!(i & (1 << j)))
            {
                auto aux = dp[i];
                if(aux.S + w[j] > x)
                {
                    aux.F++;
                    aux.S = 0;
                }
                aux.S += w[j];

                dp[i | (1 << j)] = min(dp[i | (1 << j)], aux);
            }

    cout << (dp[(1 << n) - 1].F + (dp[(1 << n) - 1].S > 0));
    return 0;
}
