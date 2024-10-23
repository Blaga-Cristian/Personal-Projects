#include <fstream>

using namespace std;
ifstream cin("sotron1.in");
ofstream cout("sotron1.out");
const int N = 245,Inf = 1e6;
int n,v[N][N],sum,maxi,ans;
/// i+j= par atunci este albastru, altfel este alb
void solve(int i,int j)
{
    if(i<1)return;
    sum += v[i][j];
    if(sum>maxi)maxi = sum;
    if(sum<0)sum = 0;
    if((i+j)%2==0)solve(i-1,j);
    else solve(i,j+1);
}
int main()
{
    cin>>n;
    ans = -Inf;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>v[i][j];
    for(int i=1;i<=n;++i)
    {
        sum = 0;
        maxi = -Inf;
        solve(i,1);
        ans = max(ans,maxi);
    }
    for(int i=1;i<=n;++i)
    {
        sum = 0;
        maxi = -Inf;
        solve(n,i);
        ans = max(ans,maxi);
    }
    cout<<ans;
    return 0;
}
