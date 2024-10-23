#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long

using namespace std;
const string TASK("scorpion");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 3e5 + 9, Mod = 1e9 + 7;

int n, c;
vvi G(N);

int d[N];
void Dfs(int x = 1, int p = 0)
{
    for(auto y : G[x])
        if(y != p)
        {
            d[y] = d[x] + 1;
            Dfs(y, x);
        }
}

int fact[N], invfact[N];

pii Inverse(int x, int y)
{
    if(y == 0)return {1, 0};

    pii r = Inverse(y, x % y);
    return {r.ss, r.ff - (x / y) * r.ss};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> c;

    int x, y;
    FOR(i, 2, n)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    if(c == 1)
    {
        Dfs();

        ll ans = 0;
        FOR(i, 1, n)
            if(G[i].size() == 1 && i != 1)
                ans += d[i];

        cout << ans << '\n';
    }
    else if(c == 2)
    {
        int nr_muchii = n - 1;
        cout << 1LL * (nr_muchii / 2 + 1) * (nr_muchii - nr_muchii / 2) << '\n';
    }
    else if(c == 3)
    {
        fact[0] = 1;
        FOR(i, 1, n)fact[i] = (1LL * i * fact[i - 1]) % Mod;

        invfact[n] = Inverse(fact[n], Mod).ff % Mod;
        if(invfact[n] < 0)invfact[n] += Mod;
        FORR(i, n - 1, 0)invfact[i] = (1LL * (i + 1) * invfact[i + 1]) % Mod;


        auto Arng = [](int n, int k) -> int
        {
            if(n < k)return 0;
            return 1LL * fact[n] * invfact[n - k] % Mod;
        };

        if(n % 2 == 0)cout << Arng(n - 1, n / 2 - 1) << '\n';
        else cout << (Arng(n - 1, n / 2) + Arng(n - 1, n / 2 - 1)) % Mod << '\n';
    }

    return 0;
}
