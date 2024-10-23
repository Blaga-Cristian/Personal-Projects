#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
ifstream cin("text.in");
ofstream cout("text.out");
const int Dim = 205, N = 100,mod = 1000003,Inf = 0x3f3f3f3f;
int n;
char s[Dim];
int dp[N][N],cnt[N][N],pr[N][N],len;///dp[i][j] = armonia maxima a cuvintelor foramte dinliterele din intervalul 1..j si au i cuvinte
/// cnt[i][j] = nr de impartiri a unei secvente de la 1..j in i cuvinte
bool vocala[N][N]; /// vocala[i][j] = daca exista o vocala intre i,j
void vocale()
{
    for(int i=1;i<=len;++i)
        if(strchr("aeiouy",s[i-1])!=NULL)vocala[i][i] = 1;
    for(int i=1;i<=len;++i)
        for(int j=i;j<=len;++j)
            vocala[i][j] = (vocala[i][j-1]||vocala[j][j]);
}
void afisare(int k,int i,int stop)
{
    if(k==1)
    {
        for(int l=1;l<=stop;++l)
            cout<<s[l-1];
        cout<<' ';
        return;
    }
    afisare(k-1,pr[k-1][pr[k][i]-1],pr[k][i]-1);
    for(int l = pr[k][i];l<=stop;++l)
        cout<<s[l-1];
    cout<<' ';
}
int main()
{
    cin>>s;
    cin>>n;
    len = strlen(s);

    vocale();

    for(int i=1;i<=n;++i)
        for(int j=1;j<=len;++j)
            dp[i][j] = Inf,
            pr[i][j] = Inf;
    for(int i=1;i<=20&&i<=len;++i)
        if(vocala[1][i])
    {
        dp[1][i] = i*i;
        cnt[1][i] = 1;
    }
    for(int k=2;k<=n;++k)
        for(int i=1;i<=len;++i)
            for(int j = max(1,i-19);j<=i;++j)
                if(vocala[j][i])
                {
                    if(dp[k][i] > dp[k-1][j-1] + (i-j+1)*(i-j+1))
                    {
                        dp[k][i] = dp[k-1][j-1] + (i-j+1)*(i-j+1);
                        pr[k][i] = j;
                    }
                }

    for(int k=2;k<=n;++k)
        for(int i=1;i<=len;++i)
            for(int j = max(1,i-19);j<=i;++j)
                if(vocala[j][i])
                    cnt[k][i] += cnt[k-1][j-1];

    cout<<cnt[n][len]<<'\n';
    cout<<dp[n][len]<<'\n';
    afisare(n,len,len);
    return 0;
}
