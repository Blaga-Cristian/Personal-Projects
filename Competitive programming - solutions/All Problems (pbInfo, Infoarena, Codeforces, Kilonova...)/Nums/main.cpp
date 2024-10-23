#include <bits/stdc++.h>
//#include <bits/extc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vpi vector<pii>
#define vvpi vector<vpi>
#define ll long long
#define double long double
//#define int long long
using namespace std;
//using namespace __gnu_pbds;

const string TASK("poligon");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout
const int N = 2009, Inf = 0x3f3f3f3f;

int n, prv[N], nxt[N], deg[N];
int p;
double x[N], y[N], d[N][N], dp[N];
int t[N];
bool viz[N];
vvi G(N);

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve()
{
    cin >> n;
    FOR(i, 1, n)cin >> x[i] >> y[i];


    FOR(i, 1, n)viz[i] = false, G[i].clear();


    FOR(i, 1, n)
        FOR(j, 1, n)
            d[i][j] = dist(x[i], y[i], x[j], y[j]);


    FOR(i, 1, n)dp[i] = d[1][i], t[i] = 1;
    dp[1] = 0;
    viz[1] = true;

    double cst = 0;
    FOR(i, 2, n)
    {
        int ind = - 1;
        FOR(j, 1, n)
            if(!viz[j] && (ind == -1 || dp[ind] > dp[j]))
                ind = j;

        cst += dp[ind];
        viz[ind] = true;

        G[ind].pb(t[ind]);
        G[t[ind]].pb(ind);

        FOR(j, 1, n)
            if(!viz[j] && dp[j] > d[ind][j])
            {
                dp[j] = d[ind][j];
                t[j] = ind;
            }
    }

    if(p == 1)
    {
        cout << cst << '\n';
        return;
    }

    FOR(i, 1, n)
    {
        viz[i] = false;
        prv[i] = i - 1;
        nxt[i] = i + 1;
        deg[i] = G[i].size();
    }
    prv[1] = n;
    nxt[n] = 1;


    FOR(phase, 2, n)
        FOR(i, 1, n)
            if(deg[i] == 1 && !viz[i])
            {
                int nod = -1;
                for(auto x : G[i])
                    if(viz[x] == false)
                {
                    nod = x;
                    break;
                }

                if(nod == prv[i] || nod == nxt[i])
                {
                    cout << i << ' ' << nod << '\n';
                    viz[i] = true;
                    deg[nod] --;
                    prv[nxt[i]] = prv[i], nxt[prv[i]] = nxt[i];
                }
            }

}

signed main()
{
    cin >> p;
    int t = 1;
    cin >> t;
    cout << fixed << setprecision(12);
    while(t --)
        solve();
    return 0;
}
