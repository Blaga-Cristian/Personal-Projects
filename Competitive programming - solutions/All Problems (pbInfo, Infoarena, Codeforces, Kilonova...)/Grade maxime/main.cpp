#include <fstream>
#include <vector>
using namespace std;
ifstream cin("gradmax.in");
ofstream cout("gradmax.out");
int v[100][100];
int ans[50],siz;
int main()
{
    int n,k,ind=0,maxi=-99;
    cin>>n;
    //cout<<n<<k;
    while(!cin.eof())
    {
        int a,b;
        cin>>a>>b;
        if(v[a][b]==0)v[a][0]++;
        if(v[b][a]==0)v[b][0]++;
        if(v[a][0]>maxi)maxi=v[a][0];
        if(v[b][0]>maxi)maxi=v[b][0];
        v[a][b]=1;
        v[b][a]=1;
    }
    for(int i=1;i<=n;++i)if(v[i][0]==maxi)
    {
        ans[siz++]=i;
    }
    cout<<siz<<' ';
    for(int i=0;i<siz;++i)cout<<ans[i]<<' ';
    return 0;
}
