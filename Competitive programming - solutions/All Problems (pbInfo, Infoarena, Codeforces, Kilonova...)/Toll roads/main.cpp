#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("tollroads.in");
ofstream cout("tollroads.out");
const int Inf = 0x3f3f3f3f;
int n,m,q,x,t;
vector<vector<pair<int,int> > >sirad;
vector<int> d;
inline void Dial(int x,int t)
{
    vector<vector<int> >v(t+1);
    for(int i=1;i<=n;++i)d[i] = Inf;
    d[x] = 0;
    v[0].emplace_back(x);
    int cnt = -1;
    for(int i=0;i<=t;++i)
    {
        for(auto j:v[i])
        {
            for(auto k:sirad[j])
            {
                int to = k.first;
                int len = k.second;
                if(i+len<=t&&i+len < d[to])d[to] = i+len,v[i+k.second].emplace_back(k.first);
            }
        }
        v[i].clear();
    }
    for(int i=1;i<=n;++i)
        if(d[i]<Inf)cnt++;
    cout<<cnt<<'\n';
}
int main()
{
    int a,b,c;
    cin>>n>>m>>q;
    d = vector<int>(n+1,Inf);
    sirad = vector<vector<pair<int,int> > >(n+1);
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>c;
        sirad[a].emplace_back(b,c);
        sirad[b].emplace_back(a,c);
    }
    while(q--)
    {
        cin>>x>>t;
        Dial(x,t);
    }
    return 0;
}
