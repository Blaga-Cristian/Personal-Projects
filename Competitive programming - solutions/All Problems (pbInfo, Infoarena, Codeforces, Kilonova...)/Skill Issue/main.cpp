#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pb push_back
#define ll long long

#define int long long
using namespace std;
const string TASK("skill-issue");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 2003, K = 5003, Mod = 1e9 + 7, B = 60;///To change

ll n, m, k, q, pt2[N * N];
ll sA, sB;
ll a[N][N], b[N][N];
ll ta[4 * N][4 * N], tb[4 * N][4 * N];

void Build_Y(int nod_x, int x_l, int x_r, int nod_y = 1, int st = 1, int dr = m)
{
    if(st == dr)
    {
        if(x_l == x_r)
        {
            ta[nod_x][nod_y] = a[x_l][st];
            tb[nod_x][nod_y] = b[x_l][st];
        }
        else
        {
            ta[nod_x][nod_y] = ta[nod_x << 1][nod_y] | ta[nod_x << 1 | 1][nod_y];
            tb[nod_x][nod_y] = tb[nod_x << 1][nod_y] | tb[nod_x << 1 | 1][nod_y];
        }

        return;
    }

    int m = (st + dr) >> 1;
    Build_Y(nod_x, x_l, x_r, nod_y << 1, st, m);
    Build_Y(nod_x, x_l, x_r, nod_y << 1 | 1, m + 1, dr);

    if(x_l == x_r)
    {
        ta[nod_x][nod_y] = ta[nod_x][nod_y << 1] | ta[nod_x][nod_y << 1 | 1];
        tb[nod_x][nod_y] = tb[nod_x][nod_y << 1] | tb[nod_x][nod_y << 1 | 1];
    }
    else
    {
        ta[nod_x][nod_y] = ta[nod_x << 1][nod_y] | ta[nod_x << 1 | 1][nod_y];
        tb[nod_x][nod_y] = tb[nod_x << 1][nod_y] | tb[nod_x << 1 | 1][nod_y];
    }
}

void Build_X(int nod_x = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        Build_Y(nod_x, st, dr);
        return;
    }

    int m = (st + dr) >> 1;
    Build_X(nod_x << 1, st, m);
    Build_X(nod_x << 1 | 1, m + 1, dr);

    Build_Y(nod_x, st, dr);
}

void Update_Y(ll t[][4 * N], int nod_x, int x_l, int x_r, int y, ll v, int nod_y = 1, int st = 1, int dr = m)
{
    if(st == dr)
    {
        if(x_l == x_r)t[nod_x][nod_y] = v;
        else t[nod_x][nod_y] = t[nod_x << 1][nod_y] | t[nod_x << 1 | 1][nod_y];
        return;
    }

    int m = (st + dr) >> 1;
    if(y <= m)Update_Y(t, nod_x, x_l, x_r, y, v, nod_y << 1, st, m);
    else Update_Y(t, nod_x, x_l, x_r, y, v, nod_y << 1 | 1, m + 1, dr);

    if(x_l == x_r)t[nod_x][nod_y] = t[nod_x][nod_y << 1] | t[nod_x][nod_y << 1 | 1];
    else t[nod_x][nod_y] = t[nod_x << 1][nod_y] | t[nod_x << 1 | 1][nod_y];
}

void Update_X(ll t[][4 * N], int x, int y, ll v, int nod_x = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        Update_Y(t, nod_x, st, dr, y, v);
        return;
    }

    int m = (st + dr) >> 1;
    if(x <= m)Update_X(t, x, y, v, nod_x << 1, st, m);
    else Update_X(t, x, y, v, nod_x << 1 | 1, m + 1, dr);

    Update_Y(t, nod_x, st, dr, y, v);
}

ll Query_Y(ll t[][4 * N], int nod_x, int y1, int y2, int nod_y = 1, int st = 1, int dr = m)
{
    if(y1 <= st && dr <= y2)return t[nod_x][nod_y];
    int m = (st + dr) >> 1;
    if(y2 <= m)return Query_Y(t, nod_x, y1, y2, nod_y << 1, st, m);
    else if(y1 > m)return Query_Y(t, nod_x, y1, y2, nod_y << 1 | 1, m + 1, dr);
    return Query_Y(t, nod_x, y1, y2, nod_y << 1, st, m) | Query_Y(t, nod_x, y1, y2, nod_y << 1 | 1, m + 1, dr);
}

