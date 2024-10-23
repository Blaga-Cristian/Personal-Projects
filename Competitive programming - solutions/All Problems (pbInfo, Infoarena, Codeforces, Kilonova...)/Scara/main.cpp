#include <fstream>

using namespace std;
ifstream cin("scara.in");
ofstream cout("scara.out");
const int N = 125;
int n,poz,cant,k,j,Inf = 0x3f3f3f3f;
struct scara
{
    int apa,energ;
}v[N];
int dp[N][N]; ///dp[poz][k] = costul minim pentru a urcam la pozitia poz in k pasi
bool p[N][N]; ///p[poz][k] = daca exista un mod de a ajunge la pozitia poz cu k pasi
int main()
{
    cin>>n;
    cin>>k;
    for(int i=1;i<=k;++i)
    {
        cin>>poz>>cant;
        v[poz].apa = cant;
    }
    cin>>j;
    for(int i=1;i<=j;++i)
    {
        cin>>poz>>cant;
        v[poz].energ = cant;
    }

    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dp[i][j] = Inf;



    ///incep rezolvarea problemei
    dp[1][1] = 0;
    p[1][1] = 1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            if(p[i][j])
            {
                p[i+1][j+1] = 1;
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]);

                if(v[i].apa)
                {
                    for(int l = 1; l <= v[i].apa && l+i <= n ; ++l)
                    {
                        p[i+l][j+1] = 1;
                        dp[i+l][j+1] = min(dp[i+l][j+1],dp[i][j]);
                    }
                }

                if(v[i].energ)
                {
                    for(int l = 1; l <= v[i].energ; ++l)
                    {
                        for(int q = 1; q<= 2*l && i+q <= n; ++q)
                        {
                            p[i+q][j+1] = 1;
                            dp[i+q][j+1] = min(dp[i+q][j+1],dp[i][j] + l);
                        }
                    }
                }
            }
    }
    for(int i=1;i<=n;++i)
    {
        if(p[n][i])
        {
            cout<<i<<' '<<dp[n][i];
            break;
        }
    }
    return 0;
}
