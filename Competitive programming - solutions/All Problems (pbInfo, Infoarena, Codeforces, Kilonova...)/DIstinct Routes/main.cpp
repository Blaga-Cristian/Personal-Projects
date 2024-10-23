#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
using namespace std;
const int N = 509, Inf = 0x3f3f3f3f;

int n, m, a, b, C[N][N], F[N][N], t[N];
bitset<N> v;
queue<int> q;
VI stk;
VVI G;

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
            if(!v[y] && C[x][y] > F[x][y])
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
        F[t[i]][i] ++;
        F[i][t[i]] --;
    }
}
int MaxFlow(int source, int sink)
{
    int maxflow = 0;
    for(;Bfs(source, sink);maxflow++)
        Augment(source, sink);
    return maxflow;
}

void Afis()
{
    cout << stk.size() << '\n';
    for(int i = stk.size() - 1; i >= 0; --i)
        cout << stk[i] << ' ';
    cout << '\n';
}
bool Dfs(int source, int x)
{

    stk.push_back(x);

    if(x == source)
    {
        Afis();
        stk.pop_back();
        return true;
    }

    for(auto y : G[x])
        if(F[y][x] > 0)
            Dfs(source, y);

    stk.pop_back();

    return
}

int main()
{
    cin >> n >> m;
    G = VVI(n + 1);

    while(m --)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        C[a][b]++;
    }

    cout << MaxFlow(1, n) << '\n';


    for(int i = 1; i <= n; ++i, cout << "\n\n")
    {
        //cout << i << '\n';
        for(auto j : G[i]);
            //cout << j << ' ' << C[i][j] << ' ' << F[i][j] << '\n';
    }

    Dfs(1, n);
    return 0;
}
