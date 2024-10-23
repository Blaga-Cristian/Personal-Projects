#include <fstream>
#include <cstring>
#include <vector>
#define Nmax 1005
using namespace std;
ifstream cin("cntsq.in");
ofstream cout("cntsq.out");

int N, M;
char C[Nmax];
int A[Nmax][Nmax];
int LRU[Nmax][Nmax], CRU[Nmax][Nmax], LDL[Nmax][Nmax], CDL[Nmax][Nmax];
vector <int> E[Nmax];
int ans;
int bit[Nmax];

void update(int x,int val)
{
    for(; x <= N; x += x&-x)
        bit[x] += val;
}
int query(int x)
{
    int ret = 0;
    for(;x;x -= x&-x)
        ret += bit[x];
    return ret;
}
int main()
{
    cin>>N>>M;
    for(int i = 1; i <= N; ++i)
    {
        cin>>(C+1);
        for(int j = 1; j <= M; ++j)
            A[i][j] = C[j] - '0';
    }
    for(int i = 1; i <= N; ++i)
        for(int j =1; j <= M; ++j)
            if(A[i][j] == 1)
                LDL[i][j] = 1 + LDL[i][j-1], CDL[i][j] = 1 + CDL[i-1][j];
    for(int i = N; i >= 1; --i)
        for(int j = M; j >= 1; --j)
            if(A[i][j] == 1)
                LRU[i][j] = 1 + LRU[i][j+1], CRU[i][j] = 1 + CRU[i+1][j];

    for(int si = N, sj = 1; sj <= M; (si == 1) ? sj ++: si--)
    {
        memset(bit,0,sizeof(bit));
        for(int i = si,j = sj; i <= N && j <= M; ++i,++j)
        {
            while(!E[i].empty())
            {
                update(E[i].back(),-1);
                E[i].pop_back();
            }
            if(A[i][j] == 1)
            {
                update(i,1);
                E[i + min(LRU[i][j],CRU[i][j])].push_back(i);
                ans += query(i) - query(i - min(LDL[i][j],CDL[i][j]));
            }
        }
        E[N+1].clear();
        E[M+1].clear();
    }
    cout<<ans;
    return 0;
}