ll Query_X(ll t[][4 * N], int x1, int y1, int x2, int y2, int nod_x = 1, int st = 1, int dr = n)
{
    if(x1 <= st && dr <= x2)return Query_Y(t, nod_x, y1, y2);
    int m = (st + dr) >> 1;
    if(x2 <= m)return Query_X(t, x1, y1, x2, y2, nod_x << 1, st, m);
    else if(x1 > m)return Query_X(t, x1, y1, x2, y2, nod_x << 1 | 1, m + 1, dr);
    return Query_X(t, x1, y1, x2, y2, nod_x << 1, st, m) | Query_X(t, x1, y1, x2, y2, nod_x << 1 | 1, m + 1, dr);
}

int sl[K], sz;
//int dp[K][K];


vvvi divide(int l, int r)
{
    int ln = (r - l + 1);
    vvvi dp(ln + 2, vvi(2, vi(2)));

    if(l == r)
    {
        if(sl[l] == 1)
        {
            dp[0][0][0] = 1;
            dp[1][0][1] = 1;
        }
        else if(sl[l] == 3)
        {
            dp[1][1][1] = 1;
            dp[2][1][0] = 1;
        }

        return dp;
    }

    int m = (l + r) >> 1;
    auto st = divide(l, m);
    auto dr = divide(m + 1, r);

    FOR(i, 0, (int)st.size() - 1)
        FOR(j, 0, (int)dr.size() - 1)
            FOR(b1, 0, 1)
                FOR(b2, 0, 1)
                {
                    if(i + j - 1 >= 0 && i + j - 1 < ln + 2)
                        dp[i + j - 1][b1][b2] = max(dp[i + j - 1][b1][b2], st[i][b1][1] + dr[j][1][b2]);
                    if(i + j < ln + 2)
                        dp[i + j][b1][b2] = max({dp[i + j][b1][b2], st[i][b1][0] + dr[j][0][b2],
                                            st[i][b1][1] + dr[j][0][b2],
                                            st[i][b1][0] + dr[j][1][b2]});
                }

    return dp;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    FOR(i, 1, n)FOR(j, 1, m)cin >> a[i][j];
    FOR(i, 1, n)FOR(j, 1, m)cin >> b[i][j];

    Build_X();

    pt2[0] = 1;
    FOR(i, 1, n * m + 9)pt2[i] = (2LL * pt2[i - 1]) % Mod;

    cin >> q;

    int t, x1, y1, x2, y2, x3, y3, x4, y4;
    ll v1, v2;
    FOR(i, 0, q - 1)
    {
        cin >> t;
        if(t == 1)
        {
            cin  >> x1 >> y1 >> v1;
            a[x1][y1] = v1;
            Update_X(ta, x1, y1, v1);

            cin  >> x2 >> y2 >> v2;
            b[x2][y2] = v2;
            Update_X(tb, x2, y2, v2);
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cin >> x3 >> y3 >> x4 >> y4;

            if(true)
            {
                sA = 0;
                FOR(l, x1, x2)
                    FOR(c, y1, y2)
                        sA |= a[l][c];
                sA = sA * pt2[1LL * (x2 - x1 + 1) * (y2 - y1 + 1) - 1] % Mod;

                sB = 0;
                FOR(l, x3, x4)
                    FOR(c, y3, y4)
                        sB |= b[l][c];
                sB = sB * pt2[1LL * (x4 - x3 + 1) * (y4 - y3 + 1) - 1] % Mod;

//                cout << sA << ' ' << sB << "  |  ";
            }
            else
            {
                sA = Query_X(ta, x1, y1, x2, y2) % Mod * pt2[1LL * (x2 - x1 + 1) * (y2 - y1 + 1) - 1] % Mod;
                sB = Query_X(tb, x3, y3, x4, y4) % Mod * pt2[1LL * (x4 - x3 + 1) * (y4 - y3 + 1) - 1] % Mod;
            }

//            cout << sA << ' ' << sB << '\n';

            ///1 A, 2 Remiza, 3 B
            if(sA > sB)sl[++ sz] = 1;
            else if(sA == sB)sl[++ sz] = 2;
            else if(sA < sB)sl[++ sz] = 3;
        }
    }


    auto dp = divide(1, sz);
//    FOR(i, 1, sz)
//    {
//        dp[i][0] = dp[i - 1][0] + (sl[i] == 1);
//        FOR(j, 1, k)
//            if(j % 2 == 0)
//                dp[i][j] = max(dp[i - 1][j] + (sl[i] == 1),
//                               dp[i - 1][j - 1] + (sl[i] == 3));
//            else
//                dp[i][j] = max(dp[i - 1][j] + (sl[i] == 3),
//                               dp[i - 1][j - 1] + (sl[i] == 1));
//    }

    int ans = 0;
    FOR(i, 0, min(k, sz + 1))
        FOR(b1, 0, 1)
            FOR(b2, 0, 1)
                ans = max(ans, dp[i][b1][b2]);
    cout << ans << '\n';

    return 0;
}
