#include <fstream>
#include <vector>
using namespace std;
ifstream cin("sierpinski.in");
ofstream cout("sierpinski.out");
vector<vector<bool> > a;
int k,l,p=1;
void matrice(int n,int i,int j)
{
    if(n>0)
    {
        for(k=i+n/3;k<i+2*n/3;k++)
        {
            for(l=j+n/3;l<j+2*n/3;l++)
            {
                a[k][l]=1;
            }
        }
        matrice(n/3,i,j);
        matrice(n/3,i,j+n/3);
        matrice(n/3,i,j+2*n/3);
        matrice(n/3,i+n/3,j);
        matrice(n/3,i+n/3,j+2*n/3);
        matrice(n/3,i+2*n/3,j);
        matrice(n/3,i+2*n/3,j+n/3);
        matrice(n/3,i+2*n/3,j+2*n/3);
    }
}
int main()
{
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++)p=p*3;
    vector<bool>matrice1(p);
    for(i=1;i<=p;i++)a.push_back(matrice1);
    matrice(p,0,0);
    for(i=0;i<p;i++)
    {
        for(j=0;j<p;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
