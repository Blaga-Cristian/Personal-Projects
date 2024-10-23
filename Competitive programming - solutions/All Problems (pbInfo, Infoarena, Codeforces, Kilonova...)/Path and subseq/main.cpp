#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
using pi = pair<int,int>;
const int N = 1e5 + 9, Inf = 0x3f3f3f3f;
int n,m,k,a,b,A[N],B[N];
int d[N];
vector<vector<int>> G;


bool Dij()
{
    priority_queue<pi,vector<pi>,greater<pi>> q;
    d[1] = (A[1] == B[1]);
    q.push({d[1],1});

    while(!q.empty())
    {
        int dx = q.top().first,
        x = q.top().second;
        q.pop();

        if(dx > d[x])continue;

        for(auto y : G[x])
            if(d[y] > d[x] + (A[y] == B[dx+1]))
            {
                d[y] = d[x] + (A[y] == B[dx+1]);
                q.push({d[y],y});
            }
    }

    return (d[n] == k);
}

int main()
{
    memset(d,Inf,sizeof(d));
    cin>>n>>m>>k;
    G = vector<vector<int>>(n+1);
    while(m--)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 1; i <= n; ++i)
        cin>>A[i];
    for(int i = 1; i <= k; ++i)
        cin>>B[i];

    Dij() ? cout<<"Yes" : cout<<"No";
    return 0;
}
