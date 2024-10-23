#include <fstream>
#include <vector>
#include <queue>
#define g(a) (sirad[a].size())
using namespace std;
ifstream cin("metrou.in");
ofstream cout("metrou.out");
const int N = 100009,Inf = 0x3f3f3f3f;
int n,m,a,b,x,y;
int p[N];
vector<vector<int>>sirad;
int dp[4][N];
/**
dp[0][i] = excludem primul si ultimul nod din lant
dp[1][i] = excludem primul nod din lant
dp[2][i] = excludem ultimul nod din lant
dp[3][i] = nu excludem nici un nod din lant
*/

int main()
{
    cin>>n>>m;
    sirad = vector<vector<int>>(n+1);
    for(int i=1;i<=n;++i)
        cin>>p[i];
    for(int i=1;i<=m;++i)
    {
        cin>>x>>y;
        sirad[x].push_back(y);
        sirad[y].push_back(x);
    }
    solve();
    return 0;
}
