#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("himalaya.in");
ofstream cout("himalaya.out");
const int N = 505;

int n,k,c1,c2;
int dp[N][N],H[N]; /// dp[i][j] = valoarea maxima pe dp[i][j], cu i opriri si care se termina in j
int val(int a,int b)
{
    if(a<=b)
        return abs(a-b)*c1;
    return abs(a-b)*c2;
}
int main()
{
    cin>>n>>k>>c1>>c2;
    for(int i=1;i<=n;++i)
        cin>>H[i];
    for(int i=1;i<=n;++i)
        dp[1][i] = val(H[1],H[i]);
    for(int i=2;i<=k;++i)
    {
        for(int i)
    }
    return 0;
}
