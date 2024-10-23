#include <iostream>
#include <vector>
using namespace std;
int n,m,a,b;
string s;
struct node
{
    int t,o,c;
};
vector<node> tree;
node Merge(node a, node b)
{
    node c;
    int tmp = min(a.o,b.c);
    c.t = a.t + b.t + tmp;
    c.o = a.o + b.o - tmp;
    c.c = a.c + b.c - tmp;
    return c;
}
void Build(int nod,int st,int dr)
{
    if(st==dr)
    {
        char x = s[st-1];
        tree[nod].t = tree[nod].o = tree[nod].c = 0;
        if(x=='(')
            tree[nod].o = 1;
        else
            tree[nod].c = 1;
        return;
    }
    int mij = (st+dr)>>1;
    Build(nod<<1,st,mij);
    Build(nod<<1|1,mij+1,dr);

    tree[nod] = Merge(tree[nod<<1],tree[nod<<1|1]);
}
node query(int nod,int st,int dr,int a,int b)
{
    if(a <= st && dr <= b)
        return tree[nod];
    int mij = (st+dr)>>1;
    if(b<=mij)
        return query(nod<<1,st,mij,a,b);
    else if(a>mij)
        return query(nod<<1|1,mij+1,dr,a,b);
    else return Merge(query(nod<<1,st,mij,a,b),query(nod<<1|1,mij+1,dr,a,b));
}
int main()
{
    cin>>s;
    n = s.size();
    tree = vector<node>(4*n);
    Build(1,1,n);
    cin>>m;
    while(m--)
    {
        cin>>a>>b;
        cout<<(query(1,1,n,a,b).t<<1)<<'\n';
    }
    return 0;
}
