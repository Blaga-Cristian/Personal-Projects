#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("coach.in");
ofstream cout("coach.out");
using ll = long long;
const int N = 109;
const ll Inf = 0x3f3f3f3f;
ll n,m,t,a,b,c;
ll mat[N][N];
ll cal[N];
ll A[N];

ll dp[N][N];
bool found_sol = false;
int nods1,nods2,nodmx,nodmn;
void rf(int minim,int maxim)
{
    memcpy(dp,mat,sizeof(mat));
    for(int k = 1; k <= n; ++k)
        if(cal[k] >= minim && cal[k] <= maxim)
            for(int i = 1; i <= n; ++i)
                if(cal[i] >= minim && cal[i] <= maxim)
                    for(int j = 1; j <= n; ++j)
                        if(cal[j] >= minim && cal[j] <= maxim)
                            if(i != j && dp[i][j] > dp[i][k] + dp[k][j])
                                dp[i][j] = dp[i][k] + dp[k][j];
    for(int i = 1; i <= n && !found_sol; ++i)
        for(int j = 1; j <= n && !found_sol; ++j)
            if(i != j && dp[i][j] == t)
            {
                found_sol = true;
                nods1 = i;
                nods2 = j;
                nodmn = minim;
                nodmx = maxim;
            }
}

int main()
{
    memset(mat,Inf,sizeof(mat));
    cin>>n>>m>>t;

    for(int i = 1; i <= n; ++i)
        cin>>cal[i],A[i] = cal[i];
    sort(A+1,A+n+1);

    while(m--)
    {
        cin>>a>>b>>c;
        mat[a][b] = mat[b][a] = c;
    }
    for(int i = 1; i <= n; ++i)
        mat[i][i] = 0;

    for(int cmin = 1; cmin <= n && !found_sol; ++cmin)
        for(int cmax = cmin; cmax <= n && !found_sol; ++cmax)
            rf(A[cmin],A[cmax]);


    cout<<nods1<<' '<<nods2<<' '<<nodmn<<' '<<nodmx;
    return 0;
}
