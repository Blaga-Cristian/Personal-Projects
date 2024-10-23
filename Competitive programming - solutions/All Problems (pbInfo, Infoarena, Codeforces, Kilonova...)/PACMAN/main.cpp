#include <iostream>

using namespace std;
long long mat[40][40];
int main()
{
    int n,m;
    cin>>n>>m;
    mat[1][1]=1;
    for(int i=1;i<=n;++i)
        for(int j=2;j<=m;++j)
            mat[i][j] = mat[i-1][j-1]+mat[i][j-1];
    cout<<mat[n][m];
    return 0;
}
