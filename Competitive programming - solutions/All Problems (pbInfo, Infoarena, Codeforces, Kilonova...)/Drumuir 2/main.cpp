#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const string f = "drumuri.";
ifstream cin(f + "in");
ofstream cout(f + "out");

int n,m,a,b,x,y,cnt,node;
vector<vector<int>>sirad;
vector<int> in,out;
vector<int> dist;
vector<bool> viz;
vector<int> ans;
void Dfs(int x)
{
    viz[x] = true;
    for(auto i : sirad[x])
    {
        if(!viz[i])
            Dfs(i);
        dist[x] = max(dist[x],dist[i]+1);
    }
}
void CalcDist()
{
    for(int i=1;i<=n;++i)
        if(!viz[i])Dfs(i);
}
void Count()
{
    priority_queue<pair<int,int>>q;
    vector<bool>inq(n+1);
    for(int i=1;i<=n;++i)
            if(in[i]==0)
            {
                q.push({dist[i],i});
                inq[i] = true;
            }
    while(!q.empty())
    {
        int dx = q.top().first;
        if(q.size() == 1)ans.push_back(q.top().second);
        while(!q.empty() && q.top().first == dx)
        {
            node = q.top().second;
            q.pop();
            for(auto i : sirad[node])
            {
                in[i]--;
                if(!inq[i])
                {
                    q.push({dist[i],i});
                    inq[i] = true;
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    sirad = vector<vector<int>>(n+1);
    in = out = vector<int>(n+1);
    viz = vector<bool>(n+1);
    dist = vector<int>(n+1);
    while(m--)
    {
        cin>>a>>b;
        out[a]++;
        in[b]++;
        sirad[a].push_back(b);
    }

    CalcDist();///imi pune distantele maxime in vectorul dist

    Count();

    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto i : ans)
        cout<<i<<' ';
    return 0;
}
