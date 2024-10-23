#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream cin("ctc.in");
ofstream cout("ctc.out");

vector<vector<int> > sirad,cc;
vector<int> c, index, low;
vector<bool> viz,instk;
stack<int> st;
int n,m,idx;

void Tarjan();
void Dfs(int x);

int main()
{
    int a,b;
    cin>>n>>m;
    sirad = vector<vector<int>>(n+1);
    index = low = vector<int>(n+1);
    viz = instk = vector<bool>(n+1);

    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
    }

    Tarjan();
    return 0;
}

void Tarjan()
{
    for(int i=1;i<=n;++i)
        if(!viz[i])
            Dfs(i);

    cout<<cc.size()<<'\n';
    for(auto i : cc)
    {
        for(auto j : i)cout<<j<<' ';
        cout<<'\n';
    }
}

void Dfs(int x)
{
    st.push(x);
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
        while(!st.empty())
        {
            int a = st.top();
            st.pop();
            instk[a] = 0;
            c.push_back(a);
            if(index[a]==low[a])break;
        }
        cc.push_back(c);
    }

}
