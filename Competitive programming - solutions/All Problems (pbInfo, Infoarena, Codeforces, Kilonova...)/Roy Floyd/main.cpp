#include <fstream>

using namespace std;
ifstream cin("royfloyd.in");
ofstream cout("royfloyd.out");
const int N = 109,Inf = 0x3f3f3f3f;
int n,v[N][N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            cin>>v[i][j];
            if(v[i][j] == 0) v[i][j] = Inf;
        }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j)
                    v[i][j] = min(v[i][j],v[i][k] + v[k][j]);
    for(int i=1;i<=n;++i,cout<<'\n')
        for(int j=1;j<=n;++j)
            cout<<((v[i][j] == Inf) ? 0 : v[i][j])<<' ';
    return 0;
}
