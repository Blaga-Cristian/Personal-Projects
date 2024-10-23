#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("picard.in");
ofstream cout("picard.out");


const int Inf = 0x3f3f3f3f;
vector<long long>v;
int mat[110][110];
int main()
{
    int n,m,a,b,t;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j)mat[i][j]=Inf;
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b>>t;
        mat[a][b] = mat[b][a] = t;
    }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j&&mat[i][j]>mat[i][k]+mat[k][j])mat[i][j]=mat[i][k]+mat[k][j];

    long long sum = 0, maxi = 0;
    for(int i=1;i<=n;++i)
    {
        sum = 0;
        for(int j=1;j<=n;++j)
            if(mat[i][j]!=Inf)sum+=mat[i][j];
        if(sum>maxi)
        {
            maxi = sum;
            v.clear();
            v.emplace_back(i);
        }
        else if(sum==maxi)v.emplace_back(i);
    }
    sort(v.begin(),v.end());
    for(auto i:v)cout<<i<<' ';
    return 0;
}
