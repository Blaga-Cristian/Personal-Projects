#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("kruskal.in");
ofstream cout("kruskal.out");
struct muchie{
int x,y,cost;
}g;
bool f(muchie a,muchie b)
{
    return a.cost<b.cost;
}
int n,m,t[1000],cost;
vector<muchie> v,ans;

int main()
{
    muchie g;
    cin>>n>>m;
    while(true)
    {
        cin>>g.x>>g.y>>g.cost;
        if(cin.eof())break;
        v.push_back(g);
    }
    sort(v.begin(),v.end(),f);
    for(int i=0;i<=n;++i)t[i]=i;
    for(auto i :v)
    {
        if(t[i.x]!=t[i.y])
        {
            cost+=i.cost;
            int ai = t[i.x], aj = t[i.y];
            for(int k=1;k<=n;++k)
            {
                if(t[k]==aj)t[k]=ai;
            }
            ans.push_back(i);
        }
    }
    cout<<cost<<'\n';
    for(auto i : ans)cout<<i.x<<' '<<i.y<<'\n';
    return 0;
}
