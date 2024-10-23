#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
ifstream cin("biconex.in");
ofstream cout("biconex.out");

int n,m;
vector<vector<int> > sirad,C;
vector<int> lvl,low;
stack<pair<int,int> > stk;

void citestegraf();
void CompBi(int x,int parent,int idx);
void ScriecompBi();
void cache_bc(int x,int y);
int main()
{
    citestegraf();
    CompBi(1,0,0);
    ScriecompBi();
    return 0;
}
void citestegraf()
{
    int a,b;
    cin>>n>>m;
    sirad = vector<vector<int> >(n+1);
    low = vector<int>(n+1);
    lvl = vector<int>(n+1,-1);
    while(m--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
        sirad[b].push_back(a);
    }
}
void CompBi(int x,int parent,int idx)
{
    lvl[x] = low[x] = idx;

    for(auto i : sirad[x])
    {
        if(i==parent)continue;
        if(lvl[i]==-1)
        {
            stk.push({x,i});
            CompBi(i,x,idx+1);
            low[x] = min(low[x],low[i]);
            if(low[i] >= lvl[x])
                cache_bc(x,i);
        }
        else
            low[x] = min(low[x],lvl[i]);
    }
}
void cache_bc(int x,int y)
{
    vector<int> con;
    int tx,ty;

    do
    {
        tx = stk.top().first,ty = stk.top().second;
        stk.pop();
        con.push_back(tx),con.push_back(ty);
    }
    while(tx !=x || ty != y);
    C.push_back(con);
}
void ScriecompBi()
{
    cout<<C.size()<<'\n';
    for(auto& i : C)
    {
        sort(i.begin(),i.end());
        i.erase(unique(i.begin(),i.end()),i.end());
        for(auto& j : i)
            cout<<j<<' ';
        cout<<'\n';
    }
}
