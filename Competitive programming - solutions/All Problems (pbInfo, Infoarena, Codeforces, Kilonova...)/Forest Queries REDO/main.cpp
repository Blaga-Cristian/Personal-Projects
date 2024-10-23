#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long

using namespace std;
const string TASK("scorpion");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout

const int N = 1009, Mod = 1e9 + 7, B = 60;

int n, q, a[N][N], aib[N][N];

void Update(int x, int y, int v)
{
    for(int i = x; i <= n; i += i & -i)
        for(int j = y; j <= n; j += j & -j)
            aib[i][j] += v;
}
int Query(int x, int y)
{
    int ret = 0;
    for(int i = x; i; i -= i & -i)
        for(int j = y; j; j -= j & -j)
            ret += aib[i][j];
    return ret;
}
int Query(int x1, int y1, int x2, int y2)
{
    return Query(x2, y2) - Query(x1 - 1, y2) - Query(x2, y1 - 1) + Query(x1 - 1, y1 - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    char c;
    FOR(i, 1, n)FOR(j, 1, n)
    {
        cin >> c;
        if(c == '*')a[i][j] = 1;
    }

    FOR(i, 1, n)FOR(j, 1, n)aib[i][j] = a[i][j] + aib[i - 1][j] + aib[i][j - 1] - aib[i - 1][j - 1];
    FORR(i, n, 1)FORR(j, n, 1)aib[i][j] = aib[i][j] - aib[i & (i - 1)][j] - aib[i][j & (j - 1)] + aib[i & (i - 1)][j & (j - 1)];

    int t, x1, y1, x2, y2, x, y, v;
    FOR(i, 1, q)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> x >> y;
            Update(x, y, -a[x][y]);
            Update(x, y, a[x][y] = 1 - a[x][y]);
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << Query(x1, y1, x2, y2) << '\n';
        }
    }
    return 0;
}
