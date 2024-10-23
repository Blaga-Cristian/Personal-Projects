#include <iostream>
using namespace std;
int v[502][502];
int main()
{
    int n,i,j,Q,c1,l1,c2,l2,val;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>v[i][j];
    cin>>Q;
    for(int k=1;k<=Q;k++)
    {
        cin>>l1>>c1>>l2>>c2>>val;
        for(i=l1;i<=l2;i++)
            for(j=c1;j<=c2;j++)
                v[i][j]=v[i][j]+val;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
