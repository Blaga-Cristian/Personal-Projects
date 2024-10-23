#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 30009;
int n,m,q,a,b,val;
int tree[4*N];
struct quer
{
    int ord,a,b,val;
    bool operator < (const quer& a)
    {
        return val < a.val;
    }
};
vector<quer> queries;
vector<int> v,ans,p;
bool cmp(int a,int b)
{
    return v[a] < v[b];
}
void Build(int nod,int st,int dr)
{
    if(st==dr)
    {
        tree[nod] = 1;
        return;
    }
    int mij = (st+dr)>>1;
    Build(nod<<1,st,mij);
    Build(nod<<1|1,mij+1,dr);

    tree[nod] = tree[nod<<1] + tree[nod<<1|1];
}
void update(int nod,int st,int dr,int poz,int val)
{
    if(st==dr)
    {
        tree[nod] = val;
        return;
    }
    int mij = (st+dr)>>1;
    if(poz<=mij)
        update(nod<<1,st,mij,poz,val);
    else
        update(nod<<1|1,mij+1,dr,poz,val);

    tree[nod] = tree[nod<<1] + tree[nod<<1|1];
}
int query(int nod,int st,int dr,int a,int b)
{
    if(a <= st && dr <= b)
        return tree[nod];
    int mij = (st+dr)>>1;
    if(b <= mij)
        return query(nod<<1,st,mij,a,b);
    else if (a > mij)
        return query(nod<<1|1,mij+1,dr,a,b);
    return query(nod<<1,st,mij,a,b) + query(nod<<1|1,mij+1,dr,a,b);
}
int main()
{
    cin>>n;
    v = vector<int>(n);
    p = vector<int>(n);
    for(int i=0;i<n;++i)
        cin>>v[i];

    for(int i=0;i<n;++i)
        p[i] = i;
    sort(p.begin(),p.end(),cmp);

    cin>>q;
    ans = vector<int>(q+1);
    for(int i=1;i<=q;++i)
    {
        cin>>a>>b>>val;
        queries.push_back({i,a,b,val});
    }

    sort(queries.begin(),queries.end());

    Build(1,0,n-1);
    int po = 0;
    for(auto i : queries)
    {
        int ord = i.ord,
        a = i.a,
        b = i.b,
        val = i.val;
        while(po < n && v[p[po]] <= val)
            update(1,0,n-1,p[po++],0);
        ans[ord] = query(1,0,n-1,a-1,b-1);
    }

    for(int i=1;i<=q;++i)
        cout<<ans[i]<<'\n';
    return 0;
}
