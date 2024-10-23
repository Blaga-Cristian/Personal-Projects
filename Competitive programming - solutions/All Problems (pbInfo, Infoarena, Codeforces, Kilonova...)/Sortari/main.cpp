#include <fstream>
#include <cmath>
#define ull unsigned long long
using namespace std;
ifstream cin("sortari.in");
ofstream cout("sortari.out");
const int Mod = 19573,N = 205;
int n;
ull dp[N]; ///dp[i] = nr de permutari de i elemente care respecta cerinta
inline int mod(int a)
{
    if(a>=0)return a;
    return -a;
}
int main()
{
    cin>>n;
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    dp[3] = 6;
    for(int k=4;k<=n;++k)
    {
        for(int i=1;i<k;++i)
            for(int j=i+1;j<=k;++j)
                dp[k] += (dp[i-1]*dp[j-i-1]*dp[k-j])%Mod;
        dp[k]=(2*dp[k])%Mod;
    }
    cout<<dp[n];
    return 0;
}
