#include <iostream>

using namespace std;
int n,v[100],x;
int lb(int x)
{
    int st = 1,dr = n,pz = 0;
    while(st<=dr)
    {
        int mij = (st + dr)>>1;
        if(x > v[mij])
        {
            pz = mij;
            st = mij + 1;
        }
        else
            dr = mij-1;
    }
    return pz;
}
int ub(int x)
{
    int st = 1,dr = n,pz=n+1;
    while(st<=dr)
    {
        int mij = (st + dr) >> 1;
        if(x < v[mij])
        {
            pz = mij;
            dr = mij-1;
        }
        else
            st = mij + 1;
    }
    return pz;
}
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    cout<<lb(x)<<'\n';
    cout<<ub(x);
    return 0;
}
