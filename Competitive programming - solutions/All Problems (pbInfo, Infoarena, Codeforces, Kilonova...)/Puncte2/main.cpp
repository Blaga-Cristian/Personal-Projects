#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("puncte2.in");
ofstream cout("puncte2.out");
using ll = long long;
const int Nmax = 110;
const int Kmax = Nmax*Nmax;

ll MOD = 1000000007;
ll N,M,P;
ll dp[Nmax][Kmax];
ll CombNPow[Nmax][5];

ll pow_mod(ll x, ll n, ll mod)
{
    if(n == 0) return 1;

    ll p = pow_mod(x,n/2,mod);
    if(n%2) return ((p * p)%mod * x)%mod;
    return (p * p)%mod;
}

ll div_mod(ll x, ll y, ll mod)
{
    while(x % y != 0) x += mod;
    return (x/y)%mod;
}

void compute_comb(ll n, ll m)
{
    CombNPow[0][0] = CombNPow[0][1] = 1;
    ll current_comb = 1;

    for(int k = 1; k <= n; ++k)
    {
        current_comb = current_comb * (n-k+1);
        current_comb = div_mod(current_comb,k,MOD);

        CombNPow[k][0] = pow_mod(current_comb,m/n,MOD);
        CombNPow[k][1] = (CombNPow[k][0] * current_comb) % MOD;
    }
}

int main()
{
    cin>>N>>M>>P;

    compute_comb(N,M);

    P = min(P,N*N - P);

    dp[0][0] = 1;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            int comb = CombNPow[j][M % N >= i];

            for(int k = 0; k + j <= P; k++)
            {
                dp[i][j + k] += (ll)(dp[i - 1][k]) * comb % MOD;
                dp[i][j + k] %= MOD;
            }
        }
    }

    cout<<dp[N][P];
    return 0;
}
