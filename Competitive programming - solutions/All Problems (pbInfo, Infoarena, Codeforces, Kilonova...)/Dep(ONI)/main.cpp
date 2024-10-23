#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define ll long long
#define VI vector<int>
#define VVI vector<VI>
using namespace std;
const int N = 269, Mod = 666013;

int n, m, k, a, b, grad[N];
bool root[N];
int dp[N][N], w[N], ans[N];
bool mat2[N][N];
bitset<N> viz;
VVI G, GF;

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod) x -= Mod;
    if(x < 0) x += Mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a * b) % Mod;
}


int low[N], lvl[N], comp[N], idx, cnt;
stack<int> stk;
bool instk[N];
void DfsT(int x)
{
    stk.push(x);
    instk[x] = true;
    lvl[x] = low[x] = ++ idx;

    for(auto y : G[x])
        if(!lvl[y])
        {
            DfsT(y);
            low[x] = min(low[x], low[y]);
        }
        else if(instk[y])low[x] = min(low[x], lvl[y]);

    if(lvl[x] == low[x])
    {
        ++cnt;
        while(true)
        {
            int a = stk.top();
            stk.pop();
            instk[a] = false;
            comp[a] = cnt;
            if(a == x)break;
        }
    }
}
void Tarjan()
{
    for(int i = 1; i <= n; ++i)
        if(!lvl[i])
            DfsT(i);
}

void merge_state(int* a, int* b)
{
    for(int i = k; i >= 0; --i)
        for(int j = k - i; j > 0; --j)
            a[i + j] = add(a[i + j], mul(a[i], b[j]));
}

void DPDfs(int x)
{
    dp[x][w[x]] = 1;

    for(auto y : G[x])
    {
        DPDfs(y);

        merge_state(dp[x], dp[y]);
    }
}


int main()
{
    freopen("dep.in", "r", stdin);
    freopen("dep.out", "w", stdout);

    cin >> n >> m >> k;
    G = GF = VVI(n + 1);
    for(int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b);
    }

    Tarjan();

    for(int i = 1; i <= n; ++i)
    {
        w[comp[i]]++;
        for(auto j : G[i])
            if(comp[i] != comp[j] && !mat2[comp[i]][comp[j]])
            {
                mat2[comp[i]][comp[j]] = true;
                grad[comp[i]] ++;
            }
    }
    G = VVI(n + 1);

    queue<int> q;
    for(int i = 1; i <= cnt; ++i)
        if(!grad[i]){
            G[0].push_back(i);
            q.push(i);
        }
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();

        for(int i = 1; i <= cnt; ++i)
        {
            if(!mat2[i][nod])continue;

            grad[i] --;
            if(!grad[i])
            {
                G[nod].push_back(i);
                q.push(i);
            }
        }
    }

    DPDfs(0);
    cout << dp[0][k];
    return 0;
}
