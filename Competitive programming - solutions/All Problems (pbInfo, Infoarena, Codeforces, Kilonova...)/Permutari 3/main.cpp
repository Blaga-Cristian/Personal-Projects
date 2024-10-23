#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;
ifstream cin("permutari2.in");
ofstream cout("permutari2.out");
int v[20],n,b[20];
bool p[20];
void scrie()
{
    for(int i=1;i<=n;i++)cout<<v[b[i]]<<" ";
    cout<<endl;
}
void backtr(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(p[i]==0)
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
    for(int i=1;i<=n;i++)cin>>v[i];
    sort(v+1,v+n+1);
    backtr(1);
    return 0;
}
