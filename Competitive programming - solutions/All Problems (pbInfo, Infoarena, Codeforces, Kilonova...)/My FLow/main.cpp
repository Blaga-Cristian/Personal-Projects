#include <bits/stdc++.h>
#include <bits/extc++.h>
#define MP make_pair
#define MT make_tuple
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int,int>
#define F first
#define S second
#define PB push_back
#define ll long long
#define ull unsigned ll
#define fast_in_out ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define REP(i,a,b) for(int i = a; i <= b; ++i)
template <typename T>
using indexed_set = __gnu_pbds::tree <T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;


using namespace std;
typedef array<int,3> triple;

const int Inf = 0x3f3f3f3f, N = 509, V = 109;
const int Mod = 1e9 + 7;
const int L = 5009;

int n, m, a, b;
VVI G;
VVI tours;
int C[N][N];
int OrC[N][N];
int t[N];

bitset<N> v;
queue<int> q;
vector<int> vec;

void Dfs(int x)
{
    if(x == n)
    {
        tours.PB(vec);
        return;
    }

    for(auto y : G[x])
    {
        if(OrC[x][y] && C[x][y] == 0)
        {
            vec.PB(y);
            Dfs(y);
            vec.pop_back();
        }
    }
}

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
            if(C[x][y] > 0 && v[y] == false)
        {
            v[y] = true;
            t[y] = x;
            q.push(y);
        }
    }

    return v[sink];
}

void Augment(int source, int sink)
{
    for(int i = sink; i != source; i = t[i])
    {
        C[t[i]][i] --;
        C[i][t[i]] ++;

    }
}

void MaxFlow(int source, int sink)
{
    for(; Bfs(source, sink);)
        Augment(source, sink);
}

int main()
{
    cin >> n >> m;
    G = VVI(n + 1);
    while(m --)
    {
        cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
        C[a][b]++;
        OrC[a][b]++;
    }

    MaxFlow(1, n);
    vec.PB(1);
    Dfs(1);

    cout << tours.size() << '\n';
    for(auto i : tours)
    {
        cout << i.size() << '\n';
        for(auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
