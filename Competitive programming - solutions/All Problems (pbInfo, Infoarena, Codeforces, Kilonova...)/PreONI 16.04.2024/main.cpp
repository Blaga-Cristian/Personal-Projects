#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vpi vector<pii>
#define vb vector<bool>
#define vvb vector<vb>

using namespace std;
const string TASK("albinuta");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 59, SZ = 15e5 + 9;
const int P = 211, M = 1e9 + 123;

int n, m;
vvi seen;

vvi G(N);
vi sir;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> n >> m;

    int k, lcm = 1;
    FOR(i, 1, n)
    {
        cin >> k;
        lcm = lcm * k / __gcd(lcm, k);
        G[i].resize(k);
        FOR(j, 0, k - 1)cin >> G[i][j];
    }

    seen = vvi(n + 1, vi(lcm + 1));
    int a, b;
    vi ans;
    for(int i = 1, cur = 1; ; ++i)
    {
        if(seen[cur][(i - 1) % lcm])
        {
            a = seen[cur][(i - 1) % lcm];
            b = i - a;
            break;
        }
        seen[cur][(i - 1) % lcm] = i;
        ans.pb(cur);
        cur = G[cur][(i - 1) % G[cur].size()];
    }

    int t;
    FOR(i, 1, m)
    {
        cin >> t;
        if(t <= a + 1)cout << ans[t - 1] << '\n';
        else cout << ans[a + (t - a - 1) % b] << '\n';
    }
    return 0;
}
