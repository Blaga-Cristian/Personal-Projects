#include <iostream>
#include <cmath>
using namespace std;
int a[1000][1000];
void matrice(int i,int j,int n)
{
    if(n>0)
    {
        int k,p=1;
        for(k=1;k<n;k++)p=p*2;
        a[i+p-1][j+p-1]=n;
        matrice(i,j,n-1);
        matrice(i,j+p,n-1);
        matrice(i+p,j,n-1);
        matrice(i+p,j+p,n-1);
    }
}
int main()
{
    int n,p=1,i=1,j=1;
    cin>>n;
    p=pow(2,n);
    matrice(i,j,n);
    for(i=1;i<p;i++)
    {
        for(j=1;j<p;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
