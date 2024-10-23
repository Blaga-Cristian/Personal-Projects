#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long

using namespace std;
const string TASK("cowfood");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int K = 31, S = 10009, N = 21, Mod = 3210121;

int k, s, n, a[N][K], tmp[K];

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    while(x < 0)x += Mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a * b) % Mod;
}
ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}

int fact[S + K], invfact[S + K], sp[S + K];
int comb(int n, int k)
{
    if(n < k)return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}
void Precalc()
{
    fact[0] = 1;
    FOR(i, 1, S + K - 1)fact[i] = mul(i, fact[i - 1]);

    invfact[S + K - 1] = PtLg(fact[S + K - 1], Mod - 2);
    FORR(i, S + K - 2, 0)invfact[i] = mul(i + 1, invfact[i + 1]);

    sp[0] = 1;
    FOR(i, 1, S + K - 1)sp[i] = add(sp[i - 1], comb(i + k - 1, k - 1));///stars and bars
}

int reu = 0, cur[K];
int calcs()
{
    int sum = s;
    FOR(i, 1, k)sum -= cur[i];

    if(sum < 0)return 0;
    return sp[sum];
}

void Back(int x, int mask)
{
    if(x == n)
    {
        if(__builtin_popcount(mask) % 2 == 1)reu = add(reu, calcs());
        else reu = add(reu, -calcs());
        return;
    }

    int tmp[K];
    FOR(i, 1, k)tmp[i] = cur[i];

    FOR(i, 1, k)cur[i] = max(cur[i], a[x + 1][i]);

    Back(x + 1, mask | (1 << x));

    FOR(i, 1, k)cur[i] = tmp[i];

    Back(x + 1, mask);
}

int main()
{
    cin >> k >> s >> n;
    FOR(i, 1, n)FOR(j, 1, k)cin >> a[i][j];


    Precalc();
    int total = add( -mul(s, k), -1);

    Back(0, 0);

    cout << add(total, - reu) << '\n';
    return 0;
}
