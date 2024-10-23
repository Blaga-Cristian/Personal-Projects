#include <cstdio>
#include <fstream>
#include <vector>
using namespace std;
FILE* in = fopen("numere19.in","rb");
FILE* out = fopen("numere19.out","wb");
const int A = 9005,mod = 9973;
int a,b;
int dp[2][A]; /// dp[i][j] = nr de numere care au i cifre si produsul cifrelor egal cu j
int cur = 1,pre = 0,mx,premx;
vector<int> divizori;
int main()
{
    fscanf(in,"%d %d",&a,&b);
    for(int i=0;i<=9;++i)
        dp[pre][i] = 1;
    mx = 9;
    premx = 0;
    for(int i=1;i<=b;++i)
        if(b%i==0)
            divizori.push_back(i);
    for(int i=1;i<a;++i,cur = cur^1,pre = pre^1)
    {
        for(auto j : divizori)
            dp[cur][j] = 0;
        premx = mx;
        for(auto j : divizori)
            if(dp[pre][j])
                for(int k=1;k<=9;++k)
                    if(j*k<=b/2 || j*k == b)
                    {
                        dp[cur][j*k] = dp[cur][j*k] + dp[pre][j];
                        if (dp[cur][j*k] >= mod)
                            dp[cur][j*k] -= mod;
                        if(j*k > mx)mx = j*k;
                    }
    }
    fprintf(out,"%d",dp[pre][b]);
    return 0;
}
