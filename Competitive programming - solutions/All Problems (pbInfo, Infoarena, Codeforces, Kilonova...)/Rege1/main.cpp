#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9, Inf = 0x3f3f3f3f3f;

int n, s, x, y, c, vmax;
vector<vector<pair<int, int>>> G;

int cur[N], cnt[N];

void Dfs(int x, int p)
{
    for(auto aux : G[x])
    {
        int y = aux.first, c = aux.second;
        if(y == p)continue;

        Dfs(y, x);

        if(cur[y] + c <= vmax)
        {
            cnt[x] += cnt[y];
            cur[x] = min(cur[x], cur[y] + c);
        }
        else
        {
            cnt[x] += cnt[y] + 1;
            cur[x] = min(cur[x], c);
        }
    }
}

int Cnt(int val)
{
    memset(cnt, 0, sizeof(cnt));
    memset(cur, Inf, sizeof(cnt));
    vmax = val;

    Dfs(1, 0);

    return cnt[1];
}

void solve()
{
    cin >> n >> s;

    int st = 0, dr = Inf, mj, poz = -1;

    G = vector<vector<pair<int, int>>>(n + 1);
    for(int i = 1; i < n; ++i)
    {
        cin >> x >> y >> c;
        st = max(st, c);
        G[x].push_back({y, c});
        G[y].push_back({x, c});
    }


    while(st <= dr)
    {
        mj = (st + dr) >> 1;
        if(Cnt(mj) <= s)
        {
            dr = mj - 1;
            poz = mj;
        }
        else
            st = mj + 1;
    }

    cout << poz << '\n';
}


int main()
{
    freopen("rege1.in", "r", stdin);
    freopen("rege1.out", "w", stdout);



    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
