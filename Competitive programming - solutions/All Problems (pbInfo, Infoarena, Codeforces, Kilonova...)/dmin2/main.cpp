#include <fstream>
#include <vector>
#include <queue>
using namespace std;
string f = "dmin2.";
ifstream cin(f+"in");
ofstream cout(f+"out");

int n,m,a,b,k,x,y;
vector<vector<int>>sirad;
vector<int> dist;
void Bfs(int x)
{
    queue<int> q;
    q.push(x);
    dist[x] = 1;
    while(!q.empty())
    {
        x = q.front();
        q.pop();

        for(auto i : sirad[x])
            if(dist[i] == 0)
            {
                dist[i] = dist[x] + 1;
                q.push(i);
            }
    }
}
int main()
{
    cin>>n>>m;
    sirad = vector<vector<int>>(n+1);
    while(m--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
    }
    cin>>k;
    while(k--)
    {
        cin>>x>>y;
        dist = vector<int>(n+1);
        Bfs(x);
        if(dist[y] == 0)cout<<"-1\n";
        else cout<<dist[y]-1<<'\n';
    }
    return 0;
}
