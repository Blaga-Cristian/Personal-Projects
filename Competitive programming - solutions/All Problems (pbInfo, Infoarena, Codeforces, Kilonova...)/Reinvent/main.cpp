#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream cin("reinvent.in");
ofstream cout("reinvent.out");
int n,m,x,a,b;
vector<vector<int> > sirad;
vector<int> src,dist;
int main()
{
    cin>>n>>m>>x;
    sirad = vector<vector<int>>(n+1);
    src = vector<int>(n+1);
    dist = vector<int>(n+1,-1);
    while(m--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
        sirad[b].push_back(a);
    }
    queue<int> q;
    for(int i=1;i<=x;++i)
        cin>>a,
        src[a] = a,
        dist[a] = 0,
        q.push(a);
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();

        for(auto i : sirad[nod])
        {
            if(dist[i] == -1)
            {
                dist[i] = dist[nod] + 1;
                src[i] = src[nod];
                q.push(i);
            }
            else
            {
                if(src[i] == src[nod])continue;
                cout<<dist[i] + dist[nod]+1;
                return 0;
            }
        }
    }
    return 0;
}
