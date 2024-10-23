#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define fast_in_out ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
using namespace std;
const int N = 2509;
const ll Inf = LLONG_MAX;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;

int n, m, a, b, c;
VVPI G;
vector<ll> d[2];

void Dijkstra()
{
    queue<pair<PI, bool> > q;
    d[0][1] = 0;
    //d[1][1] = 0;
    q.push({{0, 1}, false});

    while(!q.empty())
    {
        int dx = q.front().F.F,
        x = q.front().F.S,
        used = q.front().S;
        q.pop();

        if(dx > d[used][x])continue;

        for(auto i : G[x])
        {
            int y = i.F,
            w = i.S;

            if(!used && d[1][y] > d[0][x] + w / 2)
            {
                d[1][y] = d[0][x] + w / 2;
                q.push({{d[1][y], y}, 1});
            }

            if(d[used][y] > d[used][x] + w)
            {
                d[used][y] = d[used][x] + w;
                q.push({{d[used][y], y}, used});
            }
        }
    }
}

int main()
{
    fast_in_out

    cin >> n >> m;
    G = VVPI(n + 1);
    d[0] = d[1] = vector<ll>(n + 1, Inf);
    while(m --)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    Dijkstra();

    cout << d[1][n];
    return 0;
}
