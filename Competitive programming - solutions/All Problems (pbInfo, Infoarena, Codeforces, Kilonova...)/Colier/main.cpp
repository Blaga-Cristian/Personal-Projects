#include <fstream>
#include <queue>
using namespace std;
ifstream cin("colier.in");
ofstream cout("colier.out");
priority_queue<int,vector<int>,greater<int> > q;
int n,m,b[13],ans[13],maxi,sumi,cnt;
bool p[13];
struct mar
{
    int cul,str;
}v[13];
void afisare(int sum)
{
    if(sum==sumi)
    {
        cnt=1;
        maxi=sumi;
        for(int i=0;i<m;++i)ans[i]=b[i];
    }
    else if(sum>maxi)
    {
        maxi=sum;
        for(int i=0;i<m;++i)ans[i]=b[i];
    }
}
bool verificare(int i,int x)
{
    if(p[i]==1)return false;
    if(x>0)
    {
        if(v[b[x-1]].cul==v[i].cul)return false;
        if(x==m-1)if(v[b[0]].cul==v[i].cul)return false;
    }
    return true;
}
void backt(int x,int sum)
{
    for(int i=0;i<n&&!cnt;++i)
    {
        if(verificare(i,x))
        {
            p[i]=1;
            b[x]=i;
            sum+=v[i].str;
            if(x==m-1)afisare(sum);
            else backt(x+1,sum);
            sum-=v[i].str;
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>v[i].cul>>v[i].str,q.push(v[i].str);
    while(q.size()>m)q.pop();
    while(!q.empty())sumi+=q.top(),q.pop();
    backt(0,0);
    for(int i=0;i<m;++i)cout<<ans[i]+1<<' ';
    return 0;
}
