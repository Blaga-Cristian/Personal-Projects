#include <iostream>
//METODA LUX
using namespace std;
int a[101][101];
int main()
{
    int n,i=1,k=1,j,y,z,nr=1;
    cin>>n;
    k=n/4;
    k=(k+1)*2;
    for(i=1;i<=k;i++)
        for(j=1;j<=n;j++)
        a[i][j]=-1;
    for(i=k+1;i<=k+2;i++)
        for(j=1;j<=n;j++)
        a[i][j]=-2;
    for(i=k+3;i<=n;i++)
        for(j=1;j<=n;j++)
        a[i][j]=-3;
    for(i=k-1;i<=k;i++)
    {
        for(j=k-1;j<=k;j++)
        a[i][j]=-2;
    }
    for(i=k+1;i<=k+2;i++)
    {
        for(j=k-1;j<=k;j++)
        a[i][j]=-1;
    }
    j=n/2;
    i=1;
    a[i][j]=nr;
    nr=2;
    while(nr-1!=n*n/4)
    {
        i=i-2;
        y=i;
        j=j+2;
        z=j;
        if(i<1)i=n-1;
        if(j>n)j=1;
        if(a[i][j]>0)
        {
            i=y+4;
            j=z-2;
        }
        a[i][j]=nr;
        nr++;
    }
    for(i=n;i>=1;i--)
    {
        for(j=n;j>=1;j--)
        {
            if(a[i][j]>0)
            {
                if(a[i][j+1]==-1)
                {
                    a[i][j+1]=a[i][j]*4-3;
                    a[i+1][j]=a[i][j]*4-2;
                    a[i+1][j+1]=a[i][j]*4-1;
                    a[i][j]=4*a[i][j];
                }
                else if(a[i][j+1]==-2)
                {
                    a[i][j+1]=a[i][j]*4;
                    a[i+1][j]=a[i][j]*4-2;
                    a[i+1][j+1]=a[i][j]*4-1;
                    a[i][j]=4*a[i][j]-3;
                }
                else if(a[i][j+1]==-3)
                {
                    a[i][j+1]=a[i][j]*4;
                    a[i+1][j]=a[i][j]*4-1;
                    a[i+1][j+1]=a[i][j]*4-2;
                    a[i][j]=4*a[i][j]-3;
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
