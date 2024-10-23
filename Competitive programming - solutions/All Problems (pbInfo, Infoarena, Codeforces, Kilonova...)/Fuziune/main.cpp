#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
using namespace std;
const string TASK("fuziune");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e6 + 9, Mod = 1e9 + 7;

int n, q, a[N];
int prod[N], inv[N];

pii Inverse(int a, int b)
{
    if(b == 0)return {1, 0};

    pii r = Inverse(b, a % b);
    return {r.ss, r.ff - (a / b) * r.ss};
}

int PtLg(int base, int exp)
{
    int ret = 1;
    for(; exp; exp >>= 1, base = 1LL * base * base % Mod)
        if(exp & 1)
            ret = 1LL * ret * base % Mod;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n)cin >> a[i], ++a[i];

    prod[0] = 1;
    FOR(i, 1, n)prod[i] = (1LL * prod[i - 1] * a[i]) % Mod;

    inv[n] = PtLg(prod[n], Mod - 2);
    FORR(i, n - 1, 0)inv[i] = (1LL * inv[i + 1] * a[i + 1]) % Mod;

    int l, r;
    FOR(i, 1, q)
    {
        cin >> l >> r;
        cout << (1LL * prod[r] * inv[l - 1] % Mod - 1 + Mod) % Mod << '\n';
    }
    return 0;
}
