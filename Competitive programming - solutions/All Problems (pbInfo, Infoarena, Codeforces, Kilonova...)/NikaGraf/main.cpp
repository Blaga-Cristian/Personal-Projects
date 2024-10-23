#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
using namespace std;
const string TASK("rafaela");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout

const int N = 2e5 + 9, M = 2e5 + 9, Inf = 0x3f3f3f3f, Mod = 1e9 + 7;

int n, q, in[N], out[N], idx, cst[N];

int aib[2 * N];
void Update(int p, int v)
{
    for(; p <= 2 * n; p += p & -p)
        aib[p] += v;
}
int Query(int p)
{
    int ret = 0;
    for(; p; p -= p & -p)
        ret += aib[p];
    return ret;
}


void Dfs(int x, int p)
{
    in[x] = ++idx;
    Update(in[x], cst[x]);

    for(auto [y, c] : G[x])
    {
        if(y == p)continue;

        cst[y] = c;

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> n >> q;

    int x, y, c;
    FOR(i, 2, n)
    {
        cin >> x >> y >> c;
        G[x].pb({y, c});
        G[y].pb({x, c});
    }

    Dfs();

    cin >> x >> y >> c;///muchia care inchide
    return 0;
}
