#include <fstream>

using namespace std;
ifstream cin("minioni.in");
ofstream cout("minioni.out");
const int NN = 1000009, MM = 109,KK= 500;
int N,M,K,poz;
long long dp[MM][KK];
int v[MM];
inline long long suma(int n)
{
    return (long long)n*(n+1)/2;
}
inline long long rezolva(int n,int k)
{
    int p = k+1;
    int mp = n/p;
    int bp = (n+p-1)/p;
    int nmaj = n%p;
    int nmic = p - nmaj;
    return nmic*suma(mp) + nmaj*suma(bp);
}
int main()
{
    cin>>N>>M>>K;
    for(int i=1;i<=N;++i)
        cin>>poz,
        v[poz]++;
    for(int m=1;m<=M;++m)
        for(int k=0;k<=K;++k)
        {
            dp[m][k] = rezolva(v[m],0) + dp[m-1][k];
            for(int i=1;i<=k;++i)
                dp[m][k] = min(1LL*dp[m][k],dp[m-1][k-i] + rezolva(v[m],i));
        }
    cout<<dp[M][K];
    return 0;
}
