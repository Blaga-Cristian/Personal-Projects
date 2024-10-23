#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
ifstream cin("dep.in");
ofstream cout("dep.out");
const int Mod = 666013;
using ll = long long;
int n,m,k,a,b;
vector<vector<int>> G;
vector<vector<int>> nG;

vector<int> low,lvl;
vector<bool> instk;
stack<int> stk;
vector<int> ctc;
int idx;
ll dp[300][300];
int out[300];
int comp[300];
bool mat[300][300];
queue<int> q;

void Dfs(int x)
{
    stk.push(x);
    instk[x] = true;
    lvl[x] = low[x] = ++idx;

    for(auto i : G[x])
        if(lvl[i] == -1)
        {
            Dfs(i);
            low[x] = min(low[x],low[i]);
        }
        else if(instk[i])low[x] = min(low[x],lvl[i]);

    if(lvl[x] == low[x])
    {
        int cnt = 0;
        while(true)
        {
            int i = stk.top();
            stk.pop();
            instk[i] = false;
            comp[i] = ctc.size() + 1;
            ++cnt;
            if(i == x)break;
        }
        ctc.push_back(cnt);
    }
}
void Tarjan()
{
    for(int i = 1; i <= n; ++i)
        if(lvl[i] == -1)
            Dfs(i);
}

void Dfs3(int nod)
{
    dp[nod][ctc[nod-1]] = 1;

    for(auto vecin : nG[nod])
        Dfs3(vecin);

    for(auto vecin : nG[nod])
    {
        for(int i = k; i >= 0; --i)
        {
            if(dp[nod][i] == 0)continue;

            for(int j = k - i; j > 0; --j)
                dp[nod][i+j] = (dp[nod][i+j] + 1LL * dp[nod][i] * dp[nod][j] % Mod) % Mod;
        }
    }

}
int main()
{
    cin>>n>>m>>k;
    nG = G = vector<vector<int>>(n+1);
    lvl = low = vector<int>(n+1,-1);
    instk = vector<bool>(n+1);

    while(m--)
    {
        cin>>a>>b;
        G[a].push_back(b);
    }

    Tarjan();

    for(int i = 1; i < G.size(); ++ i)
    {
        for(auto j : G[i])
            if(comp[i] != comp[j] && !mat[comp[i]][comp[j]])
        {
            mat[comp[i]][comp[j]] = 1;
            out[comp[i]] ++;
        }
    }

    for(int i = 1; i <= ctc.size(); ++i)
    {
        if(out[i] == 0)
        {
            nG[0].push_back(i);
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(int i = 1; i <= ctc.size(); ++i)
        {
            if(!mat[i][x])continue;

            out[i] --;
            if(out[i] == 0)
            {
                nG[x].push_back(i);
                q.push(i);
            }
        }
    }

    dp[0][0] = 1;
    Dfs3(0);
    cout<<dp[0][k];
    return 0;
}
