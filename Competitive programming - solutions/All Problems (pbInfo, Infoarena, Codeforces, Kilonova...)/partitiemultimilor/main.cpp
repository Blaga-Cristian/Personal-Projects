#include <fstream>

using namespace std;
ifstream cin("pm.in");
ofstream cout("pm.out");
int b[20],n,m;
int maxim(int k)
{
    int z=0;
    for(int i=0;i<k;++i)z=max(b[i],z);
    return z;
}
void afisare()
{
    if(maxim(n+1)==m)
    {
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(b[j]==i)cout<<j;
            }
            cout<<"*";
        }
        cout<<'\n';
    }
}
void back(int x)
{
    if(x==n+1)afisare();
    else for(int i=1;i<=maxim(x)+1;++i)b[x]=i,back(x+1);
}
int main()
{
    cin>>n>>m;
    back(1);
    return 0;
}
