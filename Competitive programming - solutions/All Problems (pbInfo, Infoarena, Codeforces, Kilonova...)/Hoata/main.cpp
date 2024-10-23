#include <bits/stdc++.h>

using namespace std;


#define all(x) (x).begin(), (x).end()
#define allg(x) (x).begin(), (x).end(), greater<int>()
using ull = unsigned long long;
using ll =  long long;
using ld = double;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<ld>;
using si = set<int>;
using ssi = set<si>;
using sl = set<ll>;
using ssl = set<sl>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vs = vector<string>;
using vpi = vector<pii>;
using vvpi = vector<vpi>;
using vpl = vector<pll>;
using vvpl = vector<vpl>;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define REP(i, a, b)for(int i = a; i < b; ++i)
#define umap unordered_map
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second
#define ar array

inline void fastio() {
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
}


const string TASK("23-hoata");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
//#define cin fin
//#define cout fout

const int Inf = 0x3f3f3f3f;

struct Edge
{
    int from, to, cost, capacity, flow;
    Edge(int f = 0, int t = 0, int c = 0, int ca = 0, int fl = 0):
        from(f), to(t), cost(c), capacity(ca), flow(fl) {}
};
int encode_node(int room, int weight, int G)
{
    return room * (G + 1) + weight + 2;
}

void BellMan(vvi& graph, vector<Edge>& edges, vi& dbell, vb& inq, int s, int d)
{
    fill(all(dbell), Inf);
    fill(all(inq), false);
    queue<int> q;
    q.push(s);
    dbell[s] = 0;
    inq[s] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        inq[x] = false;

        for(int edge_idx : graph[x])
        {
            auto& e = edges[edge_idx];
            if(e.capacity - e.flow > 0 && dbell[e.to] > dbell[x] + e.cost)
            {
                dbell[e.to] = dbell[x] + e.cost;
                if(!inq[e.to])
                {
                    inq[e.to] = true;
                    q.push(e.to);
                }
            }
        }
    }
}

bool Dijkstra(vvi& graph, vector<Edge>& edges, vi& dbell, vi& dist, vi& t, int s, int d, pii& ret)
{
    fill(all(dist), Inf);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    dist[s] = 0;

    while(!q.empty())
    {
        int dx = q.top().ff, x = q.top().ss;
        q.pop();

        if(dx > dist[x])continue;

        for(int edge_idx : graph[x])
        {
            auto& e = edges[edge_idx];
            if(e.capacity - e.flow > 0 && dist[e.to] > dist[x] + e.cost + dbell[x] - dbell[e.to])
            {
                dist[e.to] = dist[x] + e.cost + dbell[x] - dbell[e.to];
                t[e.to] = edge_idx;
                q.push({dist[e.to], e.to});
            }
        }
    }

    if(dist[d] == Inf)return false;

    int min_flow = Inf, cost = dbell[d] + dist[d];

    for(int x = d; x != s; x = edges[t[x]].from)
        min_flow = min(min_flow, edges[t[x]].capacity - edges[t[x]].flow);

    for(int x = d; x != s; x = edges[t[x]].from)
    {
        edges[t[x]].flow += min_flow;
        edges[t[x] ^ 1].flow -= min_flow;
    }

    ret.ff += min_flow, ret.ss += min_flow * cost;

    return true;
}

void solve_testcase()
{
    int N, K, G;
    cin >> N >> K >> G;

    vi v(N), g(N), x(N);
    REP(i, 0, N)cin >> v[i] >> g[i] >> x[i];

    int source = 0, destination = 1;
    vector<Edge> edges;
    vvi graph(2 + N * (G + 1));

    auto add_edge = [&](int from, int to, int cost, int capacity)
    {
        edges.eb(from, to, cost, capacity, 0);
        graph[from].pb((int)edges.size() - 1);
        edges.eb(to, from, -cost, 0, 0);
        graph[to].pb((int)edges.size() - 1);
    };

    add_edge(source, encode_node(0, 0, G), 0, K);

    for(int room = 0; room < N; ++room)
        for(int a = 0, b = g[room]; b <= G; ++a, ++b)
            add_edge(encode_node(room, a, G), encode_node(room, b, G), -v[room], K);

    for(int room = 0; room + 1 < N; ++room)
        for(int w = 0; w <= G; ++w)
            add_edge(encode_node(room, w, G), encode_node(room + 1, w, G), 0, x[room]);

    int room = N - 1;
    for(int w = 0; w <= G; ++w)
        add_edge(encode_node(room, w, G), destination, 0, x[room]);

    pii ans(0, 0);
    vi dbell(2 + N * (G + 1));
    vb inq(2 + N * (G + 1));
    BellMan(graph, edges, dbell, inq, source, destination);
    vi dist(2 + N * (G + 1)), t(2 + N * (G + 1));
    for(;Dijkstra(graph, edges, dbell, dist, t, source, destination, ans););

    if(K != ans.ff)cout << "-1\n";
    else cout << -ans.ss << '\n';
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while(t --)
        solve_testcase();
    return 0;
}
