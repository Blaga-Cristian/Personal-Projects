#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;
int N;
int t,n,b,x,y,l,r;
struct node
{
    int val,lazy;
};
vector<node> tree;
vector<int> li,ri,a;
void Push(int nod,int st,int dr)
{
    if(st == dr || tree[nod].lazy == 0)
        return;

    tree[nod<<1].val = tree[nod].lazy;
    tree[nod<<1].lazy = tree[nod].lazy;

    tree[nod<<1|1].val = tree[nod].lazy;
    tree[nod<<1|1].lazy = tree[nod].lazy;

    tree[nod].lazy = 0;
}
void update(int nod,int st,int dr,int a,int b,int val)
{
    Push(nod,st,dr);
    if(a <= st && dr <= b)
    {
        tree[nod].val = val;
        tree[nod].lazy = val;
        return;
    }
    int mij = (st+dr)>>1;
    if(a <= mij)
        update(nod<<1,st,mij,a,b,val);
    if(b > mij)
        update(nod<<1|1,mij+1,dr,a,b,val);
}
int query(int nod, int st,int dr,int poz)
{
    Push(nod,st,dr);
    if(st == dr)
        return tree[nod].val;
    int mij = (st+dr)>>1;
    if(poz <= mij)
        return query(nod<<1,st,mij,poz);
    return query(nod<<1|1,mij+1,dr,poz);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        li = ri = vector<int>(n+1);
        a.clear();
        for(int i=0;i<n;++i)
        {
            cin>>li[i]>>ri[i];
            a.push_back(li[i]);
            a.push_back(ri[i]);
        }

        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());

        for(int i=0;i<n;++i)
            li[i] = lower_bound(a.begin(),a.end(),li[i]) - a.begin() + 1;

        for(int i=0;i<n;++i)
            ri[i] = lower_bound(a.begin(),a.end(),ri[i]) - a.begin() + 1;

        N = a.size();
        tree = vector<node>(4*N+9);

        for(int i=0;i<n;++i)
            update(1,1,N,li[i],ri[i],i+1);

        set<int>ans;
        for(int i=1;i<=N;++i)
            ans.insert(query(1,1,N,i));
        cout<<ans.size();
    }
    return 0;
}
