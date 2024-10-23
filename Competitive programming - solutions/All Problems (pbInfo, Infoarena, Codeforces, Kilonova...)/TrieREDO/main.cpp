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

//#define int long long
using namespace std;
const string TASK("bellmanford");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 50009, Inf = 0x3f3f3f3f;

int n, m, d[N];
vvpi G(N);

bool inQ[N];
int cntQ[N];
bool CICLU_NEGATIV;

void BellMan()
{
    queue<int> q;q.push(1);
    inQ[1] = true;
    for(int i = 1; i <= n; ++i)d[i] = Inf;
    d[1] = 0;

    while(!q.empty())
    {
        int x = q.front();
        inQ[x] = false;
        q.pop();

        for(auto [y, c] : G[x])
            if(d[y] > d[x] + c)
            {
                d[y] = d[x] + c;
                if(!inQ[y])
                {
                    q.push(y);
                    inQ[y] = true;
                    ++ cntQ[y];
                    if(cntQ[y] == n)
                    {
                        CICLU_NEGATIV = true;
                        return;
                    }
                }
            }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    int x, y, c;
    for(int i = 1; i <= m; ++i)
    {
        cin >> x >> y >> c;
        G[x].pb({y, c});
//        G[y].pb({x, c});
    }

    BellMan();

    if(CICLU_NEGATIV)
    {
        cout << "Ciclu negativ!";
        return 0;
    }

    for(int i = 2; i <= n; ++i)
        cout << d[i] << ' ';
    return 0;
}
