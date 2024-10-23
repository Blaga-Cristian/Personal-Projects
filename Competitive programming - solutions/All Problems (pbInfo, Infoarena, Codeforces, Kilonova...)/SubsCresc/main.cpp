#include <fstream>

using namespace std;
ifstream cin("nrsubsircresc.in");
ofstream cout("nrsubsircresc.out");
int n,v[305]; /// nr de subsir strict cresc ce se termina in v[i]
unsigned long long S,dp[305];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    for(int i=1;i<=n;++i)
    {
        dp[i] = 1;
        for(int j=i-1;j>=1;--j)
            if(v[i]>v[j])
                dp[i]+=dp[j];
    }
    for(int i=1;i<=n;++i)
        S += dp[i];
    cout<<S;
    return 0;
}
