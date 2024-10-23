#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream cin("ctc.in");
ofstream cout("ctc.out");
const int N = 1e5 + 9;
int n,m,a,b;
vector<vector<int>> G;

vector<int> lvl,low;
vector<bool> instk;
stack<int> stk;
vector<vector<int>> ctc;
vector<int> c;

int idx;
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

    if(low[x] == lvl[x])
    {
        c.clear();
        while(true)
        {
            int i = stk.top();
            stk.pop();
            instk[i] = false;
            c.push_back(i);
            if(i == x)break;
        }
        ctc.push_back(c);
    }
}
int main()
{
    cin>>n>>m;
    G = vector<vector<int>>(n+1);
    lvl = low = vector<int>(n+1,-1);
    instk = vector<bool>(n+1);
    while(m--)
    {
        cin>>a>>b;
        G[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i)
        if(lvl[i] == -1)
            Dfs(i);

    cout<<ctc.size()<<'\n';
    for(auto i : ctc)
    {
        for(auto j : i)
            cout<<j<<' ';
        cout<<'\n';
    }
    return 0;
}
