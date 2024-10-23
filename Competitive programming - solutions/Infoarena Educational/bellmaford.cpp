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
string TASK("bellmanford");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9;
const int Inf = 0x3f3f3f3f;
bool test_case = false;

int n, m, d[N];
vpi G[N];
bool inq[N];
int cnt[N];

void solve()
{
    cin >> n >> m;

    int x, y, c;
    FOR(i, 1, m)
    {
        cin >> x >> y >> c;
        G[x].pb({y, c});
    }

    FOR(i, 1, n)d[i] = Inf;
    d[1] = 0;
    queue<int> q;
    q.push(1);
    inq[1] = true;
    cnt[1] ++;

    bool imp = false;
    while(!q.empty() && !imp)
    {
        int x = q.front();
        inq[x] = false;
        q.pop();

        for(auto [y, c] : G[x])
            if(d[y] > d[x] + c)
            {
                d[y] = d[x] + c;

                if(!inq[y])
                {
                    q.push(y);
                    inq[y] = true;
                }

                if(++cnt[y] >= n)
                {
                    imp = true;
                    break;
                }
            }
    }

    if(imp)
    {
        cout << "Ciclu negativ!\n";
        return;
    }

    FOR(i, 2, n)cout << d[i] << ' ';
    cout << '\n';
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