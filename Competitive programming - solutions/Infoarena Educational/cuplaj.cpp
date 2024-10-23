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
string TASK("cuplaj");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9;
const int Inf = 0x3f3f3f3f;
bool test_case = false;

int n, m, e, l[N], r[N];
vvi G(N);

bitset<N> v;
bool DoMatch(int x)
{
    if(v[x])return false;
    v[x] = true;

    for(auto y : G[x])
        if(!l[y])
    {
        r[x] = y;
        l[y] = x;
        return true;
    }

    for(auto y : G[x])
        if(DoMatch(l[y]))
    {
        r[x] = y;
        l[y] = x;
        return true;
    }

    return false;
}

void solve()
{
    cin >> n >> m >> e;

    int x, y;
    FOR(i, 1, e)
    {
        cin >> x >> y;
        G[x].pb(y);
    }

    int mat = 0;
    bool found = true;
    while(found)
    {
        found = false;
        v.reset();

        FOR(i, 1, n)
            if(!r[i] && DoMatch(i))
            {
                mat ++;
                found = true;
            }
    }

    cout << mat << '\n';
    FOR(i, 1, n)
        if(r[i])
            cout << i << ' ' << r[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    if(test_case)cin >> t;
    while(t --)
        solve();
    return 0;
}