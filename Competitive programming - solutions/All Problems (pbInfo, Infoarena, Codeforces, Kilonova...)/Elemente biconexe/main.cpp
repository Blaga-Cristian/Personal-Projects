#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream cin("test.in");
ofstream cout("test.out");
int n,m,a,b;
vector<int> lvl,low;
vector<vector<int>>sirad;
struct muchie
{
    int a,b;
    bool operator != (muchie& x)
    {
        return (a!=x.a&&b!=x.b);
    }
};
stack<muchie> muchii;
void cache(muchie x)
{
    stack<muchie> aux;
    while(!muchii.empty() && muchii.top() != x)
    {
        aux.push(muchii.top());
        muchii.pop();
    }
    if(!muchii.empty())muchii.pop();
    while(!aux.empty())
    {
        muchii.push(aux.top());
        aux.pop();
    }
}
void Dfs(int x,int parent,int idx)
{
    lvl[x] = low[x] = idx;
    //cout<<x<<' ';
    for(auto i : sirad[x])
    {
        if(i==parent)continue;

        if(lvl[i]==-1)
        {
            muchii.push({x,i});
            Dfs(i,x,idx+1);
            low[x] = min(low[x],low[i]);
            if(low[i] <= lvl[x])
                cache({x,i});
        }
        else
            low[x] = min(low[x],lvl[i]);
    }
}
int main()
{
    cin>>n>>m;
    sirad = vector<vector<int>>(n+1);
    lvl = low = vector<int>(n+1,-1);
    while(m--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
        sirad[b].push_back(a);
    }
    Dfs(1,0,1);
    while(!muchii.empty())
    {
        cout<<muchii.top().a<<' '<<muchii.top().b<<'\n';
        muchii.pop();
    }
    return 0;
}
