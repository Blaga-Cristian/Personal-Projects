#include <iostream>

using namespace std;
int v[10],ans[100],n;
void afisare(int len)
{
    for(int i=0;i<len;++i)cout<<ans[i];
    cout<<'\n';
}
void backt(int x)
{
    int ok=0;
    for(int i=1;i<=n;++i)
    {
        if(v[i]>0)
        {
            ok=1;
            v[i]--;
            ans[x]=i;
            backt(x+1);
            v[i]++;
        }
    }
    if(ok==0)afisare(x);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)v[i]=i;
    backt(0);
    return 0;
}
