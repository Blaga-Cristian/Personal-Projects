#include <fstream>
#define ull unsigned long long
using namespace std;
ifstream cin("nrsubsircresc2.in");
ofstream cout("nrsubsircresc2.out");
const int N = 406;
int v[N],n,p;
ull dp[N][N];///dp[i][j] = sunsirul strict crescator de lungime i care se termina in j
int main()
{
    cin>>n>>p;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    for(int i=1;i<=n;++i)
    {
        dp[1][i] = 1;
        for(int len = 2; len <= n;++len)
            for(int j = 1;j < i;++j)
                if(dp[len-1][j]!=0 && v[j] < v[i])
                    dp[len][i] += dp[len-1][j];
    }
    ull ans = 0;
    for(int i=1;i<=n;++i)
        ans += dp[p][i];
    cout<<ans;
    return 0;
}
