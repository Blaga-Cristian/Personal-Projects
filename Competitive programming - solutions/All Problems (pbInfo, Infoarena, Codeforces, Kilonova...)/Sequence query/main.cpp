#include <fstream>
#include <limits>
#define ll long long
using namespace std;
ifstream cin("sequencequery.in");
ofstream cout("sequencequery.out");
const int N = 100009;
const long long LLONG_MIN = -9223372036854775807LL;
int n,m,a,b;
struct node
{
    ll stmax = LLONG_MIN>>1,mx = LLONG_MIN>>1,drmax = LLONG_MIN>>1;
    ll fullsum;
}tree[4*N];
node Merge(node a,node b)
{
    node c;
    c.stmax = max(a.stmax, a.fullsum + b.stmax);
    c.mx = max(a.mx,max(b.mx,a.drmax + b.stmax));
    c.drmax = max(b.drmax, a.drmax + b.fullsum);
    c.fullsum = a.fullsum + b.fullsum;
    return c;
}
void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        int x;
        cin>>x;
        tree[nod].drmax = tree[nod].stmax = tree[nod].mx = tree[nod].fullsum = x;
        return;
    }
    int mij = (st+dr)>>1;
    build(nod<<1,st,mij);
    build(nod<<1|1,mij+1,dr);

    tree[nod] = Merge(tree[nod<<1],tree[nod<<1|1]);
}
node query(int nod,int st,int dr,int a,int b)
{
    if(a<=st&&dr<=b)
        return tree[nod];
    int mij = (st+dr)>>1;
    if(a<=mij && b>mij)
        return Merge(query(nod<<1,st,mij,a,b),query(nod<<1|1,mij+1,dr,a,b));
    else if(a>mij)
        return query(nod<<1|1,mij+1,dr,a,b);
    else
        return query(nod<<1,st,mij,a,b);
}
int main()
{
    cin>>n>>m;
    build(1,1,n);
    while(m--)
    {
        cin>>a>>b;
        cout<<query(1,1,n,a,b).mx<<'\n';
    }
    return 0;
}
