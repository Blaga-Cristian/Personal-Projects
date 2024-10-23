#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1000000,N = 100009;
int n,nr;
bool p[MAX];
char s[N];
long long dp[N];
void Ciur()
{
    p[0] = p[1] = 1;
    for(int i=2;i<MAX;++i)
        if(p[i]==0)
            for(int j=2;i*j<MAX;++j)p[i*j] = 1;
}
int Prim(int i,int j)
{
    if(i<1)return 0;
    int x = 0;
    for(int k=i;k<=j;++k)
        x = x*10 + s[k]-'0';
    if(p[x]==0)return x;
    else return 0;
}
int main()
{
    Ciur();
    cin.get(s+1,N-3);
    n = strlen(s+1);
    for(int i=1;i<=n;++i)
        for(int k=1;k<=6;++k)
            dp[i] = max(dp[i],dp[i-k] + Prim(i-k+1,i));
    cout<<dp[n];
    return 0;
}
