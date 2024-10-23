#include <iostream>

using namespace std;

int main()
{
    int a[100][100],i,j,m,n,k=0,s=0;
    cin>>m>>n;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]%2==0)k++;
            else s++;
        }
    }
    cout<<s<<" nr impare "<<k<<" nr pare";
    return 0;
}
