#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
ifstream cin("modernizare.in");
ofstream cout("modernizare.out");
const long long Inf = 1LL<<60;
int n,m,F,a,b,c,x,y,cnt,node;
vector<vector<int>> sirad;
vector<long long> dist;
struct muchie
{
    long long a,b,c;
};
inline bool cmp (const muchie& x,const muchie& y)
{
    if(x.a == y.a && x.b == y.b)
        return x.c < y.c;
    else if(x.a == y.a)
        return x.b < y.b;
    return x.a < y.a;
}
vector<muchie> muchii;
void getdist()
{
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto i : sirad[x])
            if(dist[i] > 1 + dist[x])
            {
                dist[i] = 1 + dist[x];
                q.push(i);
            }
    }
}
int main()
{
    cin>>n>>m>>F;
    sirad = vector<vector<int>>(n+1);
    dist = vector<long long>(n+1,Inf);
    for(int i=1;i<=m;++i)
    {
        cin>>x>>y>>c;
        muchii.push_back({x,y,c});
        sirad[x].push_back(y);
        sirad[y].push_back(x);
    }

    getdist();

    for(auto& i : muchii)
    {
        muchie aux = {min(dist[i.a],dist[i.b]),max(dist[i.a],dist[i.b]),i.c};
        i = aux;
    }

    sort(muchii.begin(),muchii.end(),cmp);

    int ans = 0,ind = 0;
    bool ok = true;
    while(ok && ind < muchii.size())
    {
        if(muchii[ind].b == Inf)break;
        ok = false;
        if(F >= muchii[ind].c)
        {
            F -= muchii[ind].c;
            ind++;
            ans++;
            ok = true;
        }
    }
    cout<<ans;
    return 0;
}
