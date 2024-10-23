#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream cin("nuclee.in");
ofstream cout("nuclee.out");
int n,a,cnt,y,z,node;
vector<vector<int>>sirad;
vector<int> low,lvl;
vector<bool> instk;
stack<int> stk;
int idx;
int ans;
void extract(int x)
{
    while(true)
    {
        int node = stk.top();
        instk[node] = false;
        stk.pop();
        if(node == x)break;
    }
}
void Tarjan(int x)
{
    instk[x] = true;
    stk.push(x);
    low[x] = lvl[x] = ++idx;

    for(auto i : sirad[x])
        if(lvl[i] == -1)
        {
            Tarjan(i);
            low[x] = min(low[x],low[i]);
        }
        else if(instk[i])low[x] = min(low[x],lvl[i]);

    if(lvl[x] == low[x])
    {
        ++ans;
        extract(x);
    }
}
int main()
{
    cin>>n;
    sirad = vector<vector<int>>(n+1);
    low = lvl = vector<int>(n+1,-1);
    instk = vector<bool>(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>cnt;
        while(cnt--)
        {
            cin>>a;
            sirad[i].push_back(a);
        }
    }

    for(int i=1;i<=n;++i)
        if(lvl[i] == -1)
            Tarjan(i);

    cout<<ans;
    return 0;
}
