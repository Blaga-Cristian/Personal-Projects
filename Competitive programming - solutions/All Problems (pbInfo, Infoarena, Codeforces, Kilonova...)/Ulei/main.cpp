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
#define double long double
using namespace std;
const string TASK("ulei");
ifstream fin(TASK + ".in");
ofstream fout(TASK  + ".out");
//#define cin fin
//#define cout fout

const int N = 15009;

int n, m;

struct muchie
{
    int y, t, i;

    muchie(int y = 0, int t = 0, int i = 0) : y(y), t(t), i(i) {}

    bool operator < (muchie const& oth) const noexcept
    {
        return t < oth.t;
    }
};
vector<multiset<muchie>> G(N);

vector<int> stk;

int tip[N], viz[N];
void Dfs(int x = 1)
{
    cout << x << ' ';
    while(!G[x].empty())
    {
        while(viz[(*G[x].begin()).i])G[x].erase(G[x].begin());
        if(G[x].empty())continue;

        if((*(G[x].begin())).t == tip[x])
        {
            while(!G[x].empty() && viz[(*G[x].rbegin()).i])G[x].erase(prev(G[x].end()));
            if(G[x].empty())continue;

            auto m = *G[x].rbegin();
            G[x].erase(prev(G[x].end()));
            viz[m.i] = true;
            tip[m.y] = m.t;
            Dfs(m.y);
        }
        else
        {
            auto m = *G[x].begin();
            G[x].erase(G[x].begin());
            viz[m.i] = true;
            tip[m.y] = m.t;
            Dfs(m.y);
        }
    }

    stk.pb(x);
}

void solve()
{
    cin >> n >> m;

    int x, y, c;
    FOR(i, 1, m)
    {
        cin >> x >> y >> c;
        G[x].insert({y, c, i});
        G[y].insert({x, c, i});
    }

    tip[1] = -1;
    Dfs();

    for(auto i : stk)cout << i << ' ';
}

int main()
{
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
