#include <fstream>
#include <stack>
using namespace std;
ifstream cin("smax.in");
ofstream cout("smax.out");
const int N = 102;
short int dp[N][N][N],a[N][N][N];
int n,m,b,x,y;
struct nod
{
    short int k,i,j;
};
stack<nod> stk;
void drum(int k,int i,int j)
{
    stk.push({k,i,j});
    if( k == i && k == j && k == 1)
        return;
    else if(k != 1 && dp[k-1][i][j] == dp[k][i][j] - a[k][i][j])
        drum(k-1,i,j);
    else if(i != 1 && dp[k][i-1][j] == dp[k][i][j] - a[k][i][j])
        drum(k,i-1,j);
    else if(j != 1 && dp[k][i][j-1] == dp[k][i][j] - a[k][i][j])
        drum(k,i,j-1);
}
int main()
{
    cin>>n;
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cin >> a[k][i][j];

    for(int k = n; k >= 1; --k)
        for(int i = n; i >= 1; --i)
            for(int j = n; j >= 1; --j)
                dp[k][i][j] = a[k][i][j] + max(dp[k+1][i][j],max(dp[k][i+1][j],dp[k][i][j+1]));

    cout<<3*n-2<<'\n';
    cout<<dp[1][1][1]<<'\n';
    int i,j,k;
    i = j = k = 1;
    cout<<i<<' '<<j<<' '<<k<<'\n';
    do
    {
        if(j!=n && dp[k][i][j] - a[k][i][j] == dp[k][i][j+1])++j;
        else if(i != n && dp[k][i][j] - a[k][i][j] == dp[k][i+1][j])++i;
        else ++k;
        cout<<k<<' '<<i<<' '<<j<<'\n';
    }
    while(i != n || j != n || k != n);
    return 0;
}
