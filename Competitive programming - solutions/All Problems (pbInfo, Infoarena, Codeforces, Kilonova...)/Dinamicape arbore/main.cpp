#include <fstream>
#include <vector>
using namespace std;
ifstream cin("arbore1.in");
ofstream cout("arbore1.out");
const int N = 100009,mod = 1000000007;
int n;
vector<vector<int> >sirad;
long long nr[3][N],dp[3][N];
///nr[0][N] - nr de comp daca NU elimin
///nr[1][N] - nr de comp daca elimin
///dp[0][N] - nr de mod de obt daca NU elimin
///dp[1][N] - nr de mod de obt daca elimin
void Dfs(int x,int parent)
{
    nr[1][x] = 1;
    nr[0][x] = 0;
    nr[2][x] = 1;
    dp[1][x] = 1;
    dp[0][x] = 1;
    dp[2][x] = 1;
    for(auto i : sirad[x])
    {
        if(i==parent)continue;
        Dfs(i,x);
    }

    ///Sterg nodul
    for(auto i : sirad[x])
    {
        if(i==parent)continue;
        nr[0][x] += nr[2][i];
        dp[0][x] *= dp[2][i];
        dp[0][x] %= mod;
    }

    ///Nu sterg nodul
    for(auto i : sirad[x])
    {
        if(i==parent)continue;
        if(nr[0][i] + 1 == nr[1][i])
        {
            dp[1][x] *= (dp[0][i] + dp[1][i])%mod;
            dp[1][x] %= mod;
            nr[1][x] += nr[0][i];
        }
        else if(nr[0][i] + 1 < nr[1][i])
        {
            dp[1][x] *= dp[1][i];
            dp[1][x] %= mod;
            nr[1][x] += nr[1][i]-1;
        }
        else
        {
            dp[1][x] *= dp[0][i];
            dp[1][x] %= mod;
            nr[1][x] += nr[0][i];
        }
    }

    ///calculez solutia
    nr[2][x] = max(nr[0][x],nr[1][x]);
    if(nr[1][x] == nr[0][x])
        dp[2][x] = (dp[1][x] + dp[0][x])%mod;
    else if(nr[1][x]>nr[0][x])
        dp[2][x] = dp[1][x];
    else
        dp[2][x] = dp[0][x];
}
int main()
{
    int a,b;
    cin>>n;
    sirad = vector<vector<int>>(n+1);
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
        sirad[b].push_back(a);
    }
    Dfs(1,0);
    cout<<nr[2][1]<<' '<<dp[2][1];
    return 0;
}
