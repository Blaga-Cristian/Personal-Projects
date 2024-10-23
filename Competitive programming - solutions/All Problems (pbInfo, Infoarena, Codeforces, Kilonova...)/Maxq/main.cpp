#include <fstream>

using namespace std;
ifstream cin("maxq.in");
ofstream cout("maxq.out");
const int N = 200009;
int n,m,cer,x,y,i,p,a,b;
struct node
{
    int pre,suf,maxs,full;
}tree[4*N];
node Merge(node a,node b)
{
    node c;
    c.full = a.full + b.full;
    c.pre = max(a.pre,a.full + b.pre);
    c.suf = max(b.suf,a.suf + b.full);
    c.maxs = max(c.pre,max(c.suf,max(a.maxs,max(b.maxs,a.suf + b.pre))));
    return c;
}
void Build(int nod,int st,int dr)
{
    if(st==dr)
    {
        int x;
        cin>>x;
        tree[nod].full = tree[nod].maxs = tree[nod].pre = tree[nod].suf = x;
        return;
    }
    int mij = (st+dr)>>1;
    Build(nod<<1,st,mij);
    Build(nod<<1|1,mij+1,dr);

    tree[nod] = Merge(tree[nod<<1],tree[nod<<1|1]);
}
void update(int nod,int st,int dr,int poz,int val)
{
    if(st==dr)
    {
        tree[nod].full = tree[nod].maxs = tree[nod].pre = tree[nod].suf = val;
        return;
    }
    int mij = (st+dr)>>1;
    if(poz<=mij)
        update(nod<<1,st,mij,poz,val);
    else
        update(nod<<1|1,mij+1,dr,poz,val);

    tree[nod] = Merge(tree[nod<<1],tree[nod<<1|1]);
}
node query(int nod,int st,int dr,int a,int b)
{
    if(a<=st&&dr<=b)
        return tree[nod];
    int mij = (st+dr)>>1;
    if(b<=mij)
        return query(nod<<1,st,mij,a,b);
    else if(a>mij)
        return query(nod<<1|1,mij+1,dr,a,b);
    return Merge(query(nod<<1,st,mij,a,b),query(nod<<1|1,mij+1,dr,a,b));
}
int main()
{
    cin>>n;
    Build(1,0,n-1);
    cin>>m;
    while(m--)
    {
        cin>>cer;
        if(cer==0)
        {
            cin>>i>>p;
            update(1,0,n-1,i,p);
        }
        else
        {
            cin>>a>>b;
            cout<<query(1,0,n-1,a,b).maxs<<'\n';
        }
    }
    return 0;
}
