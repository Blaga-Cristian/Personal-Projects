#include <iostream>

using namespace std;
int mat[105][106];
const int dx[] ={-1,0,1,0},dy[]={0,1,0,-1};
bool completare(int x,int y)
{
    int ok=0;
    for(int k=0;k<4;++k)
        if(mat[x+dx[k]][y+dy[k]])
    {
        mat[x][y] = mat[x+dx[k]][y+dy[k]] = 0;
        ok=1;
        break;
    }
    return ok;
}
int main()
{
    int n,m;
    int x,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
    {
        cin>>mat[i][j];
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(mat[i][j]==1)if(completare(i,j))cnt++;
    cout<<cnt;
    return 0;
}
