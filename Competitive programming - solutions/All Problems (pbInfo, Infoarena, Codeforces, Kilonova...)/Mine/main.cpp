#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VPI vector<PI>
#define VVPI vector<VPI>
using namespace std;
const int N = 1e4 + 9, W = 1e6 + 9, Inf = 0x3f3f3f3f;

int n, m, a, b, c, w, energie;
VVPI G;
priority_queue<PI, vector<PI>, greater<PI>> q;
int d[N];

int main()
{
    freopen("mine.in", "r", stdin);
    freopen("mine.out", "w", stdout);

    cin >> n >> m;
    G = VVPI(n + 1);
    while(m --)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    fill(d + 1, d + n + 1, Inf);
    cin >> w;
    for(int i = 1; i <= w; ++i)
    {
        cin >> energie;

        while(!q.empty() && q.top().F <= energie)
        {
            int dx = q.top().F, x = q.top().S;
            q.pop();

            if(dx > d[x])continue;

            for(auto aux : G[x])
            {

            }
        }
    }

    cout << d[n] - 1;
    return 0;
}
