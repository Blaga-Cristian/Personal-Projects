#include <fstream>
#define NMAX 1000005
#define N 100005
using namespace std;
ifstream cin("numbers_tree.in");
ofstream cout("numbers_tree.out");
int n,q;
bool p[NMAX];

struct node
{
    int sum,pref,suf,mx,lazy;
};
node tree[5*N];

node Maxim(node a,node b,int len_a,int len_b)
{
    node ans;
    ans.sum = a.sum + b.sum;
    ans.lazy = -1;
    ans.pref = a.pref;
    if(a.pref == len_a)
        ans.pref = a.pref + b.pref;
    ans.suf = b.suf;
    if(b.suf == len_b)
        ans.suf = a.suf + b.suf;
    ans.mx = max(a.mx,max(b.mx,max(ans.suf,max(ans.pref,a.suf+b.pref))));
    return ans;
}

void propagate(int x,int lx,int rx)
{
    if(lx==rx || tree[x].lazy == -1)
        return ;
    int mid = (lx+rx)>>1;
    int len[] = {mid - lx +1,rx-mid};
    for(int i=0;i<2;++i){
        tree[(2*x)|i].sum = tree[(2*x)|i].suf = tree[(2*x)|i].pref = tree[(2*x)|i].mx = len[i]*tree[(2*x)|i].lazy;
        tree[(2*x)|i].lazy = tree[x].lazy;
    }
    tree[x].lazy = -1;
}

void Update(int nod,int st,int dr,int a,int b,int val)
{
    propagate(nod,st,dr);
    if(a<=st&&dr>=b)
    {
        tree[nod].sum = tree[nod].pref = tree[nod].suf = tree[nod].mx = (st-dr+1)*val;
        tree[nod].lazy = val;
    }
    int mid = (st+dr)>>1;
    if(a<=mid)
        Update(nod<<1,st,mid,a,b,val);
    if(b>mid)
        Update((nod<<1)|1,mid+1,dr,a,b,val);

    tree[nod] = Maxim(tree[nod<<1],tree[(nod<<1)|1],mid-st+1,dr-mid);
}

void build_tree(int x, int lx, int rx) {
        if(lx == rx) {
            int val;
            cin >> val;
            val = p[val] ^ 1;
            tree[x] = node{val, val, val, val, val};
            tree[x].lazy = -1;
            return;
        }
        int mid = (lx + rx) >> 1;
        build_tree(x << 1, lx, mid);
        build_tree((x << 1) | 1, mid + 1, rx);
        tree[x] = Maxim(tree[x << 1], tree[(x << 1) | 1], mid - lx + 1, rx - mid);
}

int Query_sum(int nod,int st,int dr,int qs,int qe)
{
    propagate(nod,st,dr);
    if(qs<=st&&dr<=qe)
    {
        return tree[nod].sum;
    }
    int mid = (st+dr)>>1,ans1=0;
    if(qs<=mid)
        ans1+=Query_sum((nod<<1)|1,st,mid,qs,qe);
    if(qe>mid)
        ans1+=Query_sum((nod<<1)|1,mid+1,dr,qs,qe);
    return ans1;
}

node Query_sequence(int nod,int st,int dr,int a,int b)
{
    propagate(nod,st,dr);
    if(a<=st&&dr<=b)
        return tree[nod];
    int mid = (st+dr)>>1;
    node ans1={0,0,0,0,0},ans2=ans1;
    if(a<=mid)
        ans1 = Query_sequence(nod<<1,st,mid,a,b);
    if(b>mid)
        ans2 = Query_sequence((nod<<1)|1,mid+1,dr,a,b);

    return Maxim(ans1,ans2,mid-st+1,dr-mid);
}

inline void Ciur()
{
    p[0] = p[1] = 1;
    for(int j=2;j*2<=NMAX;++j)p[j] = 1;
    for(int i=3;i*i<=NMAX;i+=2)
    {
        if(p[i]==0)
        {
            for(int j=2;j*i<=NMAX;++j)p[i*j]=1;
        }
    }
}

int main()
{
    Ciur();
    cin>>n>>q;
    build_tree(1,1,n);
    int type,st,dr,val;
    while(q--)
    {
        cin>>type;

    }
    return 0;
}
