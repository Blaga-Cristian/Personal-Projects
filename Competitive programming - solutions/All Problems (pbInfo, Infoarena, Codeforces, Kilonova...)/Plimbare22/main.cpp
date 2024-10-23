#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;
ifstream cin("plimbare.in");
ofstream cout("plimbare.out");

vector<vector<int>> sirad;
vector<int> cc,c,index,low;
vector<vector<bool> >matad;
stack<int> stk;
vector<bool> instk,viz;
int idx,n;

void Tarjan();
void Dfs(int x);
bool f(int a,int b);


int main()
{
    int a,b;
    cin>>n;

    sirad = vector<vector<int> >(n+1);
    index = low = vector<int>(n+1);
    instk = viz = vector<bool>(n+1);
    matad = vector<vector<bool>>(n+1,vector<bool>(n+1));

    while(cin>>a>>b)
        sirad[a].push_back(b),
        matad[a][b] = 1;

    Tarjan();

    cout<<cc.size()<<'\n';
    int ok = 1;
    while(ok)
    {
        ok = 0;
        for(int i=0;i<cc.size();++i)
        {
            int ind = (i+1)%cc.size();
            if(matad[cc[i]][cc[ind]]==0)
            {
                swap(cc[i],cc[ind]);
                ok = 1;
            }
        }
    }
    for(auto i : cc)cout<<i<<' ';
    return 0;
}

void Tarjan()
{
    for(int i=1;i<=n;++i)
        if(!viz[i])
            Dfs(i);
}

void Dfs(int x)
{
    stk.push(x);
    instk[x] = viz[x] = true;
    index[x] = low[x] = ++idx;

    for(auto i : sirad[x])
        if(!viz[i])
        {
            Dfs(i);
            low[x] = min(low[x],low[i]);
        }
        else if(instk[i])low[x] = min(low[x],index[i]);

    if(index[x] == low[x])
    {
        c.clear();
        while(!stk.empty())
        {
            int a = stk.top();
            stk.pop();
            instk[a] = 0;
            c.push_back(a);
            if(index[a] == low[a])break;
        }
        if(c.size()>cc.size())cc=c;
    }
}
bool f(int a,int b)
{
    for(auto i : sirad[a])
        if(i==b)return true;
    return false;
}
