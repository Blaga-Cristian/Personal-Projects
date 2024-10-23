#include <fstream>

using namespace std;
ifstream cin("eq.in");
ofstream cout("eq.out");
const int N = 1e5 + 9;
int n,m,i,j;
struct node
{
    int maxi,mini,max_diff,min_diff;
};
node tree[4*N];
node Merge(node a,node b)
{
    node c;
    c.maxi = max(a.maxi,b.maxi);
    c.mini = min(a.mini,b.mini);
    c.max_diff = max(a.max_diff,max(b.max_diff,a.maxi - b.mini));
    c.min_diff = min(a.min_diff,min(b.min_diff,a.mini - b.maxi));
    return c;
}
void build(int nod,int st,int dr)
{
    if(st == dr)
    {
        int x;
        cin>>x;
        tree[nod] = {x,x,0,0};
        return;
    }
    int mij = (st+dr)>>1;
    build(nod<<1,st,mij);
    build(nod<<1|1,mij+1,dr);

    tree[nod] = Merge(tree[nod<<1],tree[nod<<1|1]);
}
node query(int nod,int st,int dr,int a,int b)
{
    if(a <= st && dr <= b)
        return tree[nod];
    int mij = (st+dr)>>1;
    if(b <= mij)
        return query(nod<<1,st,mij,a,b);
    else if(a > mij)
        return query(nod<<1|1,mij+1,dr,a,b);
    return Merge(query(nod<<1,st,mij,a,b),query(nod<<1|1,mij+1,dr,a,b));
}
int main()
{
    cin>>n>>m;
    build(1,1,n);
    while(m--)
    {
        cin>>i>>j;
        node x = query(1,1,n,i,j);
        cout<<x.maxi + x.max_diff + x.mini + x.min_diff<<'\n';
    }
    return 0;
}
