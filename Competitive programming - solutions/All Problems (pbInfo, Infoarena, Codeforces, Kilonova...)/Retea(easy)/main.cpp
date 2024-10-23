#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const string f = "retea1.";
ifstream cin(f + "in");
ofstream cout(f + "out");

int n,m,x,y,a,b,c,cnt,node;
vector<vector<int>>sirad;
vector<int> ans;

vector<int> low,lvl;
stack<int> stk;
vector<bool> instk;
int idx;

void cache(int x)
{
    vector<int> c;
    while(true)
    {
        node = stk.top();
        instk[node] = false;
        stk.pop();
        c.push_back(node);
        if(x==node)break;
    }
    if(c.size() > 1)
        for(auto i : c)
            ans.push_back(i);
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
        else low[x] = min(low[x],lvl[i]);

    if(lvl[x] == low[x])
        cache(x);
}
int main()
{
    cin>>n;
    sirad = vector<vector<int>>(n+1);
    low = lvl = vector<int>(n+1,-1);
    instk = vector<bool>(n+1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
    {
        cin>>x;
        if(x)
        {
            if(i==j)
                ans.push_back(i);
            else
                sirad[i].push_back(j);
        }
    }

    for(int i=1;i<=n;++i)
        if(lvl[i] == -1)
            Tarjan(i);

    sort(ans.begin(),ans.end());
    cout<<'{';
    for(int i=0;i<ans.size()-1;++i)
        cout<<ans[i]<<',';
    cout<<ans.back()<<'}';
    return 0;
}
