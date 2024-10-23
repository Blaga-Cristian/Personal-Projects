#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("greselile.in");
ofstream fout("greselile.out");
const int M = 1e6+9;
int dp[M],n,t,x;
void Ciur(int n)
{
    for(int i = 2; i <= n;++i)
        {
            for(int j = 2; i*j <= n;++j)
                dp[i*j] = max(dp[i*j],dp[i] + 1);
        }
}
int main()
{
    fin>>n>>t;
    Ciur(n);
    while(t--)
    {
        fin>>x;
        fout<<dp[x]+1<<'\n';
    }
    return 0;
}
