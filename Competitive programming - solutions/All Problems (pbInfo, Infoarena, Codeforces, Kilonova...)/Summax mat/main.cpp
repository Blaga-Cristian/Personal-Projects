#include <fstream>

using namespace std;
ifstream cin("summax.in");
ofstream cout("summax.out");
int n,v[11][11],sum=0,sum1=0,b[11];
bool p[11];
void verificare()
{
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<'\n';
    for(int i=0;i<n;i++)sum1+=v[i][b[i]];
    if(sum1>sum)sum=sum1;
    sum1=0;
}
void backtracking(int x)
{
    for(int i=0;i<n;i++)
    {
        if(p[i]==0)
        {
            p[i]=1;
            b[x]=i;
            if(x==n-1)verificare();
            else backtracking(x+1);
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    backtracking(0);
    cout<<sum;
    return 0;
}
