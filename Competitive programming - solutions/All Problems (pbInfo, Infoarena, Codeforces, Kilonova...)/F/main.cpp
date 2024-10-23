#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

//const string TASK("file");
//ifstream fin(TASK + ".in");
//ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout

const ll N = 2009;
const ll Inf = LLONG_MAX >> 2;

int bst[100];
char s[100][100];
bool v[100][100];
int ind = 0, n, m;

bool ok(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !v[x][y]);
}

vector<vector<pii>> patt = {
{{0, 0}, {1, 0}, {2, 0}},
{{0, 0}, {1, 0}, {2, 0}},
{{0, 0}, {0, 1}, {0, 2}},
{{0, 0}, {0, 1}, {0, 2}},
{{0, 0}, {0, 1}, {1, 1}},
{{0, 0}, {0, 1}, {1, 0}},
{{0, 0}, {1, 0}, {1, 1}},
{{0, 0}, {1, -1}, {1, 0}},///8
{{0, 0}, {0, 1}, {1, 1}}, ///9
{{0, 0}, {0, 1}, {1, 0}}, ///10
{{0, 0}, {1, 0}, {1, 1}}, ///11
{{0, 0}, {1, -1}, {1, 0}} ///12
};

vector<vector<char>> mat = {
{'W', 'I', 'N'},
{'N', 'I', 'W'},
{'W', 'I', 'N'},
{'N', 'I', 'W'},
{'W', 'I', 'N'},
{'I', 'W', 'N'},
{'W', 'I', 'N'},
{'N', 'W', 'I'},
{'N', 'I', 'W'},
{'I', 'N', 'W'},
{'N', 'I', 'W'},
{'W', 'N', 'I'}
};

int ans = 0;
void Back(int x, int y, int cur)
{
//    if(x >= 3)bst[x - 3] = max(bst[x - 3], cur);
//    if(cur < bst[x])return;

    if(x == -1 && y == m - 1)
    {
        ans = max(ans, cur);
        return;
    }

    bool wnt = false;

    if(v[x][y])return;

    for(int i = 0; i < patt.size(); ++i)
    {
        if(ok(x + patt[i][0].ff, y + patt[i][0].ss) &&
            ok(x + patt[i][1].ff, y + patt[i][1].ss) &&
            ok(x + patt[i][2].ff, y + patt[i][2].ss) &&
            s[x + patt[i][0].ff][y + patt[i][0].ss] == mat[i][0] &&
            s[x + patt[i][1].ff][y + patt[i][1].ss] == mat[i][1] &&
            s[x + patt[i][2].ff][y + patt[i][2].ss] == mat[i][2])
        {
            v[x + patt[i][0].ff][y + patt[i][0].ss] = true;
            v[x + patt[i][1].ff][y + patt[i][1].ss] = true;
            v[x + patt[i][2].ff][y + patt[i][2].ss] = true;

            if(y == 0)Back(x - 1, m - 1, cur + 1);
            else Back(x, y - 1, cur + 1);

            if(i >= 7)wnt = true;

            v[x + patt[i][0].ff][y + patt[i][0].ss] = false;
            v[x + patt[i][1].ff][y + patt[i][1].ss] = false;
            v[x + patt[i][2].ff][y + patt[i][2].ss] = false;
        }
    }

    if(!wnt)
    {
        if(y == 0)Back(x - 1, m - 1, cur);
        else Back(x, y - 1, cur);
    }
}

void Solve()
{
    n = ind;
    m = strlen(s[0]);

    FOR(i, 0, 40)bst[i] = 0;

    ans = 0;
    Back(n - 1, m - 1, 0);

    cout << ans << '\n';
}

signed main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);

    ind = 0;
    while(!cin.eof())
    {
        cin.getline(s[ind], 100);

        if(strlen(s[ind]) == 0 || cin.eof())
        {
            Solve();

            ind = 0;
            continue;
        }

        ind ++;
    }

    return 0;
}
