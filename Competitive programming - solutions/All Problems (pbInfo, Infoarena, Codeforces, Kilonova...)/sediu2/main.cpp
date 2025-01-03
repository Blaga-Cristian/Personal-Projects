#include <fstream>
#include <vector>

using namespace std;
ifstream cin("16-sediu.in");
ofstream cout("sediu.out");
const int N = 16009;
int n,a,b,w[N],bigst[N];
vector<vector<int>> G;

void Dfs(int x,int p)
{
    bigst[x] = 0;
    w[x] = 1;

    for(auto i : G[x])
        if(i != p)
        {
            Dfs(i,x);

            w[x] += w[i];
            bigst[x] = max(bigst[x],w[i]);
        }
}
int main()
{
    cin>>n;
    G = vector<vector<int>>(n+1);
    for(int i = 1; i < n; ++i)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Dfs(1,0);

    for(int i = 1; i <= n; ++i)
        bigst[i] = max(bigst[i],n - w[i]);

    int mn = 0x3f3f3f3f;
    vector<int> ans;
    for(int i = 1; i <= n; ++i)
    {
        if(bigst[i] < mn)
        {
            mn = bigst[i];
            ans.clear();
            ans.push_back(i);
        }
        else if(bigst[i] == mn)
            ans.push_back(i);
    }

    cout<<mn<<' '<<ans.size()<<'\n';
    for(auto i : ans)
        cout<<i<<' ';
    return 0;
}
