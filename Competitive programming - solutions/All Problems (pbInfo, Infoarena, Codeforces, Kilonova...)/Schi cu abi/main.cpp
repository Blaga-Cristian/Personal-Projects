#include <fstream>

using namespace std;
ifstream cin("schi.in");
ofstream cout("schi.out");
const int N = 30009;
int n,poz[N],ans[N];
int tree[4*N];
void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        tree[nod] = 1;
        return;
    }
    int mij = (st+dr)>>1;
    build(nod<<1,st,mij);
    build(nod<<1|1,mij+1,dr);

    tree[nod] = tree[nod<<1] + tree[nod<<1|1];
}
void update(int nod,int st,int dr,int poz)
{
    if(st==dr)
    {
        tree[nod] = 0;
        return;
    }
    int mij = (st+dr)>>1;
    if(poz<=mij)
        update(nod<<1,st,mij,poz);
    else
        update(nod<<1|1,mij+1,dr,poz);

    tree[nod] = tree[nod<<1] + tree[nod<<1|1];
}
int query(int nod,int st,int dr,int poz)
{
    if(st==dr)
        return st;
    int mij = (st+dr)>>1;
    if(poz<=tree[nod<<1])
        return query(nod<<1,st,mij,poz);
    else
        return query(nod<<1|1,mij+1,dr,poz-tree[nod<<1]);
}
int main()
{
    cin>>n;
    for(int i=n;i>=1;--i)
        cin>>poz[i];
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        int sol = query(1,1,n,poz[i]);
        ans[sol] = n-i+1;
        update(1,1,n,sol);
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<'\n';
    return 0;
}
