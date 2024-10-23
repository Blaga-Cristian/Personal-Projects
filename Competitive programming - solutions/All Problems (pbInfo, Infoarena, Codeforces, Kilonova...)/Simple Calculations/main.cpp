#include <bits/stdc++.h>
#define int long long
//#define ll long long
using namespace std;
const int N = 1e7 + 9, Mod = 1e9 + 7;

bool is_composite[N];
vector<int> primes;
int fact[N];

void Precalc()
{
    is_composite[0] = is_composite[1] = true;
    for(int i = 2; i < N; ++i)
    {
        if(!is_composite[i])primes.push_back(i);

        for(int j = 0; j < primes.size() && i * primes[j] < N; ++j)
        {
            is_composite[i * primes[j]] = true;

            if(i % primes[j])break;
        }
    }

    fact[1] = 1;
    for(int i = 2; i < N; ++i)fact[i] = (fact[i - 1] * i) % Mod;
}

int get_phi(int n)
{
    int res = 1;
    for(int d = 2, exp; n != 1;)
    {
        exp = 1;
        while(n % d == 0)
        {
            n /= d;
            exp *= d;
        }

        if(exp != 1)
            res *= (exp - exp / d);

        if(d * d > n)d = n;
        else ++ d;
    }

    return res;
}

int PtLg(int base, int exp)
{
    int res = 1;
    for(; exp; exp >>= 1, base = 1LL * base * base % Mod)
        if(exp & 1)
            res = 1LL * res * base % Mod;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Precalc();

    int t, n;
    cin >> t;
    while(t --)
    {
        cin >> n;

        int phi = get_phi(n), nr = distance(primes.begin(),
                                        lower_bound(primes.begin(), primes.end(), n + 1));

        int exp = max(0LL, nr - phi);
        cout << PtLg(phi, fact[exp]) << '\n';
    }
    return 0;
}
