#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;
string f = "dmin2.";
ifstream fin(f+"in");
ofstream fout(f+"out");

int n,m,a,b,k,x,y;
vector<set<int>>sirad;
vector<int> low,lvl;
vector<int> coresp;
vector<bool> instk;
stack<int> stk;
int idx;
int cnt;
void extract(int x)
{
    ++cnt;
    while(!stk.empty())
    {
        int node = stk.top();
        stk.pop();
        instk[node] = false;
        coresp[node] = cnt;
        if(node == x)
            break;
    }
}
void Tarjan(int x)
{
    lvl[x] = low[x] = ++idx;
    stk.push(x);
    instk[x] = true;

    for(auto i : sirad[x])
        if(lvl[i] == -1)
        {
            Tarjan(i);
            low[x] = min(low[x],low[i]);
        }
        else if(instk[i])low[x] = min(low[x],lvl[i]);

    if(low[x] == lvl[x])
        extract(x);
}
int main()
{
    cin>>n>>m>>k;
    sirad = vector<set<int>>(n+1);
    lvl = low = vector<int>(n+1,-1);
    coresp = vector<int>(n+1);
    instk = vector<bool>(n+1);
    while(m--)
    {
        cin>>a>>b;
        sirad[a].insert(b);
    }

    for(int i=1;i<=n;++i)
        if(lvl[i] == -1)
            Tarjan(i);

    int ans = 0;
    k = coresp[k];
    for(int i=1;i<=n;++i)
        if(coresp[i] == k)ans++;
    cout<<ans;
    return 0;
}
