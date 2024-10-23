#include <fstream>
#include <vector>
using namespace std;
ifstream cin("triunghi4.in");
ofstream cout("triunghi4.out");
const int N = 2500,M = 900;
int n,m,p,r,poz;
long long mat[N][N];
long long Mars[5*N];
int main()
{
    cin>>n>>m>>p;
    for(int i=1;i<=n;++i)
        for(int j = M - i + 1; j <= M + i -1 ;++j)
            mat[i][j] = 1;
    while(m--)
    {
        cin>>r>>poz;
        mat[r][poz - r + M] = 0;
    }
    vector<int> ans;
    for(int i=1;i<=p;++i)
    {
        int x;
        cin>>x;
        ans.push_back(x);
    }

    for(int i=n;i>=1;--i)
        for(int j = M - i + 1;j <= M + i -1;++j)
            if((j - (M - i + 1))%2 == 0)
            {
                if(mat[i][j] == 1 && mat[i+1][j] == 1)
                    mat[i][j] = min(mat[i+1][j-1],mat[i+1][j+1]) + 1;
                Mars[1]++;
                Mars[mat[i][j]+1]--;
            }
    for(int i=2;i<=5*n;++i)
        Mars[i] = Mars[i-1] + Mars[i];
    for(auto i : ans)
        cout<<Mars[i]<<'\n';
    return 0;
}
