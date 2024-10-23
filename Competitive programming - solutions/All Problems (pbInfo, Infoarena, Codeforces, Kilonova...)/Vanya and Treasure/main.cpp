#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define ff first
#define ss second
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
using namespace std;
const int N = 305, di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1}, Inf = 0x3f3f3f3f;


int n, m, p, a[N][N], d[N][N], b[N][N];
vpi pos[N * N];
vpi q[4 * N];

bool inmat(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main()
{
    cin >> n >> m >> p;

    const int BLOCK = sqrt(n * m);

    FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];

    FOR(i, 1, n)FOR(j, 1, m)pos[a[i][j]].pb({i, j});

    FOR(i, 1, n)FOR(j, 1, m)d[i][j] = Inf;
    FOR(i, 1, n)FOR(j, 1, m)if(a[i][j] == 1)d[i][j] = abs(1 - i) + abs(1 - j);

    FOR(v, 1, p - 1)
        if(pos[v].size() <= BLOCK)
        {
            for(auto [x2, y2] : pos[v + 1])
                for(auto [x1, y1] : pos[v])
                    d[x2][y2] = min(d[x2][y2], d[x1][y1] + abs(x1 - x2) + abs(y1 - y2));
        }
        else
        {
            int mn = Inf;

            FOR(i, 1, n)FOR(j, 1, m)
                if(a[i][j] == v)mn = min(mn, d[i][j]);
                else b[i][j] = Inf;

            FOR(i, 1, n)FOR(j, 1, m)
                if(a[i][j] == v)
                {
                    b[i][j] = d[i][j] - mn;
                    q[b[i][j]].pb({i, j});
                }

            FOR(i, 0, 2 * (n + m))
            {
                while(!q[i].empty())
                {
                    auto [x, y] = q[i].back();
                    q[i].pop_back();

                    FOR(k, 0, 3)
                    {
                        int nx = x + di[k], ny = y + dj[k];
                        if(inmat(nx, ny) && b[nx][ny] > b[x][y] + 1)
                        {
                            b[nx][ny] = b[x][y] + 1;
                            q[b[nx][ny]].pb({nx, ny});
                        }
                    }
                }
            }

            for(auto [x, y] : pos[v + 1])
                d[x][y] = b[x][y] + mn;
        }

    auto [x, y] = pos[p][0];
    cout << d[x][y] << '\n';

//    FOR(i, 1, n)FOR(j, 1, m)cout << d[i][j] << " \n"[j == m];
    return 0;
}
