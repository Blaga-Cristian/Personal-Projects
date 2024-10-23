#include <iostream>

using namespace std;
const int N = 200009;
int n,q;///minim par si maxim impar
struct nod
{
    int par,imp,lazy;
}tree[N];
void Push(int nod,int st,int dr)
{
    if(st==dr || tree[nod].lazy == -1)
        return;
    if(tree[nod].imp!=-1)tree[nod].imp += tree[nod].lazy;
    if(tree[nod].par!=-1)tree[nod].par += tree[nod].lazy;
    if(tree[nod].imp == -1 && tree[nod].par % 2 == 1)
        swap(tree[nod].imp,tree[nod].par);
    else if(tree[nod].par == -1 && tree[nod].imp % 2 == 1)
        swap(tree[nod].imp,tree[nod].par);
    else if(tree[nod].par%2==1)
        swap(tree[nod].imp,tree[nod].par);
    tree[nod<<1].lazy = tree[nod].lazy;
    tree[nod<<1|1].lazy = tree[nod].lazy;
    tree[nod].lazy = -1;
}
void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        int x;
        cin>>x;
        if(x%2==0)
        {
            tree[nod].par = x;
            tree[nod].imp = -1;
        }
        else
        {
            tree[nod].par = -1;
            tree[nod].imp = x;
        }
        tree[nod].lazy = -1;
        return;
    }
    int mij = (st+dr)>>1;
    build(nod<<1,st,mij);
    build(nod<<1|1,mij+1,dr);

    if(tree[nod<<1].par == -1 && tree[nod<<1|1].par == -1)
        tree[nod].par = -1;
    else if(tree[nod<<1].par == -1)
        tree[nod].par = tree[nod<<1|1].par;
    else if(tree[nod<<1|1].par == -1)
        tree[nod].par = tree[nod<<1].par;
    else
        tree[nod].par = min(tree[nod<<1].par,tree[nod<<1|1].par);

    if(tree[nod<<1].imp == -1 && tree[nod<<1|1].imp == -1)
        tree[nod].imp = -1;
    else if(tree[nod<<1].imp == -1)
        tree[nod].imp = tree[nod<<1|1].imp;
    else if(tree[nod<<1|1].imp == -1)
        tree[nod].imp = tree[nod<<1].imp;
    else
        tree[nod].imp = max(tree[nod<<1].imp,tree[nod<<1|1].imp);
}
void update(int nod,int st,int dr,int a,int b,int val)
{
    Push(nod,st,dr);
    if(a<=st&&dr<=b)
    {
        tree[nod].lazy = val;
        return;
    }
    int mij = (st+dr)>>1;
    if(a<=mij)
        update(nod<<1,st,mij,a,b,val);
    if(b>mij)
        update(nod<<1,mij+1,dr,a,b,val);

    if(tree[nod<<1].par == -1 && tree[nod<<1|1].par == -1)
        tree[nod].par = -1;
    else if(tree[nod<<1].par == -1)
        tree[nod].par = tree[nod<<1|1].par;
    else if(tree[nod<<1|1].par == -1)
        tree[nod].par = tree[nod<<1].par;
    else
        tree[nod].par = min(tree[nod<<1].par,tree[nod<<1|1].par);

    if(tree[nod<<1].imp == -1 && tree[nod<<1|1].imp == -1)
        tree[nod].imp = -1;
    else if(tree[nod<<1].imp == -1)
        tree[nod].imp = tree[nod<<1|1].imp;
    else if(tree[nod<<1|1].imp == -1)
        tree[nod].imp = tree[nod<<1].imp;
    else
        tree[nod].imp = max(tree[nod<<1].imp,tree[nod<<1|1].imp);
}
pair<int,int> query(int nod,int st,int dr,int a,int b)
{
    Push(nod,st,dr);
    if(a<=st && dr<=b)
        return {tree[nod].par,tree[nod].imp};
    int mij = (st+dr)>>1;
    pair<int,int> x1 = {-1,-1},x2 = x1;
    if(a<=mij)
        x1 = query(nod<<1,st,mij,a,b);
    if(b>mij)
        x2 = query(nod<<1|1,mij+1,dr,a,b);

    if(x1 == make_pair(-1,-1))
        return x2;
    else if(x2 == make_pair(-1,-1))
        return x1;

    pair<int,int> ans;
    if(x1.first < x2.first && x1.first != -1)
        ans.first = x1.first;
    else
        ans.first = x2.first;
    ans.second = max(x1.second,x2.second);

    return ans;
}
int main()
{
    int cer,a,b,val;
    cin>>n;
    build(1,1,n);
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
            auto x = query(1,1,n,a,b);
            cout<<x.first<<' '<<x.second<<'\n';
        }
    }
    return 0;
}
