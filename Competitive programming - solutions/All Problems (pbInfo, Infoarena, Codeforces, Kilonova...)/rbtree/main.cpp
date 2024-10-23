#include <fstream>
#include <queue>
using namespace std;
ifstream cin("rbtree.in");
ofstream cout("rbtree.out");
const int N = 100009,Inf = 0x3f3f3f3f;
int n,r,b,nr,x,y;
int red[N],black[N];
vector<vector<int>>sirad;
vector<vector<int>>siradtr;
vector<int> distred,distblack,distrad;

queue<int> q;
void Bfs(vector<int>& traseu,vector<vector<int>>& ad)
{
    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto i : ad[x])
            if(traseu[i] > traseu[x] + 1)
            {
                traseu[i] = traseu[x] + 1;
                q.push(i);
            }
    }
}
int main()
{
    cin>>n>>r>>b;
    siradtr = sirad = vector<vector<int>>(n+1);
    distred = distrad = distblack = vector<int>(n+1,Inf);
    distrad[1] = 0;
    for(int i=1;i<=r;++i)
        cin>>red[i],distred[red[i]]=0;
    for(int j=1;j<=b;++j)
        cin>>black[j],distblack[black[j]]=0;

    for(int i=1;i<=n;++i)
    {
        cin>>nr;
        while(nr--)
        {
            cin>>x;
            sirad[i].push_back(x);
            siradtr[x].push_back(i);
        }
    }

    q.push(1);
    Bfs(distrad,sirad);

    for(int i=1;i<=r;++i)
        q.push(red[i]);
    Bfs(distred,siradtr);

    for(int i=1;i<=b;++i)
        q.push(black[i]);
    Bfs(distblack,siradtr);

    long long ans =Inf;
    int nod;
    for(int i=1;i<=n;++i)
        ans = min(ans,(long long)distrad[i] + distred[i] + distblack[i]);
    if(ans==Inf)
        cout<<"impossible";
    else
        cout<<ans;
    return 0;
}
