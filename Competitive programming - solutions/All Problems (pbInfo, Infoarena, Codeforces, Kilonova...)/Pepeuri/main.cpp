#include <fstream>

using namespace std;
ifstream cin("pepeuri.in");
ofstream cout("pepeuri.out");
const int Mod = 10111121;
/// dp[i][j] = nr de i cifre ce se termina in j
long long n , m , k , i , j , a[10] , p[10][10] , b[10][10] ,c[10][10] , sol , suma , cif[31],u ,t ,d ;
void ridiclapatrat()
{
    for(int i=0;i<=9;++i)
        for(int j=0;j<=9;++j)
    {
        c[i][j] = 0;
        for(int k=0;k<=9;++k)c[i][j] = (c[i][j] + p[i][k]*p[k][j])%Mod;
    }
    for(int i=0;i<=9;++i)
        for(int j=0;j<=9;++j)
            p[i][j] = c[i][j];
}
void inmultesc()
{
    for(int i=0;i<=9;++i)
        for(int j=0;j<=9;++j)
    {
        c[i][j] = 0;
        for(int k=0;k<=9;++k)
            c[i][j] = (c[i][j] + p[i][k]*b[k][j])%Mod;
    }
    for(int i=0;i<=9;++i)
        for(int j=0;j<=9;++j)
            p[i][j] = c[i][j];
}
int main()
{
    cin>>n;
    if(n==1)
    {
        cout<<4;
        return 0;
    }
    n = n-2;
    a[0]=3;a[1]=2;a[2]=2;a[3]=2;a[4]=1;a[5]=1;a[6]=1;a[7]=2;a[8]=2;a[9]=1;
    for(i=0;i<=9;i++)p[i][i]=1;
    b[0][0]=1;
    b[0][1]=1;
    b[1][0]=1;
    for(i=0;i<=4;i++)b[i][4-i]=1;
    for(i=0;i<=9;i++)b[i][9-i]=1;
    b[7][9]=1;
    b[8][8]=1;
    b[9][7]=1;
    while(n)
    {
        if()
    }
    return 0;
}
