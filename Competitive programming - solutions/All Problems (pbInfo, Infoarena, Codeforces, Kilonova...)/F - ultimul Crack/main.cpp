#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6 + 9;
int Mod = 998244353;
const bool test_cases = false;

int n, v[N];

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * y) % Mod;
}

ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}

ll cst(int i, int j)
{
    return add(PtLg(v[i], v[j]), add(mul(v[i], v[j]), PtLg(v[j], v[i])));
}

struct edge
{
    int x, y, c;
};
vector<edge> edges;

int dsu[N], sz[N];
int find(int x){return dsu[x] == 0 ? x : dsu[x] = find(dsu[x]);}
void unite(int x, int y)
{
    if(sz[x] > sz[y])swap(x, y);

    dsu[x] = y;
    sz[y] += sz[x] + 1;
}


void solve()
{
    cin >> n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

//    Precalc();

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
