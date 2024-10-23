#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("devt.in");
ofstream cout("devt.out");
bool v[100001];
int s[100001];
int main()
{
    int n,k,i,a,b,j;
    cin>>n;
    v[0]=1;
    v[1]=1;
    for(i=2;i<=n;i++)
        if(v[i]==0)
        {
            for(j=i+i;j<=n;j=j+i)v[j]=1;
        }
    for(i=1;i<=n;i++)
        s[i]=s[i-1]+v[i];
    cin>>k;
    for(i=1;i<=k;i++)
    {
        cin>>a>>b;
        cout<<s[b]-s[a-1]<<endl;
    }
    return 0;
}
