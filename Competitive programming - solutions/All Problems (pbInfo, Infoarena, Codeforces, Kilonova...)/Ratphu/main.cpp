#include <fstream>

using namespace std;
ifstream cin("ratphu.in");
ofstream cout("ratphu.out");

const int N = 19;
long long dp[1<<N][20];
string nr;
int p;
int main()
{
    cin>>nr>>p;
    int n = nr.size();
    dp[0][0] = 1;

    for(int s = 0; s < (1<<n); ++s)
        for(int r = 0; r < p; ++r)
            for(int i = 0; i < n; ++i)
                if(!(s&(1<<i)))
                    dp[s | (1<<i)][(r * 10 + nr[i] - '0')%p] += dp[s][r];
    cout<<dp[(1<<n)-1][0];
    return 0;
}
