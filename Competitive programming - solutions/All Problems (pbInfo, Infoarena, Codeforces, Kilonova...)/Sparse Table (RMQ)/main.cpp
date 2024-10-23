#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("rmq.in");
ofstream cout("rmq.out");
const int N = 100009,Lmax = 17;
int n,m,a,b,ST[N][Lmax],A[N];
void process()
{
    int i,j;
    for(int i=1;i<=n;++i)
        ST[i][0] = i;
    for(j=1;1<<j <= n;++j)
        for(int i=1;i + (1<<j) - 1<=n;++i)
            if(A[ST[i][j-1]] < A[ST[i+ ( 1 << (j-1) )][j-1]])
                ST[i][j] = ST[i][j-1];
            else
                ST[i][j] = ST[i+ ( 1 << (j-1) )][j-1];
}
int Query(int i,int j)
{
    int k = log2(j-i+1);
    return min(A[ST[i][k]] , A[ST[j-(1<<k)+1][k]]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>A[i];
    process();
    while(m--)
    {
        cin>>a>>b;
        cout<<Query(a,b)<<'\n';
    }
    return 0;
}
