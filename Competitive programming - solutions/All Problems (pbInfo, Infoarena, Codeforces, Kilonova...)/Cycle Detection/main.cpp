#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9;
vector<vector<int>> G;
vector<int> ans;
stack<int> stk;
int instk[N];
int t[N], low[N], lvl[N];
int a, b, n, m;
int idx;
bool viz[N];

void Dfs(int x)
{
    stk.push(x);
    instk[x] = true;
    low[x] = lvl[x] = ++idx;

    for(auto y : G[x])
        if(lvl[y] == 0)
        {
            t[y] = x;
            Dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y])
            low[x] = min(low[x], lvl[y]);


    if(low[x] == lvl[x])
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

        if(aux.size() > 1)
        {
            ans.clear();
            for(auto i : aux)
                ans.push_back(i);
        }
    }
}

void FindPath()
{
    int root = ans.back();
    int path;
    queue<int> q;
    q.push(root);
    viz[root] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto y : G[x])
            if(!viz[y])
            {
                viz[y] = true;
                q.push(y);
            }
            else if(y == root)
            {
                path = y;
                q = queue<int>();
                break;
            }
    }

    ans.clear();
    ans.push_back(path);
    while(path != root)
    {
        path = t[path];
        ans.push_back(path);
    }
}

int main()
{
    cin >> n >> m;
    G = vector<vector<int>>(n + 1);
    while(m--)
    {
        cin >> a >> b;
        G[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i)
        if(!lvl[i])
            Dfs(i);


    if(ans.size() == 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }


    FindPath();

    cout << ans.size() + 1 << '\n';
    for(int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i] << ' ';
    cout << ans.back();
    return 0;
}
