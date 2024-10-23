#include <iostream>

using namespace std;
const int N = 5000009;
int n,m,tree[4*N],t,x,y;
string s;
void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        tree[nod] = 1<<(s[st-1]-'a');
        return;
    }
    int mij = (st+dr)>>1;
    build(nod<<1,st,mij);
    build(nod<<1|1,mij+1,dr);

    tree[nod] = tree[nod<<1] | tree[nod<<1|1];
}
void update(int nod,int st,int dr,int poz,char x)
{
    if(st==dr)
    {
        tree[nod] = 1<<(x-'a');
        return;
    }
    int mij = (st+dr)>>1;
    if(poz<=mij)
        update(nod<<1,st,mij,poz,x);
    else
        update(nod<<1|1,mij+1,dr,poz,x);

    tree[nod] = tree[nod<<1] | tree[nod<<1|1];
}
int query(int nod,int st,int dr,int a,int b)
{
    if(a<=st&&dr<=b)
        return tree[nod];
    int mij = (st+dr)>>1;
    if(b<mij)
        return query(nod<<1,st,mij,a,b);
    else if(a>=mij)
        return query(nod<<1|1,mij+1,dr,a,b);
    else
        return query(nod<<1,st,mij,a,b)|query(nod<<1|1,mij+1,dr,a,b);
}
int main()
{
    cin>>n;
    cin>>s;
    build(1,1,n);
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>t>>x>>y;
        if(t==0)
        {
            cin>>x>>y;
            cout<<__builtin_popcount(query(1,1,n,x,y))<<'\n';

        }
        else
        {
            cin>>x;
            string s1;
            cin>>s1;
            cout<<s1<<' ';
        }
    }
    return 0;
}
