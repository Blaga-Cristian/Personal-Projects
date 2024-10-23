#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int M = 109;
int n,m,k,a,b;
vector<vector<int>> sirad;
vector<vector<int>>cc;
vector<int> low,lvl;
vector<bool>instk;
stack<int>stk;
int idx;
void extract(int x)
{
    vector<int>c;
    while(!stk.empty())
    {
        int node = stk.top();
        c.push_back(node);
        instk[node] = false;
        stk.pop();
        if(node == x)
            break;
    }
    cc.push_back(c);
}
void Tarjan(int x)
{
    stk.push(x);
    instk[x] = true;
    lvl[x] = low[x] = ++idx;

    for(auto i : sirad[x])
        if(lvl[i] == -1)
        {
            Tarjan(i);
            low[x] = min(low[x],low[i]);
        }
        else if(instk[i])low[x] = min(low[x],lvl[i]);

    if(lvl[x] == low[x])
        extract(x);
}
int main()
{
    cin>>n>>m;
    low = lvl = vector<int>(n+1,-1);
    instk = vector<bool>(n+1);
    sirad = vector<vector<int>>(n+1);
    while(m--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
    }
    for(int i=1;i<=n;++i)
        if(lvl[i] == -1)
            Tarjan(i);
    int cnt = 0;
    for(auto i : cc)
        cnt += (i.size() == 1);
    cout<<cnt;
    return 0;
}
