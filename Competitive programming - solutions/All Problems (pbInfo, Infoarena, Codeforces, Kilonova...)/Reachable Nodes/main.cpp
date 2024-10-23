#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VB vector<bool>
#define VVP vector<VP>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll


using namespace std;
const int N = 5e4 + 9;

int n, m, in[N], cnt, sir[N];
VVI G(N), GI(N);
bitset<N> bs[N];
bool viz[N];

void Dfs(int x)
{
    viz[x] = true;
    for(auto y : G[x])
        if(!viz[y])
            Dfs(y);

    ++cnt;
    sir[n - cnt + 1] = x;
}
void SortTop()
{
    FOR(i, 1, n)
        if(!in[i])
            Dfs(i);
}

int main()
{
    cin >> n >> m;
    FOR(i, 1, n)bs[i].set(i);
    int a, b;
    FOR(i, 1, m)
    {
        cin >> a >> b;
        G[a].pb(b);
        GI[b].pb(a);
        in[b] ++;
    }

    SortTop();

    FORR(i, n, 1)
    {
        int x = sir[i];
        for(auto y : GI[x])
            bs[y] |= bs[x];
    }

    FOR(i, 1, n)cout << bs[i].count() << ' ';
    return 0;
}
