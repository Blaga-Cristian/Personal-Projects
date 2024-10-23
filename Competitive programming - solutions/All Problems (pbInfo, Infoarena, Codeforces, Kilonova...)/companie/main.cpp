#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 9;
int n,m,a,b,c,x,y,rad,q,k,p[N],F[N],sumprime[N],loc[N];
vector<vector<int>>sirad;
vector<int> arb;
void Euler(int x,int parent)
{

}
void Dfs(int x,int parent) ///iau distantele
int main()
{
    cin>>n;
    sirad = vector<vector<int>>(n+1);
    arb = vector<int>(2*n+1);
    for(int i=1;i<=n;++i)
        cin>>p[i];
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
        sirad[b].push_back(a);
    }
    cin>>m;
    for(int i=1;i<=m;++i)
        cin>>F[i];
    return 0;
}
