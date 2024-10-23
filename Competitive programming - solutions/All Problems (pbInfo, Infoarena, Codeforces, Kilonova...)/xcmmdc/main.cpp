#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("xcmmdc.in");
ofstream cout("xcmmdc.out");
const int N = 1024, LogMax = 11;
int n,m,k,q;
int mat[N][N];
int ST[N][N][LogMax]; ///  dp[i][j] = latura celui mai mare patrat cu altura drepta jos in i,j si car are gcd egal cu k
long long Mars[N];
int minim, maxim, st, dr, mij, aux;

inline int gcd(int a,int b)
{
    int aux;
    while(b)
    {
        aux = a%b;
        a = b;
        b = aux;
    }
    return a;
}
void process()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            ST[i][j][0] = mat[i][j];

    for(int k = 1; 1<<k <= n; ++k)
        for(int i = 1; i + (1<<k) - 1 <= n; ++i)
            for(int j = 1; j + (1<<k) -1 <= n; ++j)
                ST[i][j][k] = gcd(ST[i][j][k-1],gcd(ST[i+(1<<(k-1))][j][k-1],gcd(ST[i][j+(1<<(k-1))][k-1],ST[i+(1<<(k-1))][j+(1<<(k-1))][k-1])));
}
int rmq(int i,int j,int len)
{
    int k = log2(len);
    return gcd(ST[i][j][k],gcd(ST[i + len - (1<<k)][j][k],gcd(ST[i][j + len - (1<<k)][k],ST[i + len - (1<<k)][j + len - (1<<k)][k])));
}

int lb(int i,int j,int st,int dr)
{
    int poz = 0,mij;
    while(st<=dr)
    {
        mij = (st+dr)>>1;
        if(k < rmq(i,j,mij))
        {
            poz = mij;
            st = mij + 1;
        }
        else
            dr = mij - 1;
    }
    return poz;
}
int ub(int i,int j,int st,int dr)
{
    int poz = dr+1,mij;
    while(st<=dr)
    {
        mij = (st+dr)>>1;
        if(k > rmq(i,j,mij))
        {
            poz = mij;
            dr = mij -1;
        }
        else
            st = mij+1;
    }
    return poz;
}
int main()
{
    cin>>n>>m>>k>>q;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>mat[i][j];
    process();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
    {
            minim = 0; st = 1; dr = min(n - i + 1, m - j + 1);
            while (st <= dr){
                mij = (st + dr) >> 1;
                aux = rmq(i,j,mij);
                if (aux > k){
                    minim = mij;
                    st = mij + 1;
                }
                else dr = mij - 1;
            }
            ++minim;
            maxim = 0; st = 1; dr = min(n - i + 1, m - j + 1);
            while (st <= dr){
                mij = (st + dr) >> 1;
                aux = rmq(i,j,mij);
                if (aux >= k){
                    maxim = mij;
                    st = mij + 1;
                }
                else dr = mij - 1;
            }
            if (minim <= maxim){
                Mars[minim]++;
                Mars[maxim+1]--;
            }
    }

    for(int i=1;i<=n || i<=m; ++i)
        Mars[i] += Mars[i-1];

    for(int i=1;i<=q;++i)
    {
        cin>>aux;
        cout<<Mars[aux]<<'\n';
    }
    return 0;
}
