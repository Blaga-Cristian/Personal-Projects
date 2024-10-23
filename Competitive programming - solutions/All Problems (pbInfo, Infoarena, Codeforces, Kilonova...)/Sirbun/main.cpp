#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back

using namespace std;
const string TASK("sirbun");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout
const int N = 1e5 + 9, M = 2e5 + 9;

int n, m, a[N];
vector<vector<pair<pii, int>>> G(N);
ll ans;

struct muchie
{
    int x, y, z;
};
vector<muchie> muchii(M);

int low[N], lvl[N], idx, w[N];
bool critical[N];

void Dfs(int x = 1, int p = 0)
{
    w[x] = 1;
    low[x] = lvl[x] = ++idx;

    for(auto aux : G[x])
    {
        int y = aux.ff.ff, z = aux.ff.ss, i = aux.ss;
        if(y == p)continue;

        if(!lvl[y])
        {
            Dfs(y, x);
            low[x] = min(low[x], low[y]);
            w[x] += w[y];

            if(lvl[x] < low[y])
                critical[i] = true;
        }
        else low[x] = min(low[x], lvl[y]);
    }
}

bool viz[N];
int cnt[N];
void Get_Edges(int x, vector<muchie>& vec)
{
    viz[x] = true;
    for(auto aux : G[x])
    {
        int y = aux.ff.ff, z = aux.ff.ss, i = aux.ss;
        if(viz[y] || critical[i])continue;
        vec.pb({x, y, z});
        Get_Edges(y, vec);
    }
}
void Solve(int x)
{
    vector<muchie> vec;
    Get_Edges(x, vec);
    int id = -1;
    for(int i = 0; i < G[x].size(); ++i)
    {
        int y = G[x][i].ff.ff, z = G[x][i].ff.ss, ind = G[x][i].ss;
        if(!critical[ind] && (id == -1 || w[y] < w[G[x][id].ff.ff]))id = i;
    }
    vec.pb({G[x][id].ff.ff, x, G[x][id].ff.ss});

    for(auto i : vec)
        if(lvl[i.x] == low[i.x])cnt[i.x] = n - w[i.y];
        else
        {
            cnt[i.x] = w[i.x];
            if(w[i.x] > w[i.y])cnt[i.x] -= w[i.y];
        }

    ll sum = 0, cnt_tot = 0;
    for(int i = 1; i < vec.size(); ++i)
    {
        cnt_tot += cnt[vec[i].x];
        sum += cnt_tot * cnt[vec[i].y] * vec[i].z;
    }

    cout << sum << ' ' << cnt_tot << '\n';

    ll best = sum;
    for(int i = 1; i < vec.size(); ++i)
    {
        cnt_tot -= cnt[vec[i].x];
        cnt_tot += cnt[vec[i - 1].x];
        sum -= cnt[vec[i].x] * cnt[vec[i].y] * vec[i].z;
        sum += cnt_tot * cnt[vec[i].x] * vec[i - 1].z;

        cout << sum << ' ' << cnt_tot << ' ' << vec[i].x << ' ' << vec[i].y << '\n';
        best = min(best, sum);
    }

    ans += best;
}

int main()
{
    cin >> n >> m;

    int x, y, z;
    FOR(i, 1, m)
    {
        cin >> x >> y >> z;
        G[x].pb({{y, z}, i});
        G[y].pb({{x, z}, i});
        muchii[i] = {x, y, z};
    }

    Dfs();


    FOR(i, 1, m)
    {
        if(critical[i])
        {
            int weight = min(w[muchii[i].x], w[muchii[i].y]);
            ans += weight * (n - weight) * muchii[i].z;
        }
        else
        {
            if(!viz[muchii[i].x])Solve(muchii[i].x);
            if(!viz[muchii[i].y])Solve(muchii[i].y);
        }
    }

    cout << ans << '\n';
    return 0;
}
