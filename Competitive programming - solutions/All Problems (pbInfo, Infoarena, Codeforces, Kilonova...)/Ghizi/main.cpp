#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back
#define vpi vector<pii>
#define vvpi vector<vpi>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

using namespace std;
const string TASK("ghizi");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
const int N = 5009;

int n, k;
vvpi G(101);

struct edge
{
    int from, to, capacity, flow;

    edge() : from(0), to(0), capacity(0), flow(0) {}
    edge(int from, int to, int capacity, int flow = 0) : from(from), to(to), capacity(capacity), flow(flow) {}
};
vector<edge> edges;

void insert_edge(int x, int y)
{
    G[x].pb({y, edges.size()});
    edges.pb({x, y, 1, 0});
    G[y].pb({x, edges.size()});
    edges.pb({y, x, 0, 0});
}

bitset<101> viz;
queue<int> q;
int t[101];

void Bfs(int source, int sink)
{
    viz.reset();
    q.push(source);
    t[source] = -1;
    viz[source] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto [y, id] : G[x])
            if(!viz[y] && edges[id].capacity - edges[id].flow > 0)
            {
                viz[y] = true;
                t[y] = id;
                q.push(y);
            }
    }
}

void Augment(int source, int sink)
{
    for(int i = t[sink]; i != -1; i = t[edges[i].from])
    {
        edges[i].flow ++;
        edges[i ^ 1].flow --;
    }
}

int main()
{
    cin >> n >> k;

    int x, y;
    FOR(i, 1, n)
    {
        cin >> x >> y;
        insert_edge(x, y);
    }

    FOR(i, 1, k)
    {
        Bfs(0, 100);
        Augment(0, 100);
    }

    vi ans;
    for(int i = 0; i < edges.size(); ++i)
        if(edges[i].flow == 1)
            ans.pb(i / 2 + 1);

    cout << ans.size() << '\n';
    for(auto i : ans)cout << i << ' ';
    return 0;
}
