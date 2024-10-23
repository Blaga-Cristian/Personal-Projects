#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define VP vector<PI>
#define VVP vector<VP>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define ll long long
#define ull unsigned ll

using namespace std;
ifstream fin("evantai.in");
ofstream fout("evantai.out");
const int N = 709, V = 2009, Mod = 30103;

int n, aib[N][V], v[N];

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod) x -= Mod;
    if(x < 0) x += Mod;
    return x;
}

void update(int x, int y, int val)
{
    for(int i = x; i < N; i += i & -i)
        for(int j = y; j < V; j += j & -j)
            aib[i][j] = add(aib[i][j], val);
}
ll query(int x, int y)
{
    ll ret = 0;
    for(int i = x; i; i -= i & -i)
        for(int j = y; j; j -= j & -j)
            ret = add(ret, aib[i][j]);
    return ret;
}

int dp[N][N];

int main()
{
    fin >> n;
    FOR(i, 1, n)fin >> v[i];

    for(int i = n; i >= 1; --i)
        for(int j = n; j > i; --j)
        {
            dp[i][j] = 1 + query(j - 1, v[i] + v[j] - 1);
            update(j, v[i] + v[j], dp[i][j]);
        }

    ll ans = 0;
    FOR(i, 1, n)
        FOR(j, i + 1, n)
            ans = add(ans, dp[i][j]);
    fout << ans;
    return 0;
}
