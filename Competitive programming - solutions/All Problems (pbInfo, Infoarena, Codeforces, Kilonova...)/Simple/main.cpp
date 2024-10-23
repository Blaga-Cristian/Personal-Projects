#include <iostream>
#define pll pair<long long,long long>
using namespace std;
const int N = 200009,Inf = 0x3f3f3f3f;
int n,q,cer,a,b,val,x;
struct node
{
    long long mipar, mapar, miimp, maimp,lazy;
    arb()
    {
        mipar = miimp = Inf;
        mapar = maimp = -Inf;
    }

    void operator += (const long long& val)
    {
        if(val & 1)
        {
            swap(mipar,miimp);
            swap(mapar,maimp);
        }

        if(mipar < Inf)mipar += val;
        if(miimp < Inf)miimp += val;
        if(mapar > -Inf)mapar += val;
        if(maimp > -Inf)maimp += val;
    }
}tree[4*N];
node Merge(node a,node b)
{
    node c;
    c.miimp = min(a.miimp,b.miimp);
    c.mipar = min(a.mipar,b.mipar);
    c.maimp = max(a.maimp,b.maimp);
    c.mapar = max(a.mapar,b.mapar);
}
void Build(int nod,int st,int dr)
{
    if(st==dr)
    {
        long long x;
        cin>>x;
        if(x&1)
            tree[nod].maimp = tree[nod].miimp = x;
        else
            tree[nod].mapar = tree[nod].mipar = x;
        return;
    }
    int mij = (st+dr)>>1;
    Build(nod<<1,st,mij);
    Build(nod<<1|1,mij+1,dr);

    tree[nod] = Merge(tree[nod<<1],tree[nod<<1|1]);
}

void Push(int nod,int st,int dr)
{
    if(tree[nod].lazy == 0 || st == dr)
        return;

    tree[nod<<1] += tree[nod].lazy;
    tree[nod<<1].lazy += tree[nod].lazy;

    tree[nod<<1|1] += tree[nod].lazy;
    tree[nod<<1|1].lazy += tree[nod].lazy;

    tree[nod].lazy = 0;
}
void update(int nod,int st,int dr,int a,int b,int val)
{
    Push(nod,st,dr);
    if(a<=st&&dr<=b)
    {
        tree[nod] += val;
        tree[nod].lazy += val;
        return;
    }
    int mij = (st+dr)>>1;
    if(a <= mij)
        update(nod<<1,st,mij,a,b,val);
    if(b>mij)
        update(nod<<1|1,mij+1,dr,a,b,val);

    tree[nod] = Merge(tree[nod<<1],tree[nod<<1|1]);
}
pll query(int nod,int st,int dr,int a,int b)
{
    Push(nod,st,dr);
    if(a<=st&&dr<=b)
        return make_pair(tree[nod].mipar,tree[nod].maimp);
    int mij = (st+dr)>>1;

    pll rez1,rez2;
    rez1.first = rez2.first = Inf;
    rez1.second = rez2.second = -Inf;

    if(a<=mij)
        rez1 = query(nod<<1,st,mij,a,b);
    if(b>mij)
        rez2 = query(nod<<1|1,mij+1,dr,a,b);

    rez1.first = min(rez1.first,rez2.first);
    rez2.second = max(rez1.second,rez2.second);

    return rez1;
}
int main()
{
    cin>>n;
    Build(1,1,n);
    cin>>q;
    while(q--)
    {
        cin>>cer;
        if(cer==0)
        {
            cin>>a>>b>>val;
            update(1,1,n,a,b,val);
        }
        else
        {
            cin>>a>>b;
            auto rez = query(1,1,n,a,b);
            if(rez.first == Inf)cout<<"-1 ";
            else cout<<rez.first<<' ';
            if(rez.second == -Inf)cout<<"-1\n";
            else cout<<rez.second<<'\n';
        }
    }
    return 0;
}
