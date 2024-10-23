#include <fstream>
#define dim 70005
using namespace std;
ifstream cin("ijk.in");
ofstream cout("ijk.out");



int tree[5*dim],v[dim],n,ind[dim],b[dim],c[dim];
bool cmp(int a,int b)
{
    return v[a]<v[b];
}
void add(int nod,int st,int dr,int val)
{

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>v[i],
        ind[i] = i;
    sort(ind+1,ind+1+n,cmp);
    b[ind[1]] = 1;
    for(int i=2;i<=n;++i)
        if(v[ind[i]] > v[ind[i-1]])
            v[ind[i]] = v[ind[i-1]] + 1;
        else
            v[ind[i]] = v[ind[i-1]];

    c[ind[n]] = 0;
    for(int i=n-1;i>=1;--i)
        if(v[ind[i]]<v[ind[i+1]])
            c[ind[i]] = n-i;
        else
            c[ind[i]] = c[ind[i+1]];

    int sol = 0;
    add(1,1,n,b[1]);
    for(int i=2;i<n;++i)
    {
        x = numar(1,1,n,b[i]+1);
        sol += x*(c[i]-x);
        add(1,1,n,b[i]);
    }
    return 0;
}
