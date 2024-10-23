#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
ifstream cin("lantminim.in");
ofstream cout("lantminim.out");
int n,p,q,mini=999999;
int traseu[101];
vector<int> ans;
bool matad[100][100];
bool viz[100];
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    traseu[x]=1;
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        for(int i=1;i<=n;++i)
        {
            if(traseu[i]==0&&matad[a][i]==1)
            {
                q.push(i);
                traseu[i]=traseu[a]+1;
            }
        }
    }
}
void drum(int x)
{
    ans.push_back(x);
    if(x==p||traseu[x]==0)return;
    else
    {
        for(int i=n;i>=1;--i)
        {
            if(traseu[x]==traseu[i]+1 && matad[x][i]==1)
            {
                drum(i);
                break;
            }
        }
    }
}
int main()
{
    int a,b;
    cin>>n>>p>>q;
    while(cin)
    {
        cin>>a>>b;
        matad[a][b]= matad[b][a]=1;
    }
    bfs(p);
    drum(q);
    reverse(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<' ';
}
