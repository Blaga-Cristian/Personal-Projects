#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 1e5 + 9;
const ll Inf = LLONG_MAX;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;



int n, m, a, b, c;
vector<ll> d;
VVPI G;

void Dijkstra()
{
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair< ll , int > > > q;
    q.push({0, 1});
    d[1] = 0;

    while(!q.empty())
    {
        ll dx = q.top().F;
        int x = q.top().S;
        q.pop();

        if(dx > d[x])continue;

        for(auto i : G[x])
        {
            int y = i.F,
            w = i.S;

            if(d[y] > d[x] + w)
            {
                d[y] = d[x] + w;
                q.push({d[y], y});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    G = VVPI(n + 1);
    d = vector<ll>(n + 1, Inf);

    while(m --)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    Dijkstra();

    for(int i = 1; i <= n; ++i)
        cout << d[i] << ' ';
    return 0;
}
