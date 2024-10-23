#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("gasti.in");
ofstream cout("gasti.out");
#define mod (666013)

long long total;
int cnt,gasti,maxi1,maxi2,cnt1,cnt2,cate[100009];
vector<vector<int> >sirad;
vector<int >vec;
bool viz[100009];
void dfs(int node)
{
    ++cnt;
    viz[node]=1;
    for(auto i:sirad[node])
        if(!viz[i])dfs(i);
}

int main()
{
    int n,m,a,b;
    cin>>n>>m;
    sirad = vector<vector<int> >(n+1);
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        sirad[a].emplace_back(b);
        sirad[b].emplace_back(a);
    }
    for(int i=1;i<=n;++i)
    if(!viz[i])
    {
        cnt=0;
        dfs(i);
        gasti++;
        cate[cnt]++;
        vec.emplace_back(cnt);
    }
    sort(vec.begin(),vec.end(),greater<int>());
    maxi1=vec[0];
    cnt1 = cate[vec[0]];
    maxi2=vec[1];
    cnt2 = cate[vec[1]];
    long long x,y;
    if(maxi1!=maxi2)
    {
        x=(1LL*maxi1*cnt1)%mod;
        y=(1LL*maxi2*cnt2)%mod;
    }
    else
    {
        x=(1LL*maxi1*maxi1)%mod;
        y=(1LL*cnt1*(cnt1-1)/2)%mod;
    }
    long long rez=(x*y)%mod;
    cout<<gasti<< ' '<<rez;
    return 0;
}
