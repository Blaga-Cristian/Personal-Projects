#include <fstream>
#include <vector>
using namespace std;
ifstream cin("graf_partial_1.in");
ofstream cout("graf_partial_1.out");
using VI = vector<int>;
using VVI = vector<VI>;
VVI v;
int main()
{
    int a,b,maxi=-191,mini=999999;
    int n,k;
    cin>>n;
    v= VVI(n+1,VI(n+1,0));
    while(cin)
    {
        cin>>a>>b;
        //cout<<a<<' '<<b<<'\n';
        if(v[a][b]==0)
        {
            v[a][b]=v[b][a]=1;
            v[a][0]++;
            v[b][0]++;
            if(v[a][0]>maxi)maxi=v[a][0];
            if(v[b][0]>maxi)maxi=v[b][0];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;++i)if(v[i][0]<mini)mini=v[i][0];
    //cout<<mini<<' '<<maxi;
    for(int i=1;i<=n;++i)
    {
        if(v[i][0]==mini)
        {
            for(int j=1;j<=n;++j)
            {
                if(j!=i)
                {
                    if(v[j][0]==maxi)
                    {
                        if(v[i][j]!=0)cnt++;
                        v[i][j]=v[j][i]=0;
                    }
                }
            }
        }
        else if(v[i][0]==maxi)
        {
            for(int j=1;j<=n;++j)
            {
                if(j!=i)
                {
                    if(v[j][0]==mini)
                    {
                        if(v[i][j]!=0)cnt++;
                        v[i][j]=v[j][i]=0;
                    }
                }
            }
        }
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
