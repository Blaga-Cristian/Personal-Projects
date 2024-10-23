#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 1e7 + 9;
int t,n,a,b;

vector<int> tree;
void Push(int nod,int st,int dr)
{
    if(st == dr || tree[nod] == 0)
        return;

    tree[nod<<1] = tree[nod<<1|1] = tree[nod];

    tree[nod] = 0;
}
void update(int nod,int st,int dr,int a,int b,int vl)
{
    Push(nod,st,dr);
    if(a <= st && dr <= b)
    {
        tree[nod] = vl;
        return;
    }
    int mij = (st+dr)>>1;
    if(a <= mij)
        update(nod<<1,st,mij,a,b,vl);
    if(b>mij)
        update( nod<<1|1,mij+1,dr,a,b,vl);
}
set<int> se;
void query(int nod = 1,int st = 1,int dr = N)
{
    Push(nod,st,dr);
    if(tree[nod])
    {
        se.insert(tree[nod]);
        return;
    }
    if(st==dr)return;
    int mij = (st+dr)>>1;
    query(nod<<1,st,mij);
    query(nod<<1|1,mij+1,dr);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        se.clear();
        tree = vector<int>(4*N);
        for(int i=1;i<=n;++i)
        {
            cin>>a>>b;
            update(1,1,N,a,b,i);
        }
        query(1,1,N);
        cout<<se.size()<<'\n';
    }
    return 0;
}
