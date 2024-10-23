#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9;

int n, m, a, b;
vector<vector<int>> G, ctc;
int lvl[N], low[N];
stack<int> stk;
bool instk[N];
int idx;
int comp[N];


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


    cout << ctc.size() << '\n';
    for(int i = 0; i < ctc.size(); ++i)
        for(int j = 0; j < ctc[i].size(); ++j)
            comp[ctc[i][j]] = i + 1;

    for(int i = 1; i <= n; ++i)
        cout <<  comp[i] << ' ';
    return 0;
}
