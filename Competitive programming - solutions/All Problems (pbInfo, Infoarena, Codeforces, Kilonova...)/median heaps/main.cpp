#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int M = 1e5+9;
int n,a,b,x,y,q,N,block;
vector<int> aux,v;
vector<long long>res;

struct query{int st,dr,ind;};
inline bool cmp(query a, query b){
    if(a.dr / block == b.dr / block){
        if(a.dr / block % 2 == 0)
            return a.st > b.st;
        else return a.st < b.st;
    }

    return a.dr / block > b.dr / block;
}
vector<query>queries;

struct node{int cnt;long long val;};
node tree[4*M];
void update(int nod,int st,int dr,int poz,int sgn,int val)
{
    if(st == dr)
    {
        tree[nod].cnt += sgn;
        tree[nod].val += sgn*val;
        return;
    }
    int mij = (st+dr)>>1;
    if(poz <= mij)
        update(nod<<1,st,mij,poz,sgn,val);
    else
        update(nod<<1|1,mij+1,dr,poz,sgn,val);

    tree[nod].cnt = tree[nod<<1].cnt + tree[nod<<1|1].cnt;
    tree[nod].val = tree[nod<<1].val + tree[nod<<1|1].val;
}
long long query(int nod,int st,int dr,int a,int b)
{
    if(a <= st && dr <= b)
        return tree[nod].val;
    int mij = (st+dr)>>1;
    if(a > mij)
        return query(nod<<1|1,mij+1,dr,a,b);
    else if(b <= mij)
        return query(nod<<1,st,mij,a,b);
    return query(nod<<1,st,mij,a,b) + query(nod<<1|1,mij+1,dr,a,b);
}
int query2(int nod,int st,int dr,int a,int b)
{
    if(a <= st && dr <= b)
        return tree[nod].cnt;
    int mij = (st+dr)>>1;
    if(a > mij)
        return query2(nod<<1,st,mij,a,b);
    else if(b <= mij)
        return query2(nod<<1|1,mij+1,dr,a,b);
    return query2(nod<<1,st,mij,a,b) + query2(nod<<1|1,mij+1,dr,a,b);
}
int get_pz(int nod,int st,int dr,int vl)
{
    if(st == dr)
        return st;
    int mij = (st+dr)>>1;
    if(vl <= tree[nod<<1].cnt)
        return get_pz(nod<<1,st,mij,vl);
    return get_pz(nod<<1|1,mij+1,dr,vl - tree[nod<<1].cnt);
}
void Add(int x){update(1,0,N,v[x],1,aux[v[x]]);}
void Del(int x){update(1,0,N,v[x],-1,aux[v[x]]);}
int get_poz(int x){return get_pz(1,0,N,x);};
int main()
{
    cin>>n;
    block = sqrt(n);

    v = aux = vector<int>(n);
    for(int i=0;i<n;++i)
        cin>>v[i],aux[i] = v[i];
    cin>>q;
    res = vector<long long>(q);
    for(int i=1;i<=q;++i)
    {
        cin>>x>>y;
        queries.push_back({x,y,i});
    }

    sort(aux.begin(),aux.end());
    aux.erase(unique(aux.begin(),aux.end()),aux.end());
    N = aux.size() - 1;///N = indicele cel mai mare
    for(int i = 0; i < v.size(); ++i)
        v[i] = lower_bound(aux.begin(),aux.end(),v[i]) - aux.begin();
    ///v acum contine indicii



    sort(queries.begin(),queries.end(),cmp);

    int st = 0,dr = -1;
    for(auto i : queries)
    {
        int s = i.st-1,d = i.dr-1;
        while(dr < d)Add(++dr);
        while(dr > d)Del(dr--);
        while(st > s)Add(--st);
        while(st < s)Del(st++);

        if(s == d)
        {
            res[i.ind-1] = 0;
            continue;
        }
        int pos = get_pz(1,0,N,(d-s+1)/2);
        int med = aux[pos];
        long long s1 = query(1,0,N,0,pos-1);
        long long s2 = query(1,0,N,pos,N) - med;
        int cnt1 = (d - s + 1)/2 - 1;
        int cnt2 = d - s + 1 - (d - s + 1)/2;

        res[i.ind-1] = 1LL * cnt1 * med - s1 + s2 - 1LL * cnt2 * med;
    }
    for(auto i : res)
        cout<<i<<'\n';
    return 0;
}
