#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 9, Mod = 1e9 + 7;

ll mul(ll a, ll b, int mod)
{
    return (a * b) % mod;
}
int exp(int base, int exp, int mod)
{
    int ret = 1;

    for(; exp; base = mul(base, base, mod), exp >>= 1)
        if(exp % 2)
            ret = mul(ret, base, mod);

    return ret;
}

int main()
{
    int n, a, b, c;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a >> b >> c;
        cout << exp(a, exp(b, c, Mod - 1), Mod) << '\n';
    }
    return 0;
}
