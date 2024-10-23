#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9;

int n, m, a, b;
vector<vector<int>> G, ctc;
int lvl[N], low[N];
stack<int> stk;
bool instk[N];
int idx;
bitset<N> viz;

bool Bfs(int a, int b)//daca pot ajunde din a la b
{
    viz.reset();
    queue<int> q;
    q.push(a);
    viz[a] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(x == b)break;

        for(auto y : G[x])
            if(!viz[y])
            {
                viz[y] = true;
                q.push(y);
            }
    }

    return viz[b];
}


void Dfs(int x)
{
    stk.push(x);
    instk[x] = true;
    low[x] = lvl[x] = ++idx;

    for(auto y : G[x])
        if(!lvl[y])
        {
            Dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y])low[x] = min(low[x], lvl[y]);

    if(lvl[x] == low[x])
    {
        vector<int> aux;
        while(true)
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;
            aux.push_back(a);
            if(a == x)break;
        }
        ctc.push_back(aux);
    }
}


int main()
{
    cin >> n >> m;
    G = vector<vector<int>>(n + 1);
    while(m --)
    {
        cin >> a >> b;
        G[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i)
        if(!lvl[i])
            Dfs(i);

    if(ctc.size() == 1)
        cout << "YES";
    else
    {
        cout << "NO\n";
        int a = ctc[0][0], b = ctc[1][0];

        if(Bfs(a, b))
            cout << b << ' ' << a;
        else
            cout << a << ' ' << b;
    }
    return 0;
}
