#include <fstream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
ifstream cin("graf1.in");
ofstream cout("graf1.out");

int n,m,a,b,x,y,mx,cnt;
vector<unordered_set<int>>sirad;
vector<int> dx,dy;
vector<int> apar;
vector<int> v;

void Bfs(int nod,vector<int>& traseu)
{
    queue<int> q;
    q.push(nod);

    while(!q.empty())
    {
        nod = q.front();
        q.pop();

        for(auto i : sirad[nod])
            if(traseu[i] == -1)
            {
                traseu[i] = traseu[nod] + 1;
                q.push(i);
            }
    }
}

int main()
{
    cin>>n>>m>>x>>y;
    sirad = vector<unordered_set<int>>(n+1);
    dx = vector<int>(n+1,-1),dx[x] = 0;
    dy = vector<int>(n+1,-1),dy[y] = 0;
    apar = vector<int>(n+1);

    while(m--)
    {
        cin>>a>>b;
        sirad[a].insert(b);
        sirad[b].insert(a);
    }

    Bfs(x,dx);
    Bfs(y,dy);

    int lgmin = dx[y];

    for(int i=1;i<=n;++i)
        if(dx[i] + dy[i] == lgmin)
            ++apar[dx[i]];

    for(int i=1;i<=n;++i)
        if(dx[i] + dy[i] == lgmin && apar[dx[i]]==1)
            v.push_back(i);

    cout<<v.size()<<'\n';
    for(auto i : v)
        cout<<i<<' ';
    return 0;
}
