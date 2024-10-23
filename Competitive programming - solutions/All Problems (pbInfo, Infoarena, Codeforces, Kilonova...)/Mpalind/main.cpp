#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("mpalind.in");
ofstream cout("mpalind.out");
const int MOD = 666013;
char s[1008];
int dp[1008][1008],m,x,y,sum=0,n;
bool P[1008][1008];
bool Palindrom(int st,int dr)
{
    while(st<dr)
    {
        if(s[st]!=s[dr])return 0;
        st++;
        dr--;
    }
    return 1;
}
void dynamic()
{
    int i,j,k,p;
    for(i=0;i<n;++i)
        for(j=i;j<n;++j)
            P[i][j]=Palindrom(i,j);
    for(i=0;i<n;++i)
        dp[i][i]=1;
    for(k=2;k<=n;++k)
        for(i=0;i<=n-k;++i)
        {
            j=i+k-1;
            dp[i][j]+=P[i][j];
            for(p=i;p<j;++p)
                if(P[i][p])
                    dp[i][j]=(dp[i][j]%MOD+dp[p+1][j]%MOD)%MOD;
        }
}
int main()
{
    cin.getline(s,1008);
    n = strlen(s);
    dynamic();
    cin>>m;
    while(m--)
    {
        cin>>x>>y;
        cout<<dp[x-1][y-1]<<'\n';
    }
    return 0;
}
