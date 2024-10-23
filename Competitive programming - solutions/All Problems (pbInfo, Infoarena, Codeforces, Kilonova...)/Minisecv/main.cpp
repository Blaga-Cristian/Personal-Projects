#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("2-minisecvente.in");
ofstream cout("minisecvente.out");


const int N = 100009,Lmax = 17;
int n,ST[N][Lmax],A[N],dp[N]; /// dp[i] = nnr de secvente ce se termina in i
void process()
{
    int i,j;
    for(int i=1;i<=n;++i)
        ST[i][0] = i;
    for(j=1;1<<j <= n;++j)
        for(int i=0;i + (1<<j) - 1<=n;++i)
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
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>A[i];
    process();
    int cnt = 0;
    for(int i=1;i<=n;++i)
    {
        int le = i, ri = n,poz = -1;
        while(le<=ri)
        {
            int mij = (le+ri)>>1;
            if(mij -i +1 > Query(i,mij))
                poz = mij,
                ri = mij-1;
            else
                le = mij+1;
        }
        if(poz==-1)continue;

        cnt += n-poz +1;
    }
    cout<<cnt;
    return 0;
}
