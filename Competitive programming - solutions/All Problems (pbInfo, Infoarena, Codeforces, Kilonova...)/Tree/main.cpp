#include <fstream>
#include <vector>
#define  size (tree[1].cnt)
using namespace std;
ifstream cin("0-lexicografic.in");
ofstream cout("lexicografic.out");
const int N = 250009,Inf = 0x3f3f3f3f;
long long n,k,t;
struct node
{
    long long val,cnt,poz;
};
node tree[4*N];
node Merge(node a, node b)
{
    node c;
    c.cnt = a.cnt + b.cnt;
    if(a.val <= b.val)
    {
        c.val = a.val;
        c.poz = a.poz;
    }
    else
    {
        c.val = b.val;
        c.poz = b.poz;
    }
    return c;
}
void Build(int nod, int st,int dr)
{
    if(st==dr)
    {
        cin>>tree[nod].val;
        tree[nod].cnt = 1;
        tree[nod].poz = st;
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
        tree[nod].val = val;
        tree[nod].cnt = 0;
        return;
    }
    int mij = (st+dr)>>1;
    if(poz<=mij)
        update(nod<<1,st,mij,poz,val);
    else
        update(nod<<1|1,mij+1,dr,poz,val);

    tree[nod] = Merge(tree[nod<<1],tree[nod<<1|1]);
}
node query(int nod,int st,int dr,int cnt)
{
    if(tree[nod].cnt <= cnt)
        return tree[nod];
    int mij = (st + dr)>>1;
    if(cnt <= tree[nod<<1].cnt)
        return query(nod<<1,st,dr,cnt);
    else
        return Merge(query(nod<<1,st,mij,cnt),query(nod<<1|1,mij+1,dr,cnt - tree[nod<<1].cnt));
}
int count(int nod,int st,int dr,int poz)///nr cate nr sunt la stanga poz
{
    if(st==dr)
        return 0;
    int mij = (st+dr)>>1;
    if(poz<=mij)
        return count(nod<<1,st,mij,poz);
    else
        return tree[nod<<1].cnt + count(nod<<1|1,mij+1,dr,poz);
}
void afis(int nod, int st, int dr)
{
    if(st==dr)
    {
        cout<<tree[nod].val<<' ';
        return;
    }
    int mij = (st+dr)>>1;
    if(tree[nod<<1].cnt > 0)
        afis(nod<<1,st,mij);
    if(tree[nod<<1|1].cnt > 0)
        afis(nod<<1|1,mij+1,dr);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        Build(1,1,n);
        vector<int> ans;
        while(size && k>0)
        {
            node x = query(1,1,n,min(size,k+1));
            k -= count(1,1,n,x.poz);
            update(1,1,n,x.poz,Inf);
            ans.push_back(x.val);
        }
        for(auto i : ans)
            cout<<i<<' ';
        afis(1,1,n);
        cout<<'\n';
    }
    return 0;
}
