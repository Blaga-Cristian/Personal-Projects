#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("sierpinski.in");
ofstream fout("sierpinski.out");
int a[101][101];
void sierpinski(int n,int i,int j)
{
    if(n>0)
    {
        int k,l;
        for(k=i-n/2;k<=i+n/2;k++)
            for(l=j-n/2;l<=j+n/2;l++)
            a[k][l]=1;
        sierpinski(n-1,i-n-1,j-n-1);
    }
}
int main()
{
    int n,i,p=1,j;
    fin>>n;
    for(i=1;i<=n;i++)p=p*3;
    //for(i=nr+1;i<=2*nr;i++)
    {
        //for(j=nr+1;j<=2*nr;j++)
            //a[i][j]=1;
    }
    sierpinski(p/3,p/2+1,p/2+1);
    for(i=1;i<=p;i++)
    {
        for(j=1;j<=p;j++)
        {
            fout<<a[i][j]<<" ";
        }
        fout<<endl;
    }
    return 0;
}
