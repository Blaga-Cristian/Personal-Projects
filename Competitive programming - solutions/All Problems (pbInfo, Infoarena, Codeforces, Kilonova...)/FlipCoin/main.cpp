#include <iostream>

using namespace std;
const int N = 100009;
int n,q,cer,a,b;
struct node
{
    int vl,cnt;
}tree[4*N];
void Push(int nod,int st,int dr)
{
    if(tree[nod].cnt == 0 || st == dr)
        return;
    int mij = (st+dr)>>1;

    tree[nod<<1].vl = (mij - st + 1) - tree[nod<<1].vl;
    tree[nod<<1].cnt = 1;

    tree[nod<<1|1].vl = (dr - mij) - tree[nod<<1|1].vl;
    tree[nod<<1|1].cnt = 1;

    tree[nod].cnt = 0;
}
void update(int nod,int st,int dr,int a,int b)
{
    Push(nod,st,dr);
    if(a<=st&&dr<=b)
    {
        tree[nod].vl = (dr - st + 1) - tree[nod].vl;
        tree[nod].cnt ^= 1;
        return;
    }
    int mij = (st+dr)>>1;
    if(a<=mij)
        update(nod<<1,st,mij,a,b);
    if(b>mij)
        update(nod<<1|1,mij+1,dr,a,b);

    tree[nod].vl = tree[nod<<1].vl + tree[nod<<1|1].vl;
}
int query(int nod,int st,int dr,int a,int b)
{
    Push(nod,st,dr);
    if(a<=st&&dr<=b)
        return tree[nod].vl;
    int mij = (st+dr)>>1;
    if(b<=mij)
        return query(nod<<1,st,mij,a,b);
    else if(a>mij)
        return query(nod<<1|1,mij+1,dr,a,b);
    return query(nod<<1,st,mij,a,b) + query(nod<<1|1,mij+1,dr,a,b);
}

int main()
{
    cin>>n>>q;
    while(q--)
    {
        cin>>cer>>a>>b;
        if(cer==0)
            update(1,0,n-1,a,b);
        else
            cout<<query(1,0,n-1,a,b)<<'\n';
    }
    return 0;
}
