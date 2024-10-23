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


const string TASK("fmcm");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int Inf = 0x3f3f3f3f;
const ll N = 359;

int n, m, S, D;
int MCMF;



class FMCM
{
public:
    const int oo = 1e9;

    struct Edge
    {
        int from, to, cost, capacity, flow;

        Edge(){}
        Edge(int from, int to, int cost, int capacity, int flow) :
            from(from), to(to), cost(cost), capacity(capacity), flow(flow){}
    };

    vi dbell, d, t;
    int n, s, d;
    vvi G;
    vector<edge> edges;

    FMCM(int n, int s, int d) : n(n), s(s), d(d)
    {
        G.resize(n + 1); t.resize(n + 1);
        dbell.resize(n + 1, oo); d.resize(n + 1);
    }

    void add_edge(int from, int to, int cost, int capacity)
    {
        edges.eb(from, to, cost, capacity, 0);
        G[from].pb((int)edges.size() - 1);
        edges.eb(to, from, -cost, 0, 0);
        G[to].pb((int)edges.size() - 1);
    }

    void BellMan()
    {
        queue<int> q;
        q.push(s);
        dbell[s] = 0;
        bool inq[n + 1] = {0};
        inq[s] = true;

        while(!q.empty())
        {
            int x = q.front();
            inq[x] = false;
            q.pop();

            for(int edge_idx : G[x])
            {
                auto& e = edges[edge_idx];
                if(e.flow < e.capacity && dbell[e.to] > dbell[x] + e.cost)
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

    bool Dijkstra(pii& mcmf)
    {
        priority_queue<pii, vector<pii>, greater<pii>> q; q.push({0, S});
        fill(all(d), oo); d[s] = 0;

        while(!q.empty())
        {
            int dx = q.top().ff, x = q.top().ss;
            q.pop();

            if(dx > d[x])continue;

            for(int edge_idx : G[x])
            {
                auto& e = edges[edge_idx];
                if(e.flow < e.capacity && d[e.to] > d[x] + e.cost + dbell[x] - dbell[e.to])
                {
                    d[e.to] = d[x] + e.cost + dbell[x] - dbell[e.to];
                    t[e.to] = edge_idx;
                    q.push({d[e.to], e.to});
                }
            }
        }

        if(d[D] == Inf)return false;


        int min_flow = Inf;
        int cost = dbell[d] + d[d];

        for(int x = d; x != s; x = edges[t[x]].from)
            min_flow = min(min_flow, edges[t[x]].capacity - edges[t[x]].flow);

        for(int x = d; x != s; x = edges[t[x]].from)
        {
            edges[t[x]].flow += min_flow;
            edges[t[x] ^ 1].flow -= min_flow;
        }

        mcmf.ff += min_flow; mcmf.ss += min_flow * cost;

        return true;
    }

    pii info()
    {
        pii ret(0, 0);
        BellMan();
        for(;Dijkstra(ret););
        return ret;
    }
};

int main() {
//    fastio();

    cin >> n >> m >> S >> D;
    FMCM ans;

    int x, y, c, z;
    FOR(i, 1, m)
    {
        cin >> x >> y >> c >> z;
        ans.add_edge(x, y, z, c);
    }

    cout << ans.info()

    return 0;
}
