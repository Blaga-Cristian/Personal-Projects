#include <fstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
ifstream cin("competitie.in");
ofstream cout("competitie.out");

vector<vector<int> >sir;
vector<int> deg;
int main()
{
    int n,m,x,y;
    priority_queue<int,vector<int>, greater<int> > q;
    cin>>n>>m;
    sir = vector<vector<int> >(n+1);
    deg = vector<int>(n+1);
    while(m--)
    {
        cin>>x>>y;
        sir[x].emplace_back(y);
        deg[y]++;
    }
    for(int i=1;i<=n;++i)if(deg[i]==0)q.emplace(i);
    while(!q.empty())
    {
        x = q.top();
        q.pop();
        cout<<x<<' ';
        for(auto i:sir[x])
        {
            deg[i]--;
            if(deg[i]==0)q.emplace(i);
        }
    }
    return 0;
}
