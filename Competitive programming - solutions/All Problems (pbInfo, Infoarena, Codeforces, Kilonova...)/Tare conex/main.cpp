#include <fstream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
ifstream cin("plimbare.in");
ofstream cout("plimbare.out");

stack<int>st;
vector<vector<int> >sirad,siradt;
set<set<int>>ctcv;
vector<int> c,ans;
vector<bool> viz;
int n,m;
void Dfs(int x)
{
    viz[x] = true;
    for(auto i : sirad[x])
        if(!viz[i])Dfs(i);
    st.push(x);
}
void Dfs1(int x)
{
    viz[x] = true;
    c.push_back(x);
    for(auto i : siradt[x])
        if(!viz[i])Dfs1(i);
}
int main()
{
    int a,b;
    cin>>n;
    m = n*(n-1)/2;
    sirad = siradt = vector<vector<int> >(n+1);
    viz = vector<bool>(n+1);
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
        siradt[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
        if(!viz[i])
            Dfs(i);
    for(int i=1;i<=n;++i)
        viz[i]=0;
    int ctc = 0;
    while(!st.empty())
    {
        int x = st.top();
        st.pop();
        if(!viz[x])
        {
            ctc++;
            c.clear();
            Dfs1(x);
            if(c.size()>ans.size())ans = c;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto i : ans)cout<<i<<' ';
    return 0;
}
