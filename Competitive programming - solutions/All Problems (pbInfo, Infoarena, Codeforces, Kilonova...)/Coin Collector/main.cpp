#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 9;

int n, m, a, b, val[N], in[N];
ll valctc[N], dp[N];
vector<vector<int>> G;

//Pt ctc
vector<vector<int>> ctc;
stack<int> stk;
bool instk[N];
int idx, comp[N], low[N], lvl[N];

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
        vector<int> c;
        while(true)
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;
            comp[a] = ctc.size();
            c.push_back(a);
            if(a == x)break;
        }
        ctc.push_back(c);
    }
}

ll STopDp()
{
    ll ans = 0;

    queue<int> q;
    for(int i = 0; i < ctc.size(); ++i)
        if(!in[i])
        {
            q.push(i);
            dp[i] = valctc[i];
        }

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto c : ctc[x])
            for(auto y : G[c])
                if(comp[y] != comp[c])
                {
                    dp[comp[y]] = max(dp[comp[y]], dp[x] + valctc[comp[y]]);
                    if((--in[comp[y]]) == 0)
                        q.push(comp[y]);
                }
    }

    for(int i = 0; i < ctc.size(); ++i)
        ans = max(ans, dp[i]);

    return ans;
}

int main()
{
    cin >> n >> m;
    G = vector<vector<int>>(n + 1);
    for(int i = 1; i <= n;  ++i)
        cin >> val[i];
    while(m --)
    {
        cin >> a >> b;
        G[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i)
        if(!lvl[i])
            Dfs(i);

    for(int i = 0; i < ctc.size(); ++i)
        for(int j = 0; j < ctc[i].size(); ++j)
        {
            valctc[i] += val[ctc[i][j]];
            for(auto y : G[ctc[i][j]])
                if(comp[y] != i)
                    in[comp[y]]++;
        }

    cout << STopDp();
    return 0;
}
