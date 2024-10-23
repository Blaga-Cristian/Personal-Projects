#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int N = 2 * 1e5 + 9, K = 19;
const ll Inf = 9223372036854775800LL;
ll k,n;
ll moves[K][K];
ll t[(1<<K) + 9];
ll dp[(1<<K) + 9];
ll mod[(1<<K) + 9];
char s[N];

int main()
{
    cin>>k>>n;
    cin.get();
    for(int s = 0; s < (1<<K); ++s)
        dp[s] = Inf;

    cin.get(s,N);
    cin.get();
    for(int i = 0; i < n - 1; ++i)
    {
        moves[s[i] - 'a'][s[i+1] - 'a']++;
        moves[s[i+1] - 'a'][s[i] - 'a']++;
    }

    dp[(1<<(s[0]-'a'))] = 0;
    mod[(1<<(s[0]-'a'))] = 1;

    for(int s = 0; s < (1<<k); ++s)
        if(dp[s] != Inf)for(int i = 0; i < k; ++i)
            if(!(s & (1<<i)))
            {
                ll cst = 0;
                int sz = __builtin_popcount(s) + 1;

                int aux = s;
                for(int j = sz - 1; j >= 1; --j,aux ^= (1<<t[aux]))
                    cst += 1LL * moves[i][t[aux]] * min((ll)sz - j,k-(sz-j));

                if(dp[s | (1<<i)] == dp[s] + cst)
                    mod[s | (1<<i)] += mod[s];
                else if(dp[s | (1<<i)] > dp[s] + cst)
                {
                    dp[s | (1<<i)] = dp[s] + cst;
                    mod[s | (1<<i)] = mod[s];
                    t[s | (1<<i)] = i;
                }
            }

    cout<<dp[(1<<k)-1] + n<<'\n'<<mod[(1<<k)-1]<<'\n';

    k = n = 0;
    memset(moves,0,sizeof(moves));
    memset(t,0,sizeof(moves));
    memset(dp,0,sizeof(moves));
    memset(mod,0,sizeof(moves));
    return 0;
}
