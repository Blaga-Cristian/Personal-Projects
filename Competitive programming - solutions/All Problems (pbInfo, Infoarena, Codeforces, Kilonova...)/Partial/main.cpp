#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
ifstream fin("partial.in");
ofstream fout("partial.out");
int n,m,g;
vector<vector<bool> > matad;
vector<bool> viz;
vector<vector<bool> > ans;
int cnt;
void Dfs(int x)
{
    viz[x]=true;
    for(int i=1;i<=n;++i)
    {
        if(matad[x][i]==true&&viz[i]==false)
        {
            ans[x][i] = ans[i][x] = true;
            Dfs(i);
        }
    }
}
int main()
{
    int a,b,x,k;
    fin>>n;
    matad = ans = vector<vector<bool> >(n+1,vector<bool>(n+1));
    viz = vector<bool>(n+1);
    while(fin>>a>>b)
    {
        m++;
        matad[a][b] = matad[b][a] = 1;
    }
    Dfs(1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            if(ans[i][j]==false&&matad[i][j]==true&&cnt<m/2)
            {
                matad[i][j] = matad[j][i] = 0;
                cnt++;
            }
    for(int i=1;i<=n;++i,fout<<'\n')
        for(int j=1;j<=n;++j)
            fout<<matad[i][j]<<' ';
    return 0;
}
