#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define vvvpi vector<vvpi>
#define pb push_back
#define eb emplace_back
#define ll long long
using namespace std;
const int N = 5009;
const int Mod = 1e9 + 7;
const bool test_cases = false;

const int di[] = {-2, -1, 1, 2, 2, 1, -1, -2},
          dj[] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;
pii L[N][N], R[N][N];
char s[N][N];
bool v[N][N];
vpi vert;
vvvpi G;

bool ok(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m && s[i][j] == '.';
}

bool DoMatch(int i, int j)
{
    if(v[i][j])return false;
    v[i][j] = true;

    for(auto [i2, j2] : G[i][j])
    {
        auto [i1, j1] = R[i2][j2];
        if(!i1)
        {
            L[i][j] = {i2, j2};
            R[i2][j2] = {i, j};
            return true;
        }
    }

    for(auto [i2, j2] : G[i][j])
    {
        auto [i1, j1] = R[i2][j2];
        if(DoMatch(i1, j1))
        {
            L[i][j] = {i2, j2};
            R[i2][j2] = {i, j};
            return true;
        }
    }

    return false;
}

int MaxMatch()
{
    int ret = 0;
    bool found_path = true;

    while(found_path)
    {
        for(auto [i, j] : vert)v[i][j] = false;
        found_path = false;

        for(auto [i, j] : vert)
            if(!L[i][j].ff && DoMatch(i, j))
        {
            ret ++;
            found_path = true;
        }
    }

    return ret;
}


void solve()
{
    cin >> n >> m;
    G = vvvpi(n + 1, vvpi(m + 1));

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> s[i][j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if((i + j) % 2 == 0 && s[i][j] != '#')
            {
                vert.pb({i, j});
                for(int d = 0; d < 8; ++d)
                {
                    int inou = i + di[d], jnou = j + dj[d];
                    if(ok(inou, jnou))G[i][j].pb({inou, jnou});
                }
            }

    int cnt_op = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(s[i][j] == '#')
                cnt_op ++;

    cout << n * m - cnt_op - MaxMatch();
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

//    Ciur();

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
