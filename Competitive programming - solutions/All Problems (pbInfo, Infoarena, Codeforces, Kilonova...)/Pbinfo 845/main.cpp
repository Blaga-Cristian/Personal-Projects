#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int p;
vector<vector<int> > v;
void matrice(int n,int i,int j)
{
    if(n>0)
    {
        int k,l;
        for(k=i;k<=i+n/2-1;k++)
            for(l=j;l<=j+n/2-1;l++)
                v[k][l]=1;
        matrice(n/2,i+n/2,j);
        matrice(n/2,i,j+n/2);
        matrice(n/2,i+n/2,j+n/2);
    }
}
int main()
{
    int n,i,j;
    cin>>n;
    p=pow(2,n);
    vector<int> v1(p+5);
    for(i=0;i<=p+5;i++)v.push_back(v1);
    matrice(p,1,1);
    for(i=1;i<=p;i++)
    {
        for(j=1;j<=p;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
