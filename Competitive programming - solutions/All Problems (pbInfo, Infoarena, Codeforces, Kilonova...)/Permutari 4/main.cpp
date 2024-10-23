#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
ifstream cin("sirpie.in");
ofstream cout("sirpie.out");
int v[20],n,b[20];
bool p[20];
void scrie()
{
    for(int i=1;i<=n;i++)cout<<v[b[i]]<<" ";
    cout<<endl;
}
bool prime(int a,int b)
{
    while(a&&b)
    {
        if(a>b)a=a%b;
        else b=b%a;
    }
    if((a==1&&b==0)||(a==0&&b==1))return true;
    else return false;
}
void backtr(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(p[i]==0&&prime(v[x-1],i))
        {
            p[i]=1;
            b[x]=i;
            if(x<n)backtr(x+1);
            else scrie();
            p[i]=0;
        }
    }
}
int main()
{
    cin>>n;
    v[0]=1;
    for(int i=1;i<=n;i++)cin>>v[i];
    sort(v+1,v+n+1);
    backtr(1);
    return 0;
}
