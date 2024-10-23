#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 100009,Vmax = 200009;
int n,q,v[N],poz,val;
struct node
{
    int lazy,val,poz;
};
node tree[4*Vmax];
void build(int nod,int st,int dr)
{
    if(st == dr)
    {
        tree[nod].poz = st;
        return;
    }
    int mij = (st+dr)>>1;
    build(nod<<1,st,mij);
    build(nod<<1|1,mij+1,dr);
}
void Push(int nod,int st,int dr)
{
    if(tree[nod].lazy == 0 || st == dr)
        return;

    tree[nod<<1].val += tree[nod].lazy;
    tree[nod<<1].lazy += tree[nod].lazy;

    tree[nod<<1|1].val += tree[nod].lazy;
    tree[nod<<1|1].lazy += tree[nod].lazy;

    tree[nod].lazy = 0;
}
void update(int nod,int st,int dr,int a,int b,int val)
{
    Push(nod,st,dr);
    if(a <= st && dr <= b)
    {
        tree[nod].val += val;
        tree[nod].lazy += val;
        return;
    }
    int mij = (st+dr)>>1;
    if(a <= mij)
        update(nod<<1,st,mij,a,b,val);
    if(b>mij)
        update(nod<<1|1,mij+1,dr,a,b,val);

    if(tree[nod<<1].val >= tree[nod<<1|1].val)
    {
        tree[nod].val = tree[nod<<1].val;
        tree[nod].poz = tree[nod<<1].poz;
    }
    else
    {
        tree[nod].val = tree[nod<<1|1].val;
        tree[nod].poz = tree[nod<<1|1].poz;
    }
}
int main()
{
    cin>>n;
    build(1,0,Vmax);
    for(int i=1;i<=n;++i)
        cin>>v[i];

     for(int i = 1; i < n; ++i)
    {
        if(i == 1)
            update(1, 1, 200000, min(v[i], v[i+1]), max(v[i], v[i+1]), 1);
        else
            if(v[i] > v[i+1])
                update(1, 1, 200000, v[i+1], v[i] - 1, 1);
            else
                update(1, 1, 200000, v[i] + 1, v[i+1], 1);
    }

    cin>>q;
    while(q--)
    {
        cin>>poz>>val;
        if(poz == 1)
            update(1, 1, 200000, min(v[poz], v[poz+1]), max(v[poz], v[poz+1]), -1);
        else
        {
            if(poz < n)
            {
                update(1, 1, 200000, min(v[poz-1], v[poz]), max(v[poz-1], v[poz]), -1);
                update(1, 1, 200000, min(v[poz+1], v[poz]), max(v[poz+1], v[poz]), -1);
                update(1, 1, 200000, v[poz], v[poz], 1);
            }
            else
                update(1, 1, 200000, min(v[poz-1], v[poz]), max(v[poz-1], v[poz]), -1);
        }
        v[poz] = val;
        if(poz == 1)
            update(1, 1, 200000, min(v[poz], v[poz+1]), max(v[poz], v[poz+1]), 1);
        else
        {
            if(poz < n)
            {
                update(1, 1, 200000, min(v[poz-1], v[poz]), max(v[poz-1], v[poz]), 1);
                update(1, 1, 200000, min(v[poz+1], v[poz]), max(v[poz+1], v[poz]), 1);
                update(1, 1, 200000, v[poz], v[poz], -1);
            }
            else
                update(1, 1, 200000, min(v[poz-1], v[poz]), max(v[poz-1], v[poz]), 1);
        }
        cout<<tree[1].poz+1<<' '<<tree[1].val<<'\n';
    }
    return 0;
}
