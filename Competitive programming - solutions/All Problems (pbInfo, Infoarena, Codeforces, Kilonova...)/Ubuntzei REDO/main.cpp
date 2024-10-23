#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define eb emplace_back
using namespace std;
const string TASK("ubuntzei");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 2009, K = 16;
const int Inf = 0x3f3f3f3f;

int n, m, k, d[K][N], d1[N];
int dp[1 << K][K];
vi ubun;
vvpi G(N);

void Dijkstra(int nod, int* d)
{
    for(int i = 1; i <= n; ++i)d[i] = Inf;
    d[nod] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, nod});

    while(!q.empty())
    {
        int dx = q.top().ff, x = q.top().ss;
        q.pop();

        if(dx > d[x])continue;

        for(auto aux : G[x])
        {
            int y = aux.ff, c = aux.ss;

            if(d[y] > d[x] + c)
                q.push({d[y] = d[x] + c, y});
        }
    }
}

int main()
{
    cin >> n >> m;

    cin >> k;

    ubun.resize(k);
    for(int i = 0; i < k; ++i)cin >> ubun[i];

    int x, y, z;
    for(int i = 1; i <= m; ++i)
    {
        cin >> x >> y >> z;
        G[x].eb(y, z);
        G[y].eb(x, z);
    }

    Dijkstra(1, d1);
    for(int i = 0; i < k; ++i)Dijkstra(ubun[i], d[i]);


    if(k == 0)
    {
        cout << d1[n] << '\n';
        return 0;
    }

    for(int i = 0; i < (1 << k); ++i)
        for(int j = 0; j < k; ++j)
            dp[i][j] = Inf;

    for(int i = 0; i < k; ++i)dp[1 << i][i] = d1[ubun[i]];

    for(int s = 0; s < (1 << k); ++s)
        for(int i = 0; i < k; ++i)
            if(s & (1 << i))
            {
                for(int j = 0; j < k; ++j)
                    if(!(s & (1 << j)))
                        dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + d[i][ubun[j]]);
            }

    int ans = Inf;
    for(int i = 0; i < k; ++i)
        ans = min(ans, dp[(1 << k) - 1][i] + d[i][n]);

    cout << ans << '\n';
    return 0;
}
