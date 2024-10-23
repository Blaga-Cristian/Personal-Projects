#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <cstring>

using namespace std;
ifstream cin("cmcm.in");
ofstream cout("cmcm.out");
using pi = pair<int,int>;
using VI = vector<pi>;
using VVI = vector<VI>;
const int N = 705,Inf = 0x3f3f3f3f;
int n,m,C[N][N],t[N],e,a,b,c;
int d[N];
bitset<N> inQ;

VVI G;

bool BFord(int source,int sink)
{
    inQ.reset();
    memset(d,Inf,sizeof(d));
    queue<int> q;
    d[source] = 0;
    q.push(source);
    inQ[source] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        inQ[x] = false;

        for(auto i : G[x])
        {
            int y = i.first,
            w = i.second;

            if(d[y] > d[x] + w && C[x][y])
            {
                d[y] = d[x] + w;
                t[y] = x;

                if(!inQ[y])
                {
                    q.push(y);
                    inQ[y] = true;
                }
            }
        }
    }

    return (d[sink] != Inf);
}

void Augment(int source,int sink)
{
    for(int i = sink; i != source; i = t[i])
    {
        C[t[i]][i] --;
        C[i][t[i]] ++;
    }
}

pi MaxFlow(int source,int sink)
{
    int maxflow = 0,cost = 0;
    for(; BFord(source,sink); ++maxflow,cost += d[sink])
        Augment(source,sink);
    return {maxflow,cost};
}

struct muchie
{
    int a,b,ind;
};
vector<muchie> muchii;

int main()
{
    cin>>n>>m>>e;
    G = VVI(n+m+2);
    for(int i = 1; i <= e; ++i)
    {
        cin>>a>>b>>c;
        G[a].push_back({b + n,c});
        G[b + n].push_back({a,-c});
        muchii.push_back({a,b+n,i});
        C[a][b+n] ++;
    }

    for(int i = 1; i <= n; ++i)
    {
        G[0].push_back({i,0});
        C[0][i] = 1;
    }
    for(int i = n + 1; i <= n + m; ++i)
    {
        G[i].push_back({n+m+1,0});
        C[i][n+m+1] = 1;
    }

    auto ans = MaxFlow(0,n+m+1);
    cout<<ans.first<<' '<<ans.second<<'\n';
    for(auto m : muchii)
        if(C[m.a][m.b] == 0)
            cout<<m.ind<<' ';
    return 0;
}