#include <fstream>

using namespace std;
ifstream cin("gta.in");
ofstream cout("gta.out");
const int Inf = 1;
int A[1009][1009],B[1009][1009];
int g[1009],p[1009];
int n,b,t;
void interschimb()
{
    for(int i=0;i<=b;++i)
        for(int j=0;j<=t;++j)
        {
            swap(A[i][j],B[i][j]);
            B[i][j] = 0;
        }
}
int main()
{
    int K=0,x,y;
    cin>>n>>b>>t;
    for(int i=1;i<=n;++i)
        {
            cin>>x>>y;
            if(b-y>=0)
                if(x-y>=0)
            {
                K++;
                g[K] = x;
                p[K] = y;
            }
        }
    t = min(t,K);
    int ans = -1;
    for(int i=1;i<=K;++i)
    {
        for(int j = 1; j<=b;++j)
            for(int k=1;k<=t;++k)
                if(j>=p[i])
                    B[j][k] = max (A[j][k],A[j-p[i]][k-1]+g[i]-p[i]);
                else
                    B[j][k] = A[j][k];
                //ans = max(ans,B[j][k]);
        interschimb();
    }
    if(A[b][t])cout<<b+A[b][t];
    else
    {
        cin.close();
        cin.open("gta.in");
        cin>>n>>b>>t;
        int Max = -0x3f3f3f3f;
        for(int i=1;i<=n;++i)
        {
            cin>>x >>y;
            if(b>=y)
                if(Max<x-y)
                Max = x-y;
        }
        if(Max == -0x3f3f3f3f)cout<<"GIGEL NU ARE BANI";
        else cout<<b+Max;
    }
    return 0;
}
