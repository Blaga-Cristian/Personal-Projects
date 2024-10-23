#include <bits/stdc++.h>
#define PI pair<int,int>
#define F first
#define S second
#define ll long long
using namespace std;
const int N = 509, Inf = 1e9 + 9;
int n, m, a, b, c, t[N];
ll C[N][N];
vector<vector<int>> G;
vector<PI> muchii;
queue<int> q;
bitset<N> v;


bool Bfs(int source, int sink)
{
    q = queue<int>();
    v.reset();
    v[source] = true;
    q.push(source);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(x == sink)break;

        for(auto y : G[x])
            if(C[x][y] > 0 && !v[y])
            {
                v[y] = true;
                t[y] = x;
                q.push(y);
            }
    }

    return v[sink];
}

ll MaxFlow(int source, int sink)
{
    ll maxflow = 0, flow;
    for(;Bfs(source, sink);)
        for(auto x : G[sink])
            if(C[x][sink] > 0)
            {
                flow = 1;
                for(int i = sink; i != source; i = t[i])
                    flow = min(flow, C[t[i]][i]);

                if(flow == 0)continue;

                cout << x << ' ' << sink << '\n';

                for(int i = sink; i != source; i = t[i])
                {
                    C[t[i]][i] -= flow;
                    C[i][t[i]] += flow;
                }

                maxflow += flow;
            }

    return maxflow;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin >> n >> m;
    G = vector<vector<int>>(n + 1);
    while(m --)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        C[a][b] = C[b][a] = 1;
    }

    cout << MaxFlow(1, n) << '\n';
    for(auto i : muchii)
        cout << i.F << ' ' << i.S << '\n';
    return 0;
}
